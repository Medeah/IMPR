/* Figure 2.16  A Program with a Run-time Error */
#include <stdio.h>
int
main (void)
{
  int first, second;
  double temp, ans;
  
  printf ("Enter two integers> ");
  scanf ("%d%d", &first, &second);
  temp = second / first;
  ans = first / temp;
  printf ("The result is %.3f\n", ans);
  return (0);
}

/*
Enter two integers> 14 3
Arithmetic fault, divide by zero at line 272 of routine main
*/
