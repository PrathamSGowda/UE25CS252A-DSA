#ifndef TERM_H
#define TERM_H

struct term
{
	float coeff_;
	float expo_;
};
typedef struct term term_t;

void set_term(term_t* ptr_term, int coeff, int expo_);
void disp_term(term_t* ptr_term);
int compare_exponents(term_t* left, term_t* right);
float term_value(term_t* ptr_term, int x);

#endif