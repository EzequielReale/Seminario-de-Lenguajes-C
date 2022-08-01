#include <stdio.h>
#include <string.h>
#define BUFFER 1024

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        char *ret, *temp, haystack[BUFFER];
        int ocurrencias = 0, ocurr_linea = 0;

        while (fgets(haystack, BUFFER, stdin))
        {
            temp = haystack;

            while ((ret = strstr(temp, argv[1])))
            {
                ocurrencias++;
                ocurr_linea = 1;
                while (temp < ret)
                {
                    putchar(*temp);
                    temp++;
                }
                putchar('*'); // Simulando el resaltado de grep en Linux
                while ((*ret != ' ') && (*ret != '\0'))
                {
                    putchar(*ret);
                    ret++;
                }
                temp = ret;
            }
            if (ocurr_linea)
            {
                fputs(temp, stdout);
                ocurr_linea = 0;
            }   
        }
        printf("\nCantidad de ocurrencias: %d\n", ocurrencias);
    }
    else
    {
        fputs("Cantidad erronea de argumentos\n", stderr);
        return 1;
    }

    return 0;
}