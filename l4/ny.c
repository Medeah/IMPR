/*Programmeringsopgave 2 side 292. (Dette er også en hjemmeopgave, men hvis I har tid, så lav den gerne i gruppen. Det er den nederste opgave på siden).*/
#include <stdio.h>

int main(void)
{
  int i, j = 0, dif = 1 ;

  for (i = 0; i >= 0; printf("\n"), (dif = i==5 ?-1 :dif), i += dif)
    for (j = 0; j <= i; ++j)
      printf("%d ", j);

  return 0;
}
