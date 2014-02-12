/* Illustrerer FORKERT haandtering af strenge i felter af en struct.
   I tilfælde af at jeg har indlaest data i tekststrenge som skal kopieres */

#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LGT 100
#define NAME_MAX 100
#define TOWN_MAX 50

struct town{
  char name[NAME_MAX];
  char region[NAME_MAX];
  int population;
};
typedef struct town town;
  

void read_towns(char *file_name, town towns[]){
  FILE *ifp;
  char twn[NAME_MAX], reg[NAME_MAX];
  int pop, i = 0;
  town local_town;

  ifp = fopen(file_name, "r");

  while (fscanf(ifp, " BY: %s REG: %s # %d", twn, reg, &pop) == 3){

     local_town.name = twn;         // Et fristende forsoeg...
     local_town.region = reg;       // Men det virker ikke i C.
     local_town.population = pop;   // Compileren opdager det dog.

     towns[i] = local_town;
     
     i++;
  }

  fclose(ifp);  
}

int main(void) {
  town large_danish_towns[TOWN_MAX];
  read_towns("data.txt", large_danish_towns);

  return 0;
}
