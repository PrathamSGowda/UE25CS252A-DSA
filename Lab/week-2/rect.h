#ifndef RECT_H
#define RECT_H

typedef struct
{
    int length;
    int breadth;
}rect_t;

void set_rect(rect_t* ptr_rect, int length, int breadth);
void disp_rect(rect_t* ptr_rect);
int compare_rect(rect_t* rect1, rect_t* rect2);
int rect_area(rect_t* ptr_rect);

#endif