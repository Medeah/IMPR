#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "primes.h"

int main(void) {
    int found = 0, n = 0, i = 1;

    printf("Intast n:\n");
    scanf("%d", &n);
    while(found < n){
        if (is_prime(i)) {
            found++;
            printf("prime %d: %d\n", found, i);
        }
        i++;
    }
    
    return 0;
}