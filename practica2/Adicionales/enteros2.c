#include <stdio.h>

//corregido

int main(int argc, char **argv)
{
    unsigned i;
    for (i = 10; i > 0; i--) //si se pone <= 0 i se quiere volver negativo (-1) pero no puede 
                             //y loopea infinito desde el valor maximo de unsigned
    {
        printf("Valor de i = %u\n", i);
    }
    return 0;
}