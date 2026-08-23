#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

void differentiate(poly_t *ptr_poly, poly_t* ptr_diff_poly)
{
	copy(ptr_poly,ptr_diff_poly);
	node_t *pres = ptr_diff_poly->head_;
	node_t* prev = NULL;
	while (pres != NULL)
	{
		if(pres->term_.expo_ == 0)
		{
			prev->next_ = NULL;
		}
		else
		{
			pres->term_.coeff_ = pres->term_.expo_ * pres->term_.coeff_;
			pres->term_.expo_ = pres->term_.expo_ - 1;
		}
		prev = pres;
		pres = pres->next_;
	}
}

float definite_integrate(poly_t *ptr_poly, poly_t* ptr_intg_poly, int upper_bound, int lower_bound)
{
	copy(ptr_poly,ptr_intg_poly);
	node_t *pres = ptr_intg_poly->head_;
	while(pres != NULL)
	{
		pres->term_.coeff_ = pres->term_.coeff_ / (pres->term_.expo_ + 1);
		pres->term_.expo_ = pres->term_.expo_ + 1;
		pres = pres->next_;
	}

	float u = eval(ptr_intg_poly,upper_bound);
	float l = eval(ptr_intg_poly,lower_bound);

	return u-l;
}

void copy(poly_t *ptr_poly1, poly_t *ptr_poly2)
{
	node_t *pres1 = ptr_poly1->head_;
	node_t *pres2 = ptr_poly2->head_;

	while (pres1 != NULL)
	{
		node_t *newnode = (node_t*)malloc(sizeof(node_t));
		newnode->next_ = NULL;
		newnode->term_ = pres1->term_;
		if(pres2 == NULL) // handles empty list
		{
			ptr_poly2->head_ = newnode;
		}
		else
		{
			pres2->next_ = newnode;
		}
		pres2 = newnode;
		pres1 = pres1->next_;
	}
}

float eval(poly_t *ptr_poly, int x)
{
	float sum = 0;
	node_t* pres = ptr_poly->head_;
	while(pres != NULL)
	{
		sum = sum + term_value(&pres->term_,x);
		pres = pres->next_;
	}
	return sum;
}

void init_poly(poly_t *ptr_poly)
{
	ptr_poly->head_ = NULL;
}

void disp(poly_t *ptr_poly)
{
	node_t* pres = ptr_poly->head_;
	while(pres != NULL)
	{
		disp_term(&pres->term_);
		pres = pres->next_;
	}
	printf("\n");
}

void insert(poly_t* ptr_poly, int coeff, int expo) 
{
	node_t* temp;
	temp = (node_t*)malloc(sizeof(node_t));
	set_term(&temp->term_, coeff, expo);
	temp->next_ = NULL;
	
	// 1. empty poly 
	if(ptr_poly->head_ == NULL)
	{
		ptr_poly->head_ = temp;
		temp->next_ = NULL;
	}
	else // find the position
	{
		node_t* prev = NULL; 
		node_t* pres = ptr_poly->head_;
		//while(pres != NULL && pres->key_ < temp->key_)
		while(pres != NULL && compare_exponents(&pres->term_, &temp->term_) > 0)
		{
			prev = pres;
			pres = pres->next_;
		}
		// beginning 
		if(prev == NULL)
		{
			ptr_poly->head_ = temp;
			temp->next_ = pres;
		}
		else // middle or end 
		{
			prev->next_ = temp;
			temp->next_ = pres;
		}
	}
	
}











