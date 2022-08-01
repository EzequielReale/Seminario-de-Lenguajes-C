#include <stdio.h>

int main(int argc, const char *argv[])
{
    FILE *archivo;
    int c;
    for (int i = 1; i < argc; i++)
    {
        if ((archivo = fopen(argv[i], "r")))
        {
            printf("********Archivo %s********\n",argv[i]);
            while ((c = fgetc(archivo)) != EOF)
            {
                fputc(c, stdout);
            }
            fputc('\n', stdout);
            fclose(archivo); 
        }
        else fputs("El archivo no pudo abrirse", stderr);
    } 
    return 0;
}