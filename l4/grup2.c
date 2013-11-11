/* Programmeringsopgave 1 side 281 (Den med de 9870 mennesker...)*/
#include <stdio.h>

int main(void)
{
    int population = 9870, count_years = 0;
    while (population < 30000) {
        population *= 1.1;
        count_years++;
    }

    printf("It will take %d years\n", count_years);
    return 0;
}
