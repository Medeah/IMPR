/* Taeller byerne, og checker at dette virker. */

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

int count_towns (char *file_name){
  FILE *ifp;
  char buf[MAX_LINE_LGT];
  int i = 0;

  ifp = fopen(file_name, "r");

  while (fscanf(ifp, " BY %[^\n]", buf) == 1)
     i++;

  fclose(ifp);  
  return i;
}


void print_town(town t){
  printf("%s i region %s: %d\n", t.name, t.region, t.population);
}

int main(void) {
  int i;
  town large_danish_towns[TOWN_MAX];

  printf("Der er %d byer i filen\n", count_towns("data.txt"));

  // Resten af programmet kommer her 

  return 0;
}
