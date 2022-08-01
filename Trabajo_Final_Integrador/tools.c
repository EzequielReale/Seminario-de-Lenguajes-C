#include "tools.h"

void help()
{
    printf("Estos programas funcionan de la siguiente forma:\n\n"
    "**Head --> Imprime en pantalla los primeros n bytes/líneas del archivo\n"
    "**Tail --> Imprime en pantalla los últimos n bytes/líneas del archivo\n"
    "\n\nSe emplean los siguientes argumentos:\n\n"
    "-l <cantidad_lineas> o --lines <cantidad_lineas> \n\tMuestra en pantalla la cantidad de lineas ingresadas\n\tSi se omite la cantidad se muestran %d lineas por defecto.\n" 
    "-b <cantidad_bytes> o --bytes <cantidad_bytes> (solo en Head)\n\tMuestra en pantalla la cantidad de bytes ingresados\n\tNo puede omitirse la cantidad.\n"
    "<archivo> (como último argumento) \n\tAbre el archivo indicado\n\tSi se omite se lee por teclado.\n"
    "-r o --reverse (solo en tail) \n\tMuestra las lineas en orden inverso, es decir, a partir la última línea en reversa.\n"
    "-h o --help \n\tMuestra esta ayuda\n"
    "\n*ACLARACIÓN: los argumentos -l y -b son mutuamente excluyentes entre si.\n"
    "Además, líneas tiene prioridad, por lo que si se omiten ambos se imprimen por defecto 5 líneas\n", DEFAULT);
}

t_error manage_args(int argc, const char *argv[], FILE **fp, int *quantity, bool *lines, bool tail, ...)
{
    bool *reverse, *bytes;
    va_list args;
    va_start(args, tail);
    if (tail) reverse = va_arg(args, bool*);
    else bytes = va_arg(args, bool*);
    va_end(args);

    int i;
    for (i = 1; i < argc; i++)
    {
        if ((!strcmp(argv[i], "-l")) || (!strcmp(argv[i], "--lines")))
        {
            *lines = 1;
            if ((i+1) < argc)
            {
                *quantity = atoi(argv[i+1]);
                if (!*quantity) *quantity = DEFAULT;
                else i++;
            }
            else *quantity = DEFAULT;
        }
        else if ((!tail) && ((!strcmp(argv[i], "-b")) || (!strcmp(argv[i], "--bytes"))))
        {
            *bytes = 1;
            if ((i+1) < argc)
            {
                *quantity = atoi(argv[i+1]);
                if (!*quantity) return E_INVALID_ARG;
                else i++;
            }
            else return E_INVALID_ARG;
        }
        else if ((tail) && ((!strcmp(argv[i], "-r")) || (!strcmp(argv[i], "--reverse"))))
        {
            *reverse = 1;
        }
        else if ((!strcmp(argv[i], "-h")) || (!strcmp(argv[i], "--help"))) 
        {
            help();
            exit(E_OK);
        }
        else if (i == (argc-1))
        {
            if (!(*fp = (fopen(argv[i], "r")))) return E_OPEN_FILE;
        }
        else return E_INVALID_ARG;
    }

    if (tail)
    {
        if (!*lines)
        {
            *lines = 1;
            *quantity = DEFAULT;
        }
    }
    else if ((!*lines) && (!*bytes)) 
    {
        *lines = 1;
        *quantity = DEFAULT;
    }
    else if ((*lines) && (*bytes)) return E_INVALID_ARG;

    return E_OK;
}

char *dynamic_fgets(char **buffer, FILE *fp)
{
    int c;
    size_t len = 0;

    while (((c = fgetc(fp)) != '\n') && (c != EOF)) 
    {
        if (!(*buffer = realloc(*buffer, sizeof(char) * ++len)))
        {
            error_to_output(E_ALLOC);
            exit(E_ALLOC);
        }
        
        (*buffer)[len-1] = (char)c; //Agrego el caracter
    }

    if (len == 0) return NULL;

    if(!(*buffer = realloc(*buffer, sizeof(char) * (len + 2))))
    {
        error_to_output(E_ALLOC);
        exit(E_ALLOC);
    }

    (*buffer)[len++] = '\n';
    (*buffer)[len] = '\0';
    return *buffer;
}