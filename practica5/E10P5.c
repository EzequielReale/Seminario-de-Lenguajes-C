#include <stdio.h>

typedef struct{
    char nombre[100], apellido [100];
    int edad;
} persona;

int main(int argc, const char *argv[])
{
    if (argc >= 2)
    {
        FILE *archivo;      
        if ((archivo = fopen(argv[1], "w+")))
        {
            persona p;
            p.edad = 0;
            while (p.edad != -1)
            {
                puts("Ingrese nombre, apellido y edad de la persona separados por espacio (termina poniendo edad -1):");
                if (scanf("%s %s %d", p.nombre, p.apellido, &p.edad) != 3)
                {
                    char c;
                    do
                    {
                        c = getchar();
                    } while (c != '\n');
                }
                else if (p.edad != -1) fwrite(&p, sizeof(p), 1, archivo);
            }

            fseek(archivo, 0, SEEK_SET);
            while (fread(&p, sizeof(p), 1, archivo)) printf("%s %s %d\n", p.nombre, p.apellido, p.edad);
            
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