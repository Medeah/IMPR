/* Programmeringsopgave 1 side 267 (den opgave der beregner 1 + 2 + 3 + ... + (n-1) + n).
 */
#include <stdio.h>

int main(void)
{
    int n, sum = 0, i;
    printf("Indtast n\n");
    (void)scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        sum += i;
    }

    if (sum == (n*(n+1))/2) { // det samme for ale tal?
        printf("%d er det samme\n", sum);
    } else {
        printf("%d er ikke det samme\n", sum);
    }
    return 0;
}
