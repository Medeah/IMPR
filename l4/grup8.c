/* Self-check opgave 2 side 292. (Kør først programmet efter I har forudset resultatet!!!)*/
#include <stdio.h>

int main(void)
{
    int i, j, k;
    for (i = 0; i < 3; ++i) {
        printf("Outer %4d\n", i);
        for (j = 0; j < 2; ++j) {
            printf("  Inner%3d%3d\n", i, j);
        }
        for (k = 2; k > 0; --k) {
            printf("  Inner%3d%3d\n", i, k);
        }
    }
    return 0;
}
/*
outer 0
  inner 0 0
  inner 0 1
  inner 0 2
  inner 0 1
outer 1...

*/ 