#include <stdio.h>
#include <math.h>
#include "term.h"

float term_value(term_t* ptr_term, int x)
{
	float coeff = ptr_term->coeff_;
	float expo = ptr_term->expo_;

	return coeff * pow(x,expo);
}

void set_term(term_t* ptr_term, int coeff, int expo)
{
	ptr_term->coeff_ = coeff;
	ptr_term->expo_ = expo;
}

void disp_term(term_t* ptr_term)
{
	printf("+ %.2f x^%.2f  ", ptr_term->coeff_, ptr_term->expo_);
}

int compare_exponents(term_t* left, term_t* right)
{
	return left->expo_ - right->expo_;
}