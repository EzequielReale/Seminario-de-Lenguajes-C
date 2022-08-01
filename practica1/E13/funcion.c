#include <stdio.h>

int factorial(int x)
{
    int fact = 1;

    for (x; x > 0; x--)
    {
        fact *= x;
        printf("\n%d", x);
    }
    
    return fact;
}

int factorialRec(int x)
{
    printf("\n%d", x);

    if (x == 1)
    {
        return 1;
    }

    return x * factorialRec(x - 1);
}

int main()
{
    printf("\nFactorial: %d", factorialRec(5));
    return 0;
}