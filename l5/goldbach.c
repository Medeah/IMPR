#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "primes.h"

int main(void) {
    int i, disproven = 0;

    for (i = 8; i < 2000000; i += 2) {
        if (!goldbach_number(i)) {
            printf("Tallet %d modbeviser det\n", i);
            disproven = 1;
        }
    }

    if (!disproven) {
        printf("kunne ikke finde et tal mellem 7 og 2000000 der mod beviser\n");
    }
    return 0;
}

/// [n] kan skrives som summen af to ulige primtal. 
int goldbach_number(int n) {
    int i;
    for (i = 1; i < n; ++i) {
        if (is_prime(i) && is_prime(n-i)) {
            return 1;
        }
    }
    return 0;
}