/* Opgave 3.1 (Inden i eller uden for en cirkel)
 */
#include <stdio.h>

int main(void)
{
    double r, x, y;
    printf("Indtast radius, x og y\n");
    (void)scanf("%lf %lf %lf", &r, &x, &y);
    if (x * x + y * y < r * r) {
        printf("Punktet (%f, %f) er i cirklen med r = %f og centrum i (0, 0)\n",x, y, r);
    } else if (x * x + y * y == r * r)
        printf("Punktet (%f, %f) er på periferien af cirklen med r = %f og centrum i (0, 0)\n",x, y, r);
    else {
        printf("Punktet (%f, %f) er ikke i cirklen med r = %f og centrum i (0, 0)\n", x, y, r);
    }
    return 0;
}
