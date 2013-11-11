/* Opgave 2.3 
  Increment og decrement operatorerne */

#include <stdio.h>

int main(void) {
  
  int i = 3, j = 4, k = 5;
  int res1, res2, res3;
  
  i++; j--; ++k; // 4 3 6

  printf("i: %d, j: %d, k: %d\n", i,j,k);

  res1 = --i; // 3
  res2 = j++; // 3
  res3 = --k; // 5

  printf("res1: %d, res2: %d, res3: %d\n", res1, res2, res3);
  printf("i: %d, j: %d, k: %d\n", i,j,k); // 3 4 5
  
  return 0;
}