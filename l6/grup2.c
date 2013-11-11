/*Opgave 6.5 (En simpel lommeregner).*/

/* Programmeringsopgave 1 side 384 i Problem Solving and Program Design in C, seventh edition. Du skal skrive en converter funktion med én input parameter (dollars) og 4 output parametre (hhv. euros, rupees, ruble og yen). Dette er en "opvarmningsopgave". */

#include <stdio.h>
#include <math.h>

void scan_data(char *operator, double *operand) {
    int scan_res = scanf(" %c %lf", operator, operand);
    if (scan_res != 2) {
        printf("FEJL!!!\n");
    }
}

int do_next_op(char operator, double operand, double *akkumulatoren) {
    switch(operator) {
        case '+':
            *akkumulatoren += operand;
            return 0;
        case '-':
            *akkumulatoren -= operand;
            return 0;
        case '*':
            *akkumulatoren *= operand;
            return 0;
        case '/':
            *akkumulatoren /= operand;
            return 0;
        case '^':
            *akkumulatoren = pow(*akkumulatoren, operand);
            return 0;
        default:
            return 1;
    }
}

int main(void) {
    double akkumulatoren = 0, operand = 0;
    char operator;
    printf("En lille lommeregner.\nHer er de gyldige operationer:\n  +  addition\n  -  subtraktion\n  *  multiplikation\n  /  division\n  ^  potensopløftning\n  q  quit\n");

    while(1) {
        scan_data(&operator, &operand);
        if (operator == 'q') {
            break;
        }
        if (do_next_op(operator, operand, &akkumulatoren) != 0) {
            printf("Kan ikke forstå operatoren '%c'\nBrug q til at slutte\n", operator);
            continue;
        } else {
            printf("result so far is  %lf\n", akkumulatoren);
        }
        
    }
    printf("final result is %lf\n", akkumulatoren);

    return 0;
}

