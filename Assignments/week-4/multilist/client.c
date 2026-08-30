#include <stdio.h>
#include <string.h>
#include "multilist.h"

int main()
{
    multilist_t myteam;
    init(&myteam);

    char name[MAX];
    int score;
    int opt;

    printf("enter 1 to add data; enter 0 to exit : ");
    scanf("%d", &opt);
    while(opt)
    {
        switch(opt)
        {
            case 1 :    printf("Enter player name : ");    
                        scanf("%s", name);
                        printf("Enter score: ");
                        scanf("%d", &score);
                        add_data(&myteam, name, score);
                        break;
        }
        printf("enter 1 to add data; enter 0 to exit : ");
        scanf("%d", &opt);
    }

    display(&myteam);
}