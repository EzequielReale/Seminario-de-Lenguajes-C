#include <stdio.h>

int main()
{
    char *str = "Hello world";
    printf("%.*s\n", 5, str);
    return 0;
}