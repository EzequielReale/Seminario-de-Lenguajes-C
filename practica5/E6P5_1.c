#include <stdio.h>
#include <string.h>
#define BUFFER 4096

int main(int argc, const char *argv[])
{
    FILE *archivo;
    int cant;
    char c[1024];
    for (int i = 1; i < argc; i++)
    {
        if ((archivo = fopen(argv[i], "r")))
        {
            printf("\n\nArchivo %s:\n",argv[i]);
            while ((cant = fread(c, sizeof(char), BUFFER, archivo)) != 0)
            {
                fwrite(c, sizeof(char), strlen(c), stdout);
            }
            fclose(archivo);
            
        }
        else fputs("El archivo no pudo abrirse", stderr);
    } 
    return 0;
}