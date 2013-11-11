/*Opgave 9.1 
En pointer øvelse*/

#include <stdio.h>
#include <assert.h>

int main(void)
{
    int x[8], i;
    for (i = 0; i <= 8; ++i) /* note the <= should be < */
        x[i] = i;

    /* The error is detected by clang than will print a warning:

hjem1.c:13:20: warning: array index 8 is past the end of the array (which
      contains 8 elements) [-Warray-bounds]
    printf("%d\n", x[8]);
                   ^ ~
hjem1.c:9:5: note: array 'x' declared here
    int x[8], i;
    ^
*/

    printf("%d\n", x[8]);
    return 0;
}