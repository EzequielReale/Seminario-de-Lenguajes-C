#include <stdio.h>

int mayor(int x, int y)
{
    return ((x > y) ? x : y);
}

int main()
{
    printf("Mayor: %d", mayor(4 , 2));
    return 0;
}