#include <stdio.h>
#define CIR(x,y,a,b,r) ((x-a)*(x-a)+(y-b)*(y-b))<r*r


int main(void) {
    printf("%d\n", CIR(1, 3, 0, 0, 3));

    return 0;
}