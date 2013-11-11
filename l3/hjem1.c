/* Self-check opgave 5 side 205 i Problem Solving and Program Design in C, seventh edition.
 */
#include <stdio.h>

int
main (void)
{
    int soln, a = 90, b = 35, c = 20;
    //soln = (90 > 35) + (20 < 15); 1?
    soln = (a > b) + (c < 15);
    printf("%d\n", soln);
    return 0;
}