/*
 * Programmer: Frederik Andersen   Date completed: Sep 20, 2013
 * Instructor: Kurt Normark        Class: IMPR
 *
 * Afleveringsopgave nummer 2.
 *
 * Indlæser et helt antal sekunder og omregner dette tal til timer, minutter og
 * sekunder på sædvanlig vis.
 */

#include <stdio.h>
#define SEC_PER_HR 3600
#define SEC_PER_MIN 60

int main(void)
{
    int input_sec, sec, min, hr, scanf_res;

    printf("Intast et antal sekunder der skal omregnes:\n");
    scanf_res = scanf(" %d", &input_sec);

    if (scanf_res != 1 || input_sec < 0) {
        fprintf(stderr, "Fejl ved indlæsning.\n");
        fprintf(stderr, "Check at du har indtastet et heltal støre end 0.\n");
        return 1;
    }

    hr = input_sec / SEC_PER_HR;
    min = (input_sec % SEC_PER_HR) / SEC_PER_MIN;
    sec = (input_sec % SEC_PER_HR) % SEC_PER_MIN;

    printf("\n%d sekund", input_sec);
    input_sec != 1 ? printf("er") : 0;
    printf(" svarer til ");

    if (hr > 0) {
        printf("%d time", hr);
        hr > 1 ? putchar('r') : 0;

        if (min > 0 && sec > 0) {
            printf(", ");
        } else if (min > 0 || sec > 0) {
            printf(" og ");
        } else {
            printf("\n");
            return 0;
        }
    }

    if (min > 0) {
        printf("%d minut", min);
        min > 1 ? printf("er") : 0;

        if (sec > 0) {
            printf(" og ");
        } else {
            printf("\n");
            return 0;
        }
    }

    printf("%d sekund", sec);
    sec != 1 ? printf("er") : 0;

    printf("\n");
    return 0;
}