#include <stdio.h>
#include <math.h>

#include "mistakes.h"

double * mistakes(double *array, double *e, double x_0, double dx) {
    double *p = array;
    
    while (fabs(*p - x_0) < dx && p < e) 
    {
        ++p;
    }
    
    return p;
}
