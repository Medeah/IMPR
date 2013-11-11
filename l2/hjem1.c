/* Self-Check opgave 1 side 88 i Problem Solving and
   Program Design in C, seventh edition. */
#include <stdio.h>
int
main (void)
{
  int a, b;
  puts ("Enter two integers> ");
  scanf ("%d%d", &a, &b);
  a = b / 2;
  b = 25 - a;
  printf ("a = %d\nb = %d\n", a, b);
  return 0;
}

// in: 10 20 out a = 10\nb = 15
