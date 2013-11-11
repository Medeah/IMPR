/*Opgave 10.3 (Flertals navneord).
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>

int ends_in_chr(char c, char *st) {
    int len = strlen(st);

    return st[len - 1] == c;
}

int ends_in_str(char *end, char *st) {
    int len = strlen(st);
    int len_end = strlen(end);
    int begin = len - len_end;
    int i;

    for (i = 0; i < len_end; ++i) {
        if (st[begin + i] != end[i])
        {
            return 0;
        }
    }

    return 1;
}

// jeg har valgt at denne fuction som functionerne i string.h. Dvs den arbejder i det array man giver den. 
void flertal(char *ord) {
    int len = strlen(ord);
    if (ends_in_chr('y', ord)) {
        ord[len-1] = 'i';
        ord[len] = 'e';
        ord[len+1] = 's';
        ord[len+2] = '\0';
    } else if (ends_in_str("ch", ord) || ends_in_str("sh", ord) || ends_in_chr('s', ord)) {
        ord[len] = 'e';
        ord[len + 1] = 's';
        ord[len + 2] = '\0';
    } else {
        ord[len] = 's';
        ord[len + 1] = '\0';
    }
}

int main(void) {
    char ord[9][10] = {"chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish"};
    int i;
    for (i = 0; i < 9; ++i) {
        flertal(ord[i]);
        printf("%s\n", ord[i]);
    }
    return 0;
}
