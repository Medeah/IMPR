#include <stdio.h>


int main(void) {
    int c[] = {1,2,3,4};
    printf("%d\n", 0[c]);

    return 0;
}


/*
11234567
12312345
12345123
12345671
123456789



1

antal(l) -> l * l * 2 + 2*(l+1) -1

antal(4) -> 4 * 4*2 + 2*5 -1 = 
  line(n) -> 2 * n -1
  mitter(x) -> line(x+1)

  */
