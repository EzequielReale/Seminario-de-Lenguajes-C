#include <stdio.h>

int esDigito(char x)
{
    return ((x >= '0') & (x <= '9'));
}

int main()
{
    printf("%d", esDigito('8'));
    return 0;
}