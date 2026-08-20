#include <stdio.h>
#include "rect.h"

int main(void)
{
    rect_t rect1;
    rect_t rect2;
    int l, b;
    int res;

    printf("Enter length and breadth of rectangle 1: ");
    scanf("%d %d", &l, &b);
    set_rect(&rect1, l, b);

    printf("Enter length and breadth of rectangle 2: ");
    scanf("%d %d", &l, &b);
    set_rect(&rect2, l, b);

    printf("Rectangle 1:\n");
    disp_rect(&rect1);

    printf("Area: %d\n", rect_area(&rect1));

    printf("Rectangle 2:\n");
    disp_rect(&rect2);

    printf("Area: %d\n", rect_area(&rect2));

    res = compare_rect(&rect1, &rect2);

    if (res < 0)
        printf("Rectangle 1 has smaller area\n");
    else if (res > 0)
        printf("Rectangle 1 has greater area\n");
    else
        printf("Both rectangles have equal area\n");

    return 0;
}