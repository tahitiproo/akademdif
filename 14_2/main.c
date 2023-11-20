#include <stdio.h>
#include <stdlib.h>

#include "instruments.h"
#include "mistakes.h"

int main() {
    size_t n;
    
    scanf("%lu", &n);
    
    double *array, *e;
    
    array = malloc(n * sizeof(double));
    if (!array) {
        printf("Memory allocation error");
        return 1;
    }
    
    e = array + n;
    
    for (double *p = array; p < e; ++p)
        scanf("%lf", p);
    
    double x_0 = average(array, e), dx = sigma(array, e, x_0);
    
    for (double *p = mistakes(array, e, x_0, dx); p < e; p = mistakes(p + 1, e, x_0, dx)) 
    {
        printf("%.3lf ", *p);
    }
    
    printf("\n");
    dx *= 3;
    
    for (double *p = mistakes(array, e, x_0, dx); p < e; p = mistakes(p + 1, e, x_0, dx)) 
    {
        printf("%.3lf ", *p);
    }
    
    free(array);
    
    return 0;
}
double average(double* array, double* e);

double sigma(double* array, double* e, double x_0);

double average(double* array, double* e) 
{
    double r = 0;

    for (double* p = array; p < e; ++p)
        r += *p;

    return r / (e - array);
}

double sigma(double* array, double* e, double x_0) 
{
    double temp, r = 0;

    for (double* p = array; p < e; ++p) 
    {
        temp = *p - x_0;
        r += temp * temp;
    }

    return sqrt(r / (e - array - 1));
}
double* mistakes(double* array, double* e, double x_0, double dx);

double* mistakes(double* array, double* e, double x_0, double dx) 
{
    double* p = array;

    while (fabs(*p - x_0) < dx && p < e)
    {
        ++p;
    }

    return p;
}
