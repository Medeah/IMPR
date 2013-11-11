/*Opgave 1 side 583 i Problem Solving and Program Design in C, sixth edition. */

#include <stdio.h>
#include <assert.h>

int blob_count(int grid[5][5], int x, int y) {
    int out = 0;
    if (!((grid[x][y] == 0) || (x < 0 || 4 < x || y < 0 || 4 < y))) {
        grid[x][y] = 0;
        out++;
        out += blob_count(grid, x - 1, y - 1);
        out += blob_count(grid, x    , y - 1);
        out += blob_count(grid, x + 1, y - 1);
        out += blob_count(grid, x + 1, y    );
        out += blob_count(grid, x + 1, y + 1);
        out += blob_count(grid, x    , y + 1);
        out += blob_count(grid, x - 1, y + 1);
        out += blob_count(grid, x - 1, y    );
    }
    return out;
}

void test1 (void) {
    int grid[5][5] = {
                     {1, 1, 0, 0, 0},
                     {0, 1, 1, 0, 0},
                     {0, 0, 1, 0, 1},
                     {1, 0, 0, 0, 1},
                     {0, 1, 0, 1, 1},
                    };
    assert(blob_count(grid, 1, 0) == 0);
    assert(blob_count(grid, 3, 3) == 0);
    assert(blob_count(grid, 5, 0) == 0);
    assert(blob_count(grid, -1, 0) == 0);
    assert(blob_count(grid, 0, 5) == 0);
    assert(blob_count(grid, 0, -1) == 0);
    assert(blob_count(grid, 1, 1) == 5);
    assert(blob_count(grid, 1, 1) == 0);
    printf("test1 done\n");
}

void test2 (void) {
    int grid[5][5] = {
                     {1, 1, 0, 0, 0},
                     {0, 1, 1, 0, 0},
                     {0, 0, 1, 0, 1},
                     {1, 0, 0, 0, 1},
                     {0, 1, 0, 1, 1},
                    };
    assert(blob_count(grid, 4, 4) == 4);
    printf("test2 done\n");
}

void test3 (void) {
    int grid[5][5] = {
                     {1, 1, 0, 0, 0},
                     {0, 1, 1, 0, 0},
                     {0, 0, 1, 0, 1},
                     {1, 0, 0, 1, 1},
                     {0, 1, 0, 1, 1},
                    };
    assert(blob_count(grid, 0, 0) == 10);
    printf("test3 done\n");
}

int main(int argc, char const *argv[])
{
    test1();
    test2();
    test3();
    
    return 0;
}
