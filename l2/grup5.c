/*Opgave 2.4 (Indlæsning af doubles).*/
#include <stdio.h>

int main(void) {

  double d, e, f;

  printf("Enter three real numbers: ");
  scanf("%lf %lf %lf", &d, &e, &f);
  //scanf("%f %f %f", &d, &e, &f);

  printf("The average is: %lf\n", (d + e + f) / 3.0);
  //printf("The average is: %d\n", (d + e + f) / 3.0);
    
  return 0;
}