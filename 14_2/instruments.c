#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "instruments.h"

double average(double *array, double *e)
{
    double r = 0;
    
    for (double *p = array; p < e; ++p)
        r += *p;
    
    return r / (e - array);
}

double sigma(double *array, double *e, double x_0)
{
    double temp, r = 0;
    
    for (double *p = array; p < e; ++p)
    {
        temp = *p - x_0;
        r += temp * temp;
    }
    
    return sqrt(r / (e - array - 1));
}
