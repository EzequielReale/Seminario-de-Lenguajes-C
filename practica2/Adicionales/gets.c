#include <stdio.h>

//corregido

int main()
{
    int x = 1300;
    char buffer[5];
    printf("x = %d\n", x);
    printf("Ingresa por teclado: \"hola\"\n");
    fgets(buffer,5,stdin);
    printf("hola = %s\n", buffer);
    printf("x = %d\n", x);
    return 0;
}