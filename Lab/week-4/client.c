#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

int main()
{
	int coeff;
	int expo;
	
	printf("Enter the first polynomial\n");
	int n;
	poly_t mypoly1;
	init_poly(&mypoly1);
	printf("Enter the number of terms : ");
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
	{
		printf("Enter coeff and expo : ");
		scanf("%d %d",&coeff,&expo);
		insert(&mypoly1,coeff,expo);
	}
	
	printf("\nEnter the second polynomial\n");
	int m;
	poly_t mypoly2;
	init_poly(&mypoly2);
	printf("Enter the number of terms : ");
	scanf("%d",&m);
	for(int i = 0; i < m; ++i)
	{
		printf("Enter coeff and expo : ");
		scanf("%d %d",&coeff,&expo);
		insert(&mypoly2,coeff,expo);
	}

	printf("\nPolynomial 1 :");
	disp(&mypoly1);
	printf("\n");

	printf("Polynomial 2 :");
	disp(&mypoly2);
	printf("\n");

	printf("Sum : ");
	poly_t sum;
	init_poly(&sum);
	add_poly(&mypoly1,&mypoly2,&sum);
	disp(&sum);

	poly_t intg;
	init_poly(&intg);
	int u,l;
	float res;
	printf("Enter upper and lower bound : ");
	scanf("%d %d",&u,&l);
	res = definite_integrate(&mypoly1,&intg,u,l);
	printf("Integrated poly : ");
	disp(&intg);
	printf("Result of definite integration : %.2f",res);
}