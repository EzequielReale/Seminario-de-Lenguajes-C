#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    long first, last, increment;
    char *ptr;

    switch (argc)
    {
    case 2:
        first = strtol(argv[1], &ptr, 10);
        for (long i = 1; i <= first; i++)
        {
            printf("%ld\n",i);
        }
        break;
    case 3:
        first = strtol(argv[1], &ptr, 10);
        last = strtol(argv[2], &ptr, 10);
        for (; first <= last; first++)
        {
            printf("%ld\n",first);
        }
        break;
    case 4:
        first = strtol(argv[1], &ptr, 10);
        increment = strtol(argv[2], &ptr, 10);
        last = strtol(argv[3], &ptr, 10);
        for (; first <= last; first = first + increment)
        {
            printf("%ld\n",first);
        }
        break;
    default:
        fputs("Error en la cantidad de operandos\n",stderr);
        return 1;
    }

    return 0;
}