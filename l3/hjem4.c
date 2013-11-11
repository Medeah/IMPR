/* Opgave 6 side 252 i Problem Solving and Program Design in C, seventh edition.
 */

#include <stdio.h>

int main(void)
{
    int x = 0, y = 0;

    (void) scanf(" ( %d , %d)", &x, &y);

    if (x == 0) {
        if (y == 0) {
            printf("(%d, %d) is the origin point\n", x, y);
            return 0;
        }
        printf("(%d, %d) is on the y-axis\n", x, y);
        return 0;
    }

    if (y == 0) {
        printf("(%d, %d) is on the x-axis\n", x, y);
        return 0;
    }

    if (y > 0) {
        if (x > 0) {
            printf("(%d, %d) is in quadrant I\n", x, y);
            return 0;
        }
        printf("(%d, %d) is in quadrant II\n", x, y);
        return 0;
    }

    if (x > 0) {
        printf("(%d, %d) is in quadrant IV\n", x, y);
        return 0;
    }

    printf("(%d, %d) is in quadrant III\n", x, y);
    return 0;
}
