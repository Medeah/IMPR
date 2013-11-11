/* Self-Check opgave 2 side 204 i Problem Solving and Program Design in C, seventh edition. Se gerne ovennævnte video (tid 3:44) om logiske udtryk med && og || som forberedelse.  */
#include <stdio.h>

int main(void)
{
    int a = 6, b = 9, c = 14, flag = 1;

    c == a + b || !flag;
    a != 7 && flag || /*bliver ikke */c >= 6;
    !(b <= 12) && /*bliver ikke*/a % 2 == 0;
    !(a > 5 || /*bliver ikke*/c < a + b);
    return 0;
}
