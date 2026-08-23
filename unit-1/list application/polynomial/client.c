#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

int main()
{
	int coeff[] = { 5, 4, 3, 2, 1};
	int expo[] = { 2, 6, 0, 4, 8};
	int n = 5;
	poly_t mypoly1;
	init_poly(&mypoly1);
	for(int i = 0; i < n; ++i)
	{
		insert(&mypoly1, coeff[i], expo[i]);
	}
	printf("Polynomial: \n");
	disp(&mypoly1);

	int x;
	printf("Enter value of x: ");
	scanf("%d",&x);
	float res1 = eval(&mypoly1,x);
	printf("res = %.2f\n",res1);

	poly_t mypoly2;
	init_poly(&mypoly2);
	copy(&mypoly1,&mypoly2);
	printf("Copied polynomial: \n");
	disp(&mypoly2);

	poly_t diff_poly;
	init_poly(&diff_poly);
	differentiate(&mypoly1,&diff_poly);
	printf("Derivative of polynomial: \n");
	disp(&diff_poly);

	poly_t intg_poly;
	init_poly(&intg_poly);
	int u,l;
	printf("Enter the upper and lower bounds for integration : ");
	scanf("%d %d",&u,&l);
	float res2 = definite_integrate(&mypoly2,&intg_poly,u,l);
	printf("Result of definite integration on poly: \n");
	disp(&intg_poly); 
	printf("\nres = %.2f\n",res2);
}