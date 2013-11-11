#include <stdio.h>

int main(void) {

  int i1, i2,
      scanRes;

  printf("Enter input on the following line\n");

  scanRes = scanf("%d abe %d", &i1, &i2);

  printf("i1 = %d, i2 = %d\n", i1, i2);
  printf("scanRes = %d\n", scanRes);

  return 0;
}

/*
123 456 -> får kun et ind
123abe456 - > virker
123 abe 456 -> virker
123 kat 456 -> får et ind
-123abe-456 -> får dem ind negativt
*/