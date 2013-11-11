/*Opgave 11.5 (Rekursive udgaver af Euclids algorime)*/
#include <stdio.h>

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main(void) {
  int i=315, j=120;
 
  //printf("Enter two non-negative integers: ");
  //scanf("%d %d", &i, &j);

  printf("GCD of %d and %d is %d\n\n", i, j, gcd(i, j));
  
  return 0;
}   