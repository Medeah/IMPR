/*
 * Programmer: Frederik Andersen   Date completed: Nov 5, 2013
 * Instructor: Kurt Normark        Class: IMPR
 *
 * Take a product code from Millie’s Mail-Order Catalog (MMOC) and separate it
 * into its component parts. An MMOC product code begins with one or more
 * letters identifying the warehouse where the product is stored. Next come the
 * one or more digits that are the product ID. The final field of the string
 * starts with a capital letter and represents qualifiers such as size, color,
 * and so on. 
 * 
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// finds index of the first digit
int index_first_num(const char *code)
{
    int i;
    for (i = 0; i < strlen(code); ++i) {
        if (isdigit(code[i])) {
            return i;
        }
    }
    return -1;
}

// finds the index of the first letter after a position
int index_letter_pos(const char *code, int pos)
{
    for (; pos < strlen(code); ++pos) {
        if (isalpha(code[pos])) {
            return pos;
        }
    }
    return -1;
}

// separetes a MMOC product code
void separate_code(const char *code, char *warehouse, char *id,
                   char *qualifiers)
{
    int first_num = index_first_num(code);
    int letter = index_letter_pos(code, first_num);
    strncpy(warehouse, code, first_num);
    strncpy(id, code + first_num, letter - first_num);
    strcpy(qualifiers, code + letter);
}

int main(void)
{
    char product_code[] = "IM1337H4CK3R";
    char ware[0x10] = "", id[0x10] = "", qual[0x10] = "";

    separate_code(product_code, ware, id, qual);
    printf("Warehouse: %s\n", ware);
    printf("Product: %s\n", id);
    printf("Qualifiers: %s\n", qual);
    return 0;
}
