#include <stdio.h>

int main(int argc, const char *argv[])
{
    if (argc == 3)
    {
        FILE *archivo;
        int c;

        if ((archivo = fopen(argv[1], "r")))
        {
            FILE *ult = fopen(argv[2], "w");
            while ((c = fgetc(archivo)) != EOF) fputc(c, ult);
            fclose(archivo);
            fclose(ult);
        }
        else fputs("No pudo abrirse el archivo a copiar", stderr);
    }
    else
    {
        fputs("Debe ingresar 2 archivos", stderr);
        return 1;
    }
    return 0;
}