/* Programmeringsopgave 1, side 205. Skriv et program med de ønskede udtryk, som erklærer og initialiserer de variable som indgår i opgaven.*/
#include <stdio.h>
#include <assert.h>

int main(void)
{

    int temperature = 12, weight = 70, year = 2012, duration = 42;
    int p = 3, q = 2, r = 1;
    int interest = 10;

    assert(!(temperature > 35));
    assert(weight > 65 && weight < 80);
    assert(year % 4 == 0);
    assert(!(duration < 30));
    assert(p == q || !(p < r));
    assert(interest < 12 && interest > 7);
    return 0;
}
