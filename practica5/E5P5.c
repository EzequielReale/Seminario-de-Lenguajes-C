#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    if (argc == 3)
    {
        FILE *src, *dest;
        int i = 0;
        char c[1024], k[1024], *ok_1, *ok_2;

        if ((src = fopen(argv[1], "r")) && (dest = fopen(argv[2], "r")))
        {
            ok_1 = fgets(c, sizeof(c)-1, src);
            ok_2 = fgets(k, sizeof(k)-1, dest);
            while ((ok_1) && (ok_2))
            {
                puts(c);
                puts(k);
                ok_1 = fgets(c, sizeof(c)-1, src);
                ok_2 = fgets(k, sizeof(k)-1, dest);
                i++;
                if (strcmp(c, k))
                {
                    printf("Diferencia en la linea %d!\n", i);
                    break;
                }
            }
            if (!strcmp(c, k)) puts("Son iguales");
            printf("%d", i);
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