#include <stdio.h>

int main(int argc, const char *argv[])
{
    if (argc > 2)
    {
        FILE *archivo, *ult = fopen(argv[argc-1], "a");
        int c;

        for (int i = 1; i < argc-1; i++)
        {
            if ((archivo = fopen(argv[i], "r")))
            {
                fputc('\n', ult);
                while ((c = fgetc(archivo)) != EOF)
                {
                    fputc(c, ult);
                }
                fclose(archivo);  
            }
            else fputs("Algun archivo no pudo abrirse", stderr);
        }
        fclose(ult);
    }
    else
    {
        fputs("Cantidad inferior de argumentos", stderr);
        return 1;
    }
    return 0;
}