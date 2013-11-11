/* Programmeringsopgave 2, side 205 i Problem Solving and Program Design in C, seventh edition. Du må ikke bruge if-else kontrolstruturer eller betingede udtryk i løsningen af denne opgave. Variablene leap, ascii og uppercase bør kun optræde én gang i de respektive assignment statements. 
*/
#include <stdio.h>
#include <assert.h>

int main(void)
{
    // a.
    int n = 2012;
    int leap = ((n % 4) == 0);
    assert(leap == 1);

    // b.
    int number = 70;
    int ascii = number > 65 && number < 91;
    assert(ascii == 1);
    
    // c.
    char ch = 'S';
    int uppercase = ch >= 65 && ch <= 90;
    assert(uppercase == 1);

    ch = 's';
    uppercase = ch >= 65 && ch <= 90;
    assert(uppercase == 0);

    return 0;
}
