/* Opgave 5 side 467 i Problem Solving and Program Design in C, seventh edition. 
*/
// Lavet som pair. Original af Rasmus

#include <stdio.h>
#include <assert.h>
#define BARCODE_LENGTH 12

int barcode(const int a[])
{
    int i, sum = 0, final_digit = a[BARCODE_LENGTH - 1], check_digit = 0;

    // Step 1
    for (i = 0; i < BARCODE_LENGTH - 1; i += 2) {
        sum += a[i];
    }
    sum *= 3;

    // Step 2
    for (i = 1; i < BARCODE_LENGTH - 1; i += 2) {
        sum += a[i];
    }

    // Step 3
    check_digit = (10 - (sum % 10)) % 10;

    // Step 4
    return check_digit == final_digit;
}


void get_numbers(int a[])
{
    int i;
    printf("Enter 12 digits of barcode:\n");
    for (i = 0; i < BARCODE_LENGTH; ++i) {
        scanf("%d", &a[i]);
    }
    printf("\n");

    // printf("Enter 12 digits seperated by space\n");
    // scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &a[0], &a[1], &a[2],
    //       &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9], &a[10], &a[11]);

}

void test(void)
{
    int t[BARCODE_LENGTH] = { 0, 7, 9, 4, 0, 0, 8, 0, 4, 5, 0, 1 };
    int u[BARCODE_LENGTH] = { 0, 2, 4, 0, 0, 0, 1, 6, 2, 8, 6, 0 };
    int v[BARCODE_LENGTH] = { 0, 1, 1, 1, 1, 0, 8, 5, 6, 8, 0, 7 };
    int w[BARCODE_LENGTH] = { 0, 5, 1, 0, 0, 0, 1, 3, 8, 1, 0, 1 };
    int x[BARCODE_LENGTH] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    assert(barcode(t));
    assert(!barcode(u));
    assert(barcode(v));
    assert(barcode(w));
    assert(barcode(x));

    printf("All tests passed\n");
}

int main(void)
{
    int a[BARCODE_LENGTH], i;

    test();
    get_numbers(a);

    for (i = 0; i < BARCODE_LENGTH; i++) {
        printf("%d ", a[i]);
    }

    if (barcode(a)) {
        printf("validated\n");
    } else {
        printf("error in barcode\n");
    }
    return 0;
}
