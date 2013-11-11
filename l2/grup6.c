/*Opgave 9 side 124.*/

#include <stdio.h>
#define SQFEET_PER_SQYARD 9

int
main (void)
{
    int xyard, yyard, yard_area, xhouse, yhouse, house_area;
    int yard_area_feet, time_req, feet_per_sec = 2;

    puts ("Input house x & y;");
    scanf (" %d %d", &xhouse, &yhouse);

    house_area = xhouse * yhouse;
    //printf("%d\n", house_area);

    puts ("Input yard x & y;");
    scanf (" %d %d", &xyard, &yyard);

    yard_area = xyard * yyard - house_area;
    //printf("%d\n", yard_area);

    yard_area_feet = yard_area * SQFEET_PER_SQYARD;

    //printf("%d\n", yard_area_feet);

    time_req = yard_area_feet / feet_per_sec;

    printf ("Tid det ville tage: %d sec\n", time_req);

    return 0;
}
