#include <stdio.h>

/* Precondition: n >= 0 */
long fib(int n){
  long result;

  if (n == 0)
    result = 0;
  else if (n == 1)
    result = 1;
  else
    result = fib(n-1) + fib(n-2);

  return result;
}

int main(void) {
  int i = 44;
  printf("Fib(%i) = %li\n", i, fib(i));
  
  return 0;
}