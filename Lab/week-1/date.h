#ifndef DATE_H
#define DATE_H

typedef struct
{
    int date;
    int month;
    int year;
}date;

date date_set(date *d);
void date_display(date d);

#endif