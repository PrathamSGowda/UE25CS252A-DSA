#include <stdio.h>
#include "date.h"

int main()
{
    date d;
    printf("Enter the date, month and year\n");
    date_set(&d);
    printf("The date is : ");
    date_display(d);
}