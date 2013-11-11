/*
 * Programmer: Frederik Andersen   Date completed: ???
 * Instructor: Kurt Nørmark        Class: IMPR
 *
 * I denne opgave vil vi generere grafik filer med flotte mønstre.
 * Den kreative udfordringen består i at lave flotte mønstre ved at variere programmerne.
 * Nu mangler vi bare en matematisk definition på "flot".
 */

#include <stdio.h>

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
            r = 0;
            g = y;
            b = x;

            fputc(r, image_file);
            fputc(g, image_file);
            fputc(b, image_file);
        }

    fclose(image_file);
    return 0;
}


int squared_dist(int x, int y, int other_x, int other_y)
{
    return (x - other_x) * (x - other_x) + (y - other_y) * (y - other_y);
}
