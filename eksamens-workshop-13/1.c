/* En foerste begyndelse - datastruktuer laves - filen aabnes og lukkes */

#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LGT 100
#define NAME_MAX 100
#define TOWN_MAX 50

// Her laves typen struct town...
struct town{
  char name[NAME_MAX];
  char region[NAME_MAX];
  int population;
};
typedef struct town town;  
  
// Naar denne funktion er faerdig skal den indlaese byerne fra en fil
void read_towns(const char *file_name, town towns[]){
  FILE *ifp;
  ifp = fopen(file_name, "r");

  // LAESNING FRA FILEN KOMMER HER.

  fclose(ifp);  
}

int main(void) {
  town large_danish_towns[TOWN_MAX];     // Her laves et array med byer.
  read_towns("data.txt", large_danish_towns);


  return 0;
}
