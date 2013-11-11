/*Programmeringsopgave 2 side 292. (Dette er også en hjemmeopgave, men hvis I har tid, så lav den gerne i gruppen. Det er den nederste opgave på siden).*/
#include <stdio.h>

int main(void)
{
    int i, j = 0;

    // op
    for (i = 0; i <= 5; ++i) {
        for (j = 0; j <= i; ++j) {
            printf("%d ", j);
        }
        printf("\n");
    }

    // og ned
    for (i = 4; i >= 0; --i) {
        
        for (j = 0; j <= i; ++j) {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}
