#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double Squareroot(double a, double x1, double e)
{
	if (a < 0 || e <= 0)
		return 0.0 / 0.0;

	if (a == 0)
		return a;

	if (a == 1.0 / 0.0)
		return a;

	if (a != a)
		return 0.0 / 0.0;

	double x0 = a;
	do 
	{
		x0 = x1;
		x1 = 0.5 * (x0 + (a / x0));
	} 
	while (fabs((x1 - x0) / x1) >= e);

	return x1;
}
void main()
{
	double a, x1, e;
	printf("Enter numbers(required number, seed number, accuracy respectively):\n");
	scanf("%lf %lf %lf", &a, &x1, &e);
	if (Squareroot(0.0 / 0.0, 1 , 0.01) != Squareroot(0.0 / 0.0, 1 ,0.01))
		printf("test completed for a = Nan\n");

	if (Squareroot(1.0 / 0.0, 1 ,0.01) == Squareroot(1.0 / 0.0, 1 ,0.01))
		printf("test completed for infinite a\n");

	if (Squareroot(-1, 5 ,0.01) != Squareroot(-1, 5 ,0.01))
		printf("test completed for negative a\n");

	if ((fabs(Squareroot(25, 1 ,0.01) * Squareroot(56, 1 ,0.01) - 25) / 25) < 2 * 0.01)
		printf("test completed for usual a = 25\n");

	if (Squareroot(2.5E-10, 1 ,0.01) == Squareroot(2.5E-10, 1 ,0.01))
		printf("test completed for 0<a<<1\n");

	if ((Squareroot(0, 1 ,0.01) == 0))
		printf("test completed for a = 0\n");

	x1 = Squareroot(a, x1,  e);

	if (x1 != x1)
		printf("error for a = %lf\n", x1);

	else if ((fabs(x1 * x1 - a) / a) > 2 * e)
		printf("error for a = %lf and eps = %lf\n", x1, e);

	else
		printf("Final number : %lf", x1);
}