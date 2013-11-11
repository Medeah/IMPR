#include <stdio.h>

int main(void) {

  int i1, i2,
      scanRes;

  printf("Enter input on the following line\n");

  scanRes = scanf("%d;%d", &i1, &i2);

  printf("i1 = %d, i2 = %d\n", i1, i2);
  printf("scanRes = %d\n", scanRes);

  return 0;
}

/*

123;456 -> virker
123; 456 -> virker
123 ; 456 -> virker ikke, den for kun 123 ind, scanRes = 1
123:456 -> virker ikke, den for kun 123 ind, scanRes = 1
123.456; -> virker ikke, den for kun 123 ind, scanRes = 1
*/