#include <stdio.h>

int main(int argc, const char *argv[])
{
    if (argc == 3)
    {
        FILE *src, *dest;
        int c, k, i = 0;

        if ((src = fopen(argv[1], "r")) && (dest = fopen(argv[2], "r")))
        {
            c = fgetc(src);
            k = fgetc(dest);
            while ((c != EOF) && (k != EOF))
            {
                c = fgetc(src);
                k = fgetc(dest);
                i++;
                if (c != k)
                {
                    printf("Diferencia en el byte %d!\n", i);
                    break;
                }
            }
            if (c == k) puts("Son iguales");
            fclose(src);
            fclose(dest);
        }
        else fputs("No pudo abrirse algun archivo", stderr);
    }
    else
    {
        fputs("Debe ingresar 2 archivos", stderr);
        return 1;
    }
    return 0;
}