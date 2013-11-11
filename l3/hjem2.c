/* Self-Check opgaverne 1 og 2 side 242 i Problem Solving and Program Design in C, seventh edition. */
#include <stdio.h>

int
main (void)
{
    char color = 'R';
    switch (color) {
    case 'R':
        printf ("red\n");
    case 'B':
        printf ("blue\n");
    case 'Y':
        printf ("yellow\n");
    }
    return 0;
}
