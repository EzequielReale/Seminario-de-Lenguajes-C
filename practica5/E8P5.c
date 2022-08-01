#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    if (argc >= 2)
    {
        FILE *archivo;      
        if ((archivo = fopen(argv[1], "r")))
        {
            char cadena[1024];   
            while (fgets(cadena, sizeof(cadena)-1, archivo))
            {
                for (int i = strlen(cadena)-1; i >= 0; i--) fputc(cadena[i], stdout);
                fputc('\n', stdout);
            }
            fclose(archivo);  
        }
        else fputs("No pudo abrirse el archivo", stderr);
    }
    else
    {
        fputs("No ingreso ningun archivo", stderr);
        return 1;
    }
    return 0;
}