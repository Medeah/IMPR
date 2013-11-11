#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "ppm.h"

void vandret_linie(ppm* image, int y, pixel p) {
    int i = 0;
    for (; i < image_width(image); ++i) {
        set_pixel(image, i, y, p);
    }
}

void lodret_linie(ppm* image, int x, pixel p) {
    int i = 0;
    for (; i < image_height(image); ++i) {
        set_pixel(image, x, i, p);
    }
}

void vandret_linie_tyk(ppm* image, int y, int tyk, pixel p) {
    int i, j;
    for (j = 0; j < tyk; ++j) {
        for (i = 0; i < image_width(image); ++i) {
            set_pixel(image, i, y + j, p);
        }
    }
}

void lodret_linie_tyk(ppm* image, int x, int tyk, pixel p) {
    int i, j;
    for (j = 0; j < tyk; ++j) {
        for (i = 0; i < image_width(image); ++i) {
            set_pixel(image, x + j, i, p);
        }
    }
}

void vandret_linie_stip(ppm* image, int y, pixel p) {
    int i = 0;
    for (; i < image_width(image); ++i) {
        if ((i / 4) % 2) {
            set_pixel(image, i, y, p);
        }
    }
}

void vilkarlig_linie(ppm* image, int x, int y, int other_x, int other_y, pixel p) {
    assert(x < other_x);
    assert(y < other_y);

    int i, tegn_x, tegn_y;

    int diff_x = other_x - x;
    int diff_y = other_y - y;
    int step = (diff_x > diff_y) ? diff_x : diff_y;

    for (i = 0; i < step; ++i) {
        tegn_y = y + (i * diff_y / step);
        tegn_x = x + (i * diff_x / step);
        printf("(%d, %d)\n", tegn_x, tegn_y);
        set_pixel(image, tegn_x, tegn_y, p);
    }
}

int main(void) {

    ppm *img = make_image(500, 500,  make_pixel(255U, 255U, 255U));  // white

    pixel black_pixel = make_pixel(0U, 0U, 0U);
    pixel red_pixel = make_pixel(255U, 0U, 0U);

    vandret_linie(img, 250, black_pixel);
    vandret_linie(img, 200, red_pixel);
    lodret_linie(img, 200, red_pixel);
    lodret_linie(img, 100, red_pixel);
    vandret_linie_tyk(img, 50, 10, red_pixel);
    lodret_linie_tyk(img, 50, 10, red_pixel);
    vandret_linie_stip(img, 450, black_pixel);

    vilkarlig_linie(img, 50, 50, 300, 300, black_pixel);
    vilkarlig_linie(img, 50, 50, 300, 100, black_pixel);
    vilkarlig_linie(img, 50, 50, 100, 300, black_pixel);


    write_image(img, "img1.pnm");
    return 0;
}
