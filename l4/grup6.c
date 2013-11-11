#include <stdio.h>

int main(void) {
  int a, b, i, j, remainder, iter = 0;
 
  printf("Enter two non-negative integers: ");
  scanf("%d %d", &a, &b);

  i = a; j = b;  /* We don't know if i > j */  
  while (j > 0){

    printf("Iteration %d: i: %3d, j: %3d\n", ++iter,  i, j);
    remainder = i % j; // første iteration vil bytte om på talne hvis j > i, for så er i%j = i
    i = j;
    j = remainder;
  }

  printf("GCD of %d and %d is %d\n\n", a, b, i);
  
  return 0;
} 