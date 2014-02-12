// Laeser ny by data ind i array af structs. Udskriver byer
// via print_town i for-loekke i main.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LGT 100
#define NAME_MAX 100
#define TOWN_MAX 50

struct town{
  char name[NAME_MAX];
  char region[NAME_MAX];
  int population;
};
typedef struct town town;
  

int read_towns(char *file_name, town towns[]){
  FILE *ifp;
  char twn[NAME_MAX], reg[NAME_MAX];
  int pop, scanres, i = 0;
  town local_town;

  ifp = fopen(file_name, "r");

  while (fscanf(ifp, " BY : %s REG : %s # %d", twn, reg, &pop) == 3){

     strcpy(local_town.name, twn);  // Vi ser hvordan string kopiering finder sted.
     strcpy(local_town.region, reg);// Tegn fra den lokale variable twn kopiere over i
     local_town.population = pop;   // felterne i local_town.

     towns[i] = local_town;         // local town kopieres over i array af struct town.
     i++;
  }

  fclose(ifp);  
  return i;                            // Returnerer antallet af byer
}

void print_town(town t){
  printf("%s i region %s: %d\n", t.name, t.region, t.population);
}

int main(void) {
  int i, number_of_towns;
  town large_danish_towns[TOWN_MAX];

  number_of_towns = read_towns("data.txt", large_danish_towns);

  for (i = 0; i < number_of_towns; i++)
    print_town(large_danish_towns[i]);

  return 0;
}
