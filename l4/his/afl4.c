/*
 * Programmer: Frederik Andersen   Date completed: ???
 * Instructor: Kurt Nørmark        Class: IMPR
 *
 * I denne opgave vil vi generere grafik filer med flotte mønstre.
 * Nu mangler vi bare en matematisk definition på "flot".
 *
 * Design heavily inspired by a picture by East718
 * http://commons.wikimedia.org/wiki/File:718smiley.svg
 *
 * CC-BY-SA
 * This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/
 */

#include <stdio.h>
#define _ point_in_circle(x, y,

int point_in_circle(int x, int y, int other_x, int other_y, int r);

int main(void)
{
    FILE *image_file;
    int x, y;
    unsigned char r, g, b;

    image_file = fopen("image-file-1.pnm", "wb");

    fputs("P6\n", image_file);

    fputs("500 500\n", image_file);
    fputs("255\n", image_file);

    for (y = 0; y < 500; y++)
        for (x = 0; x < 500; x++) {

( _ 319, 196, 65) && y < 220) ?((_ 362, 155, 26)) ? (b =g = r = 0) : (b =g = r = 0xFF)):(_ 319, 196, 76) && y < 231)
 ?(b =g = r = 0):(_ 109, 196, 65) && y < 220) ?(_ 137, 155, 26) ? (b =g = r = 0) :(b =g = r = 0xFF)):(_ 109, 196, 76) && y < 231) ?
(b =g = r = 0):(_ 220, 297, 128) && y > 289) ?(_ 276, 448, 82) ? ( (r = 251)+(g = 192)+(b = 223) ) : ( (r = 135)+(g = 25)+(b = 69) )):
(_ 220, 297, 139) && y > 289 - 11) ?
(b =g = r = 0)
: 
(_ 250, 250, 229)) ?
((r = 254)+(g = 222)+(b = 88))
:
(_ 250, 250, 250)) ?
(b =g = r = 0)
: 
((r = 0)+(g = (x*y)/70)+(b = 200));

            fputc(r, image_file);
            fputc(g, image_file);
            fputc(b, image_file);
        }

    fclose(image_file);
    return 0;
}

int point_in_circle(int x, int y, int other_x, int other_y, int r)
{
    return ((x - other_x) * (x - other_x) +
            (y - other_y) * (y - other_y)) < r * r;
}