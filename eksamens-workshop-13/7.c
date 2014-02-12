/* Sorterer byerne primært efter region, sekundært efter population. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LGT 100
#define NAME_MAX 100

struct town{
  char name[NAME_MAX];
  char region[NAME_MAX];
  int population;
};
typedef struct town town;

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

void read_data_1(FILE *ifp, town towns[]){
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

int int_compare(int i1, int i2){
  if (i1 < i2)
    return -1;
  else if (i1 > i2)
    return 1;
  else return 0;
}

int town_compare(const void *ip1, const void *ip2){
  town *t1 = (town *) ip1,
       *t2 = (town *) ip2;

  if (strcmp(t1->region, t2->region) < 0)
    return -1;
  else if (strcmp(t1->region, t2->region) > 0)
    return 1;
  else return -int_compare(t1->population, t2->population);
}

int main(void) {
  int i;
  town *large_danish_towns;  
                             
  int number_of_towns;

  FILE *ifp;
  ifp = fopen("data.txt", "r");

  number_of_towns = count_towns(ifp);

  large_danish_towns = 
    (town *)malloc(number_of_towns * sizeof(town));   

  if (large_danish_towns == NULL){
     printf("Allocation problems. Bye.");
     exit(EXIT_FAILURE);
  }
                                                      
  rewind(ifp); 

  read_data_1(ifp, large_danish_towns);

  qsort(large_danish_towns, number_of_towns,     // Her sorteres byerne
        sizeof(town), town_compare);             // med brug af town_compare.

  for (i = 0; i < number_of_towns; i++) print_town(large_danish_towns[i]);

  fclose(ifp);  
  free(large_danish_towns);

  return 0;
}
