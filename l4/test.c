#include <stdio.h>

int main(void) {
    int a = 2, b = 1, c = 2;

    (a==0) ?
        puts("0")
    :
    (a == 1 ) ?
        puts("1")
    : 
    (a == 2) ?
        puts("2")
    :
        puts("andet");

    return 0;
}