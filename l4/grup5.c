/* Opgave 4.2 (Sum af tal i interval som kan divideres med samme tal). */
#include <stdio.h>

int main(void)
{
    int m, n, k, sum = 0, i;
    printf("Indtast m n k\n");
    (void)scanf("%d %d %d", &m, &n, &k);

    for (i = m; i <= n; ++i) {
        if ((i % k) == 0) {
            sum += i;
        }
    }
        

    printf("%d\n", sum); 
    return 0;
}
