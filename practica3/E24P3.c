#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void help()
{
    puts("El programa imprime el resultado de enviar una operación y sus "
         "correspondientes parámetros. El resultado será impreso en pantalla.\n\n"
         "Argumentos:\n"
         "\t-s: suma los siguientes 2 parámetros.\n"
         "\t-r: resta los siguientes 2 parámetros.\n"
         "\t-d: divide los siguientes 2 parámetros.\n"
         "\t-m: multiplica los siguientes 2 parámetros.\n"
         "\t-i: imprime todos los parámetros recibidos.\n"
         "\t-h: imprime un texto de ayuda.\n");
}

int main(int argc, char const *argv[])
{
    char imprimo = 0, operacion;
    int i, num1, num2;

    for (i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-h"))
        {
            help();
            return 0;
        }
        else if (!strcmp(argv[i], "-i")) imprimo = 1;
        else if (!strcmp(argv[i], "-s")) operacion = 's';
        else if (!strcmp(argv[i], "-r")) operacion = 'r';
        else if (!strcmp(argv[i], "-d")) operacion = 'd';
        else if (!strcmp(argv[i], "-m")) operacion = 'm';
        else operacion = 0;
        
        if ((operacion != 0) && (strcmp(argv[i], "-i")))
        {
            if (((i + 2) < argc) && (strcmp(argv[i + 1], "-i")) && (strcmp(argv[i + 2], "-i")) && (strcmp(argv[i + 1], "-h")) && (strcmp(argv[i + 2], "-h")))
            {
                num1 = atoi(argv[i + 1]);
                num2 = atoi(argv[i + 2]);
                i += 2;
            }
            else
            {
                fputs("Cantidad de operandos inválida ***(como vos)***, se necesitan 2 \"enteros\".", stderr);
                return 1;
            }
        }    
    }

    if (imprimo)
    {
        puts("Parametros ingresados:");
        for (i = 1; i < argc; i++) if (strcmp(argv[i], "-i")) printf("\t%d --> %s\n", i, argv[i]); 
    }

    switch (operacion)
    {
    case 's':
        printf("El resultado de la suma es %d.\n", (num1 + num2));
        break;
    case 'r':
        printf("El resultado de la resta es %d.\n", (num1 - num2));
        break;
    case 'd':
        printf("El resultado de la division es %d.\n", (num1 / num2));
        break;
    case 'm':
        printf("El resultado de la multiplicacion es %d.\n", (num1 * num2));
        break;
    default:
        printf("No se ingresó un operando valido.\n");
        break;
    }
    return 0;
}