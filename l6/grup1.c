/* Programmeringsopgave 1 side 384 i Problem Solving and Program Design in C, seventh edition. Du skal skrive en converter funktion med én input parameter (dollars) og 4 output parametre (hhv. euros, rupees, ruble og yen). Dette er en "opvarmningsopgave". */

#include <stdio.h>
#define USD_IN_EUR 0.731743012;
#define USD_IN_RUP 61.5422488;
#define USD_IN_RUB 31.9172704;
#define USD_IN_YEN 98.1739643;


void convert_currency(double dollar, double *euro, double *rupees, double *ruble, double *yen) {
    *euro = dollar * USD_IN_EUR;
    *rupees = dollar * USD_IN_RUP;
    *ruble = dollar * USD_IN_RUB;
    *yen = dollar * USD_IN_YEN;
}

int main(void) {
    double dollars = 0, euro = 0, rupees = 0, ruble = 0, yen = 0;

    printf("Enter the currency in dollars => ");
    scanf("%lf", &dollars);

    convert_currency(dollars, &euro, &rupees, &ruble, &yen);

    printf("\nDollars   Euros     Rupees    Ruble     Yen\n");
    printf("%-9.2lf %-9.2lf %-9.2lf %-9.2lf %-9.2lf\n", dollars, euro, rupees, ruble, yen);
    return 0;
}

