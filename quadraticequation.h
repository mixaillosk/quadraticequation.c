#ifndef UADR
#define UADR

#include <math.h>

enum errors {
    INCORRECT_COEF = -1,
    INVALID_PTR    = -2,

    NO_ROOTS       =  0,
    ONE_ROOT       =  1,
    TWO_ROOTS      =  2,
    INF_ROOTS      =  3
};

int quadr_eq(double a, double b, double c, double* x1, double* x2);
void print_roots(double* x1, double* x2, int root_amount);
static const int POISON_VALUE = -1 * 0xBADDEAD;

#endif