/*
 *name: 11.1
 *input: a number 1,2 or 3(number of program to use) and two int numbers
 *output: in program 1: Sum of digits of a number
          in program 2: Digital root of a number
          in program 3: Greatest common divisor and smallest common multiple
 *author: Morozov Daniil
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int program, a;
    printf("Which program do you want to use?\n"
       "1.Sum of digits of a integer\n"
       "2.Digital root of a number\n"
       "3.Greatest common divisor of two numbers and their smallest common multiple\n");
    scanf("%d",&program);

if (program == 1)
{
    int p;
    printf("Enter an integer number and the base\n");
    scanf("%d%d",&a, &p);
    printf("Sum of digits of %d in base %d is %d\n", a, p, SumOfDigits_Recursive(a,p));
}
if (program == 2)
{   int p;
    printf("Enter an integer an the base\n");
    scanf("%d%d",&a,&p);
    printf("The digital root of %d in base %d is %d\n", a,p, DigitalRoot_Recursive(a,p));
}

if (program == 3)
{   int b;
    printf("Enter two integer numbers\n");
    scanf("%d%d", &a,&b);
    printf("Greatest common divisor of %d and %d is %d and their smallest common multiple is %d\n", a, b, Gcd_Recursive(a,b), Scm_Recursive(a,b));
}

    return 0;
}
int SumOfDigits_Recursive(int a,int p)
{
    if (a > 0) return a%p + SumOfDigits_Recursive(a/p,p);
    else return 0;
}

int DigitalRoot_Recursive(int a,int  p)
{
    int s = 0;
    while (a > 0)
    {
        s += a % p;
        a /= p;
    }

    return s < p ? s : DigitalRoot_Recursive(s, p);
}
int DigitalRoot_Iterative(int a, int p)
{
    int s;
    do
    {
        for (s = 0; a; a /= p)
        s += a % p;
        a = s;
    } while (a > p);
    return s;
}

int SumOfDigits_Iterative(int a, int p)
{
    int s = 0;
    while (a > 0)
    {
        s += a % p;
        a /= p;
    }
    return s;
}
int Gcd_Iterative(int a, int b)
{
    if  (b == 0) return a;
    int s;
    while (b > 0)
    {
        s = b;
        b = a % b;
        a = s;
    }
    return a;
}
int Scm_Iterative(int a,int b)
{   if (Gcd_Iterative(a,b) == 0) return 0;
    return a * b / Gcd_Iterative(a,b);
}


int Gcd_Recursive(int a,int b)
{
    if (b == 0) return a;
    return a % b == 0 ? b : Gcd_Recursive(b, a % b);
}

int Scm_Recursive(int a,int b)
{   if (Gcd_Recursive(a,b) == 0) return 0;
    return a * b / Gcd_Iterative(a,b);
}
/** \brief Function which computes sum of digits of integer
 * \param n is an integer number
 * \return sum of digits of n
 */

int SumOfDigits_Recursive(int a, int p);

/** \brief function which computes a digital root of a number in base p
 *
 * \param a is an integer number
 * \param p is a base
 * \return digital root of a in base p
 *
 */
int DigitalRoot_Recursive(int a, int p);

/** \brief Function which computes a greatest common divisor of two numbers
 *
 * \param a is a first integer number
 * \param b is a second integer number
 * \return greatest common divisor of a and b and their smallest common multiple
 *
 */
int Gcd_Recursive(int a, int b);


/** \brief Function which computes a greatest common divisor of two numbers
 *
 * \param a is a first integer number
 * \param b is a second integer number
 * \return greatest common divisor of a and b
 *
 */

int Gcd_Iterative(int a, int b);

/** \brief Function which computes a smallest common multiple of two numbers
 *
 * \param a is a first number
 * \param b in a second number
 * \return smallest common multiple of a and b
 *
 */

int Scm_Iterative(int a, int b);

/** \brief Function which computes a smallest common multiple of two numbers
 *
 * \param a is a first number
 * \param b in a second number
 * \return smallest common multiple of a and b
 *
 */
int Scm_Recursive(int a, int b);
