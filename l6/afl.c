/*
 * Programmer: Frederik Andersen   Date completed: Oct 21, 2013
 * Instructor: Kurt Normark        Class: IMPR
 *
 * The program accepts as input a dollar amount divisible by 10. The program
 * will calculate the number of issued 100, 50, 20 and 10 dollar bills equal to
 * the amount. They shall be given as few notes as possible.
 *
 * This uses a recursive function for the solution.
 */
#include <stdio.h>

void number_of_bills(int dollars, int *ten_bills, int *twenty_bills,
                     int *fifty_bills, int *hundred_bills)
{
    if (dollars == 0) {
        return;
    } else if (dollars >= 100) {
        *hundred_bills += 1;
        number_of_bills(dollars - 100, ten_bills, twenty_bills,
                        fifty_bills, hundred_bills);
    } else if (dollars >= 50) {
        *fifty_bills += 1;
        number_of_bills(dollars - 50, ten_bills, twenty_bills,
                        fifty_bills, hundred_bills);
    } else if (dollars >= 20) {
        *twenty_bills += 1;
        number_of_bills(dollars - 20, ten_bills, twenty_bills,
                        fifty_bills, hundred_bills);
    } else {
        *ten_bills += 1;
        number_of_bills(dollars - 10, ten_bills, twenty_bills,
                        fifty_bills, hundred_bills);
    }
}

int main(void)
{
    int dollars = 0, scanf_res = 0;
    int ten_bills = 0, twenty_bills = 0, fifty_bills = 0, hundred_bills = 0;

    printf("Enter a dollar amount to be delivered:\n");
    scanf_res = scanf(" %d", &dollars);

    if (scanf_res != 1 || dollars < 0) {
        fprintf(stderr, "Error reading number.\n");
        fprintf(stderr, "Check that you have entered an integer greater than 0.\n");
        return 1;
    }
    if (dollars % 10 != 0) {
        fprintf(stderr, "Error reading number.\n");
        fprintf(stderr, "Check you have entered the amount divisible with 10.\n");
        return 1;
    }

    number_of_bills(dollars, &ten_bills, &twenty_bills, &fifty_bills, &hundred_bills);

    printf("To be delivered:\n");
    printf("%d ten-dollar bill%c\n", ten_bills, ten_bills != 1 ? 's' : ' ');
    printf("%d twenty-dollar bill%c\n", twenty_bills, twenty_bills != 1 ? 's' : ' ');
    printf("%d fifty-dollar bill%c\n", fifty_bills, fifty_bills != 1 ? 's' : ' ');
    printf("%d hundred-dollar bill%c\n", hundred_bills, hundred_bills != 1 ? 's' : ' ');
    return 0;
}