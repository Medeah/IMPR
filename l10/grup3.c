/*Opgave 10.1 (Funktionen strrev)
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>

void strrev(char *str) {
    int i;
    int k = strlen(str) - 1;
    char temp;
    for(i = 0; i < (strlen(str)/2); i++, k--) {
        temp = str[k];
        str[k] = str[i];
        str[i] = temp;
    }
}


int main(void) {
    char test[] = "test";
    strrev(test);

    printf("%s\n", test );
    return 0;
}
