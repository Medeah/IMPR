#include <stdio.h>

int main(void) {

  double d1, d2;
  int scanRes;

  printf("Enter input on the following line\n");

  scanRes = scanf("%lf %lf", &d1, &d2);

  printf("d1 = %10.5f, d2 = %8.4f\n", d1, d2);
  printf("scanRes = %d\n", scanRes);

  return 0;
}

/*
12.34 56.78 -> virker
12.34   56.78 -> virker
12.34.56.78 -> 12.34 og 0.56
12.34 56 . 78 -> ignorere . 78
12 34 -> kommer ind som floats
012 034 -> virker
12,34-> kun 12 kommer ind
.12e3 .4e-2 -> e notation virker
12a34 -> for kun 12 ind
12-34 -> 12 og -45
12 - 34 -> for kun 12 ind
*/