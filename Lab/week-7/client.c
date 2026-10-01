#include <stdio.h>
#include "webpage.h" 

int main()
{
	dll_t browser;
	init(&browser);
	
    int url;

	int opt;
	printf("enter: 1. openPage; 2. goBack; 0. exit : ");
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : printf("Enter the URL to open: \n");
                     scanf("%d", &url);
                     openPage(&browser, url);
					 break;
					 
			case 2 : goBack(&browser);
					 break;

            case 0 : break;
			
		}
		printf("enter: 1. openPage; 2. goBack; 0. exit : ");
		scanf("%d", &opt);
	}
}