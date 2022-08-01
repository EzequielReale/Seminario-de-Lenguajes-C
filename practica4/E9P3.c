#include <stdio.h>
#include <stdlib.h>
#define T_INT 1
#define T_FLOAT 2
#define T_STR 3

union t_union{
    int ival;
    float fval;
    char *sval;
};

int main()
{
    printf("Ingresar un numero:");
    int num;
    scanf("%d", &num);
    union t_union n;

    switch (num)
    {
    case T_INT:
        n.ival = num;
        printf("Se ingreso el numero entero: %d\n", n.ival);
        break;
    case T_FLOAT:
        n.fval = num;
        printf("Se ingreso el numero flotante: %f\n", n.fval);        
        break;
    case T_STR:
        getchar();
        n.sval = malloc(sizeof(char) * num + 1);
        fgets(n.sval, num+1, stdin);
        printf("Se ingreso el string: %s\n", n.sval);
        free(n.sval);
        break;
    default:
        printf("El numero ingresado no era ninguno de los valores definidos.\n");
        break;
    }    
    return 0;
}