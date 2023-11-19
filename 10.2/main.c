/*
 *name:Type and roots in equation
 *input: Three int numbers(coefficients in equation)
 *output: Type of equation and roots(if they exist)
 *author: Morozov Daniil
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>

typedef enum type
{
    TwoReal,
    OneReal,
    TwoComplex,
    Linear,
    NoRoots,
    ANY,
    InfNaN
}
FunctionType;

/** \brief a function which analyzes a equation with given coefficients a b and c
 *
 * \param a - coefficient before x^2
 * \param b - coefficient before x
 * \param c - free term of the function
 * \param x1 - a pointer to the first root
 * \param x2 - a pointer to the second root
 * \return type of the function with given coefficients a b and c
 *
 */
FunctionType TypeAndRoots(double a, double b, double c, double* x1, double* x2);
FunctionType TypeAndRoots(double a, double b, double c,
    double* x1, double* x2)
{
    if (isnan(a) || isnan(b) || isnan(c) || isinf(a) || isinf(b) || isinf(c))
        return InfNaN;

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                return ANY;
            else
                return NoRoots;
        }
        if (x1 != NULL && x2 != NULL)
            *x1 = *x2 = -c / b;
        return Linear;
    }

    double d = b * b - 4 * a * c;

    if (d < 0)
    {
        if (x1 != NULL && x2 != NULL)
        {
            *x1 = -b / a / 2;
            *x2 = sqrt(-d) / a / 2;
        }
        return TwoComplex;
    }

    if (d == 0)
    {
        if (x1 != NULL && x2 != NULL)
            *x1 = *x2 = -b / 2 / a;
        return OneReal;
    }

    if (x1 != NULL && x2 != NULL)
    {
        *x1 = (-b + sqrt(d)) / 2 / a;
        *x2 = (-b - sqrt(d)) / 2 / a;
    }
    return TwoReal;
}
int main()
{
    double a, b, c;

    printf("Enter the coefficients of the equation:\n");
    scanf("%lf%lf%lf", &a, &b, &c);

    double x1, x2;
    switch(TypeAndRoots(a, b, c, &x1, &x2))
    {
    case TwoReal:
        printf("The function is quadratic and "
               "has two real roots %lf and %lf\n.", x1, x2);
        break;
    case OneReal:
        printf("The function is quadratic and "
               "has one real root %lf\n.", x1);
        break;
    case TwoComplex:
        printf("The function is quadratic and "
               "has two complex roots: %lf + %lf*i and %lf - %lf*i.\n", x1, x2, x1, x2);
        break;
    case Linear:
        printf("The function is linear and "
               "the root is %lf.\n", x1);
        break;
    case NoRoots:
        printf("The function has no roots.\n");\
        break;
    case ANY:
        printf("The function has an infinite number "
               "of roots (any number is a root)\n");
        break;
    case InfNaN:
        printf("One of the function's factors "
               "is either infinity or not a number.\n");
        break;
    }

    return 0;
}
