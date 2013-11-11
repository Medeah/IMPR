/*Opgave 9.1 
En pointer øvelse*/

#include <stdio.h>
#include <assert.h>

int main(void)
{
    int    i = 3, j = 5, *p = &i, *q = &j, *r;
    double x;

    printf("%d\n", p == &i); // true (1)

    p = i + 7; // type warning
    printf("%d\n", p); // 10

    //printf("%d\n", * (* (& p))); // Segmentation fault

    r = & x; // type warning
    printf("%x\n", r); // some random pointer

    // printf("%d\n", 7 * * p / * q + 7); // Segmentation fault

    //* (r = & j) *= * p; // Segmentation fault

    return 0;
}
