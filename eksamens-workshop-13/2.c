/* Laeser data om alle byer - skriver det ud for at checke indlaesningen
   Laegger det ikke på plads i struct town endnu. */

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
  

void read_towns(const char *file_name, town towns[]){
  FILE *ifp;
  char twn[NAME_MAX], reg[NAME_MAX];
  int pop;

  ifp = fopen(file_name, "r");

  while (fscanf(ifp, " BY: %s REG: %s # %d", twn, reg, &pop) == 3){
     printf("BY: %s, REG: %s, POP: %d\n", twn, reg, pop); 
  }

  fclose(ifp);  
}

int main(void) {
  town large_danish_towns[TOWN_MAX];
  read_towns("data.txt", large_danish_towns);

  return 0;
}
