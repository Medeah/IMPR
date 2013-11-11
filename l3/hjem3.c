/*
 * Programmerings-opgaverne 1 og 2 side 242-243 i Problem Solving and
 * Program Design in C, seventh edition.
 */

#include <stdio.h>

int main(void)
{
    int watts = 0, lumens = -1;
    printf("Enter watts: ");
    scanf("%d", &watts);
    switch (watts) {
    case 15:
        lumens = 125;
        break;
    case 25:
        lumens = 215;
        break;
    case 40:
        lumens = 500;
        break;
    case 60:
        lumens = 880;
        break;
    case 75:
        lumens = 1000;
        break;
    case 100:
        lumens = 1675;
        break;
    default:
        lumens = -1;
    }

    printf("Lumens: %d\n", lumens);
    return 0;
}
