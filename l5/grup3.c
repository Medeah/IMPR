#include <stdio.h>

int isLeapYear(int year);
int leap_year(int year);

int main(void) {
    int i;
    for (i = 1900; i <= 2100; ++i) {
        if (isLeapYeart(i)) {
            printf("%d er skudår\n", i);
        } else {
            printf("%d er ikke skudår\n", i);
        }
    }
    return 0;
}

int isLeapYear(int year){
  int res;
  if (year % 400 == 0)
    res = 1;
  else if (year % 100 == 0)
    res = 0;
  else if (year % 4 == 0)
    res = 1;
  else res = 0;
  return res;
}

/// Ny skudårsfunktion med brug af && og ||
/// Uden brug af if-else og uden brug af betingede udtryk.
/// Finden ud af om [year] er skudår
int isLeapYeart(int year) {
    return (year % 400 == 0) || ((year % 4 == 0) && !(year % 100 == 0));
}