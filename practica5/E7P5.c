#include <stdio.h>

int main(int argc, const char *argv[])
{
    if (argc >= 2)
    {
        FILE *archivo;      
        if ((archivo = fopen(argv[1], "r")))
        {
            char cadena[1024];   
            fseek(archivo, -1, SEEK_END);
            int len = ftell(archivo);
            while (len >= SEEK_SET)
            {
                if (((fgetc(archivo)) == '\n') || (len == SEEK_SET))
                {
                    fgets(cadena, sizeof(cadena)-1, archivo);
                    fputs(cadena, stdout);
                }
               fseek(archivo, --len, SEEK_SET);
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