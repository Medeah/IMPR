/* Allokerer byerne dynamisk. 
   Funktionerne tager nu også en FILE pointer i stedet for
   et filnavn som parameter. */

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

int main(void) {
  int i;
  town *large_danish_towns;  // Denne variabel er nu en pointer til en town.
                             // Lageret til denne by laves i kaldet af malloc herunder.
  int number_of_towns;

  FILE *ifp;
  ifp = fopen("data.txt", "r");

  number_of_towns = count_towns(ifp);

  large_danish_towns = 
    (town *)malloc(number_of_towns * sizeof(town));   // Her allokores praecist den
                                                      // maengde lager der er behov for.
  if (large_danish_towns == NULL){
     printf("Allocation problems. Bye.");
     exit(EXIT_FAILURE);
  }

  rewind(ifp); 

  read_towns(ifp, large_danish_towns);

  for (i = 0; i < number_of_towns; i++)
    print_town(large_danish_towns[i]);

  fclose(ifp);  
  free(large_danish_towns);

  return 0;
}
