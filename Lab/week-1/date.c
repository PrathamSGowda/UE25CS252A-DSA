#include <stdio.h>
#include "date.h"

date date_set(date *d)
{
    scanf("%d %d %d", &d->date, &d->month, &d->year);
}

void date_display(date d)
{
    printf("%d-%d-%d", d.date, d.month, d.year);
}