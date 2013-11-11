/*Opgave 10.4 (Længste fælles endelse af to ord).
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>

void reverse(char *str) {
    int i;
    int k = strlen(str) - 1;
    char temp;
    for(i = 0; i < (strlen(str)/2); i++) {
        temp = str[k];
        str[k] = str[i];
        str[i] = temp;
        k--;
    }
}

void endelse(const char *ord1, const char *ord2, char *output) {
    int i;
    int out_counter = 0;

    for (i = 1; i <= strlen(ord1); ++i) {
        if (ord1[strlen(ord1) - i] == ord2[strlen(ord2) - i]) {

            output[out_counter++] = ord1[strlen(ord1) - i];

        } else {
            break;
        }
    }
    output[out_counter++] = '\0';
    reverse(output);
}

void test1(void) {
    char ord1[] = "datalogi";
    char ord2[] = "biologi";
    char out[10];
    endelse(ord1, ord2, out);
    printf("%s\n", out);
}
void test2(void) {
    char ord1[] = "program";
    char ord2[] = "diagram";
    char out[10];
    endelse(ord1, ord2, out);
    printf("%s\n", out);
}
void test3(void) {
    char ord1[] = "defsgram";
    char ord2[] = "gram";
    char out[10];
    endelse(ord1, ord2, out);
    printf("%s\n", out);
}


int main(void) {
    test1();
    test2();
    test3();
    return 0;
}
