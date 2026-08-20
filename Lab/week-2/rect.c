#include <stdio.h>
#include "rect.h"


int rect_area(rect_t* ptr_rect)
{
	int length = ptr_rect->length;
	int breadth = ptr_rect->breadth;

	return length*breadth;
}

void set_rect(rect_t* ptr_rect, int length, int breadth)
{
	ptr_rect->length = length;
	ptr_rect->breadth = breadth;
}

void disp_rect(rect_t* ptr_rect)
{
	printf("length : %d, breadth : %d\n", ptr_rect->length, ptr_rect->breadth);
}

int compare_rect(rect_t* rect1, rect_t* rect2)
{
    if(rect_area(rect1) < rect_area(rect2))
        return -1;
    else
        return 1;
}
