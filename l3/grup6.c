/* Self-check opgave 3 side 236 i lærebogen Problem Solving and Program Design in C, seventh edition.
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define DBL_EPSILON 2.2204460492503131e-16

int main(void)
{
    double ph;
    printf("Indtast pH værdi\n");
    (void) scanf("%lf", &ph);
    if (ph <= 2)
        printf("Very acidic");  
    else if (ph < 7) 
        printf("Acidic");       
    else if (ph == 7)
        printf("Neutral");      
    else if (ph < 12)
        printf("Alkaline");     
    else 
        printf("Very alkaline");
    return 0;
}
