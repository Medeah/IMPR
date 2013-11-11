/* Opgave 1.4 (Programmeringsstil)
   En pænere version af uheldig.c
   Det viser sig at det udregner gennemsnit
*/


#include <stdio.h>

int
main (void)
{
  float first_number, second_number, third_number;

  printf ("Give me three: ");
  scanf ("%f %f %f", &first_number, &second_number, &third_number);
  printf ("Theresult: %f\n", (first_number + second_number + third_number) / 3.0);
  return 0;
}
