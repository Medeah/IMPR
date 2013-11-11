#include <stdio.h>

int main(void) {

  int i1, i2,
      scanRes;

  printf("Enter input on the following line\n");

  scanRes = scanf("%d%d", &i1, &i2);

  printf("i1 = %d, i2 = %d\n", i1, i2);
  printf("scanRes = %d\n", scanRes);

  return 0;
}
/*
123 456 -> de to tal bliver indlæst som forvented
123    456 -> som forvented, den ignoree space
123.456 -> den for kun læst 123.456 som bliver casted til 123. scanRes giver 1
123-456 -> 123 og -456
123_456 -> kan kun læse et tal ind, scanRes giver 1 
123 -> den hænger igen

*/