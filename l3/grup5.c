/* Self-check opgave 3 side 236 i lærebogen Problem Solving and Program Design in C, seventh edition.
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define DBL_EPSILON 2.2204460492503131e-16

int main(void)
{
    double pH;
    printf("Indtast pH værdi\n");
    (void) scanf("%lf", &pH);
    printf("%lf\n", fabs(pH - 7));
    if (pH > 7) {
        if (pH < 12) {
            printf("Alkaline\n");
        } else {
            printf("Very alkaline\n");
        }

/*Two real (float, double, or long double) values are compared directly using
  == or != primitive. This may produce unexpected results since floating point
  representations are inexact. Instead, compare the difference to FLT_EPSILON
  or DBL_EPSILON. (Use -realcompare to inhibit warning)*/
    } else if (fabs(pH - 7) < DBL_EPSILON) {
        printf("Neutral\n");
    } else if (pH > 2) {
        printf("Acidic\n");
    } else {
        printf("Very acidic\n");
    }
    return 0;
}
