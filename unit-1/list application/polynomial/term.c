#include <stdio.h>
#include <math.h>
#include "term.h"

int term_value(term_t* ptr_term, int x)
{
	int coeff = ptr_term->coeff_;
	int expo = ptr_term->expo_;

	return coeff * pow(x,expo);
}

void set_term(term_t* ptr_term, int coeff, int expo)
{
	ptr_term->coeff_ = coeff;
	ptr_term->expo_ = expo;
}

void disp_term(term_t* ptr_term)
{
	printf("+ %d x^%d  ", ptr_term->coeff_, ptr_term->expo_);
}

int compare_exponents(term_t* left, term_t* right)
{
	return left->expo_ - right->expo_;
}