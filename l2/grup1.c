/* Opgave 11 side 125 i Problem Solving and
   Program Design in C, seventh edition. */
#include <stdio.h>
int
main (void)
{
  int m, n, side1, side2, hypotenuse;
  printf ("Input two integers, and I will give you a pythagoream triple: \n");
  scanf ("%d %d", &m, &n);

  if (!(m > n))
    {
      puts ("first must be higer than last");
      return 1;
    }

  side1 = m * m - n * n;
  side2 = 2 * m * n;
  hypotenuse = m * m + n * n;

  printf ("Side: %d, side: %d and hypotenuse: %d \n", side1, side2,
	  hypotenuse);
  return 0;
}
