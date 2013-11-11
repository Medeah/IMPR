/*Opgave 11.1 (En Fibonacci funktion med huskeværk)*/
#include <stdio.h>


long fib(int n){
  long result;
  static long int test[81] = { 0 };
 
  if (test[n] != 0)
    return test[n];

  if (n == 0)
    result = 0;
  else if (n == 1)
    result = 1;
  else
    result = fib(n-1) + fib(n-2);

  test[n] = result;
  return result;
}

int main(void) {
  long i;

  for(i = 0; i <= 80; i++){
    printf("Fib(%li) = %li\n", i, fib(i) );
  }
   
  return 0;
}