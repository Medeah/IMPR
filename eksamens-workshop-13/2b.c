/* Laeser data om alle byer - Placerer byer i towns array 
  Skriver byer  ud med print_town at checke indlaesningen */

#include <stdio.h>
#include <stdlib.h>
#define NAME_MAX 100
#define TOWN_MAX 50

struct town{
  char name[NAME_MAX];
  char region[NAME_MAX];
  int population;
};
typedef struct town town;
  

int read_towns(const char *file_name, town towns[]){
  FILE *ifp;
  char twn[NAME_MAX], reg[NAME_MAX];
  int pop, towns_nr = 0;
  town local_town;

  ifp = fopen(file_name, "r");

  while (fscanf(ifp, " BY: %s REG: %s # %d", local_town.name, local_town.region, &local_town.population) == 3){
    towns[towns_nr] = local_town;
    towns_nr++;
  }

  fclose(ifp);  
  return towns_nr;
}

void print_town(town twn){
  printf("BY: %s, REG: %s, POP: %d\n", twn.name, twn.region, twn.population); 
}

int main(void) {
  int number_of_towns, t;
  town large_danish_towns[TOWN_MAX];
  number_of_towns = read_towns("data.txt", large_danish_towns);

  for (t = 0; t < number_of_towns; t++)
    print_town(large_danish_towns[t]);

  return 0;
}
