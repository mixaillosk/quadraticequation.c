#include <stdio.h>
#include <math.h>
#include<assert.h>
#include<errno.h>

#include "quadraticequation.h"

int quadr_eq(double a, double b, double c, double* x1, double* x2)
{
    if (isnan(a) || isnan(b) || isnan(c))
    {
        errno = INCORRECT_COEF;
        return INCORRECT_COEF;
    }

    else if (x1 == NULL || x2 == NULL)
    {
        errno = INVALID_PTR;
        return INVALID_PTR;
    }

    double D = b * b - 4 * a * c;

    if (a == 0 && b == 0 && c == 0)
    {
        return INF_ROOTS;
    }

    else if (a == 0)
    {
        *x1 = -c / b;
        return ONE_ROOT;
    }

    else if (D > 0)
    {
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);
        return TWO_ROOTS;
    }
    else if (D == 0)
    {
        *x1 = -b / (2 * a);
        return ONE_ROOT;
    }

    return NO_ROOTS;
}

int solve_linear_equation(double b, double c, double* x1)
{
   if (isnan(b) || isnan(c))
    {
        errno = INCORRECT_COEF;
        return INCORRECT_COEF;
    }

    else if (x1 == NULL)
    {
        errno = INVALID_PTR;
        return INVALID_PTR;
    }

    
}

void print_roots(double* x1, double* x2, int root_amount)
{
    if      (root_amount == 0)
    {
        printf("No roots.");
    }
    else if (root_amount == 1)
    {
        printf("There is one root = %lf.", *x1);
    }
    else if (root_amount == 2)
    {
        printf("There are two roots:\nx1 = %lf.\nx2 = %lf.", *x1, *x2);
    }
    else if (root_amount == 3)
    {
        printf("There are infinite number of roots.");
    }
}
