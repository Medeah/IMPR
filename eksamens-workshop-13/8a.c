/* Vi finder regionerne fra et gennemløb af byerne i initialize_regions.
   I stedet for at have et array ar regionsnavne.
   Udskriver regionerne */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LGT 100
#define NAME_MAX 100
#define NUMBER_OF_REGIONS 5

struct town{
  char name[NAME_MAX];
  char region[NAME_MAX];
  int population;
};
typedef struct town town;

// Ny region struct:
struct region{
  char name[NAME_MAX];
  int number_of_large_towns;
  int population;
};
typedef struct region region;
  

int count_towns (FILE *ifp){
  char buf[MAX_LINE_LGT];
  int scanres, i = 0;

  scanres = fscanf(ifp, " BY %[^\n]", buf); 
  while (scanres == 1){
     i++;
     scanres = fscanf(ifp, " BY %[^\n]", buf); 
  }

  return i;
}

void read_towns(FILE *ifp, town towns[]){
  char twn[NAME_MAX], reg[NAME_MAX];
  int pop, i = 0;
  town local_town;

  while (fscanf(ifp, " BY : %s REG : %s # %d", twn, reg, &pop) == 3){
     strcpy(local_town.name, twn);
     strcpy(local_town.region, reg);
     local_town.population = pop;
     towns[i] = local_town;

     i++;
  }
}

void print_town(town t){
  printf("%s i region %s: %d\n", t.name, t.region, t.population);
}

// Ensure that region of twn is represented in region.
// Return is the region of twn is new in regions
int ensure_region_from_town(const town twn, region regions[], int next_reg){
   int r;
   for (r = 0; r < next_reg; r++)
     if (strcmp(twn.region, regions[r].name) == 0)   // Is the region of twn already in regions?
       return 0;  // Signals that no new region has been inserted.

   // The region of town is not in regions. Insert it:
   strcpy(regions[next_reg].name, twn.region);
   regions[next_reg].number_of_large_towns = 0;
   regions[next_reg].population = 0;

   return 1; // signals that a new region has been entered.
}

void initialize_regions(town towns[], int number_of_towns, region regions[]){
  int j, next_region = 0, new_reg;

  for(j = 0; j < number_of_towns; j++){
     new_reg = ensure_region_from_town(towns[j], regions, next_region);
     if (new_reg) next_region++;
  }
}

int find_region_index(char *reg_name,  region regions[]){
  int i;
  for (i = 0; i < NUMBER_OF_REGIONS; i++){
    if (strcmp(reg_name, regions[i].name) == 0)
      return i;
  }
  return -1;
}

// Overfører data fra towns til regions - taeller byer i en given region.
// Udregner det samlede befolkningstal i store byer i regionerne.
void enter_data_in_regions(town towns[], int number_of_towns, 
                           region regions[]){
  int i, reg_idx;

  for(i = 0; i < number_of_towns; i++){
    reg_idx = find_region_index(towns[i].region, regions);
    if (reg_idx != -1){
      (regions[reg_idx].number_of_large_towns)++;
      regions[reg_idx].population += towns[i].population;
    }
  }
}

void print_region(region regions[], int r){
  printf("Region %s: %d store byer med ialt %d indbyggere.\n",
         regions[r].name, regions[r].number_of_large_towns, regions[r].population);
}


int main(void) {
  int i;
  town *large_danish_towns;
  region regions[NUMBER_OF_REGIONS];     // Her laves et array af regioner
  int number_of_towns;

  FILE *ifp;
  ifp = fopen("data.txt", "r");

  number_of_towns = count_towns(ifp);

  large_danish_towns = (town *)malloc(number_of_towns * sizeof(town));
  if (large_danish_towns == NULL){
     printf("Allocation problems. Bye.");
     exit(EXIT_FAILURE);
  }

  rewind(ifp); 

  read_towns(ifp, large_danish_towns);
  initialize_regions(large_danish_towns, number_of_towns, regions);     // Indsaetter navnene paa regioner i array af regioner.
  enter_data_in_regions(large_danish_towns, number_of_towns, regions);  // Indsaetter resten af data om regionerne.

  for (i = 0; i < 5; i++)
    print_region(regions, i);

  fclose(ifp);  
  free(large_danish_towns);

  return 0;
}
