#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "programs.h"

void tail(FILE *fp, int lines, bool mode)
{
    int c, q_lines = 0;
    fseek(fp, -1, SEEK_END);
    while((q_lines < lines) && (ftell(fp) > 0))
    {
        if ((c = fgetc(fp)) == '\n') q_lines++;
        fseek(fp, -2, SEEK_CUR);
    }
    if (ftell(fp) > 0) fseek(fp, 2, SEEK_CUR);//Me desplazo hacia adelante para evitar el 1er \n
                                              //El desplazamiento es 1 en Linux pero 2 en Windows 
                                              //por el caracter "retorno de carro"

    if (!mode) right_lines(fp, lines);
    else reverse_lines(fp, lines);

    if (q_lines+1 < lines) fprintf(stderr, "\n***Aclaración: usted pidió leer %d lineas pero el archivo "
                            "solo contenía %d. Se imprimieron las últimas %d líneas\n", lines, q_lines+1, q_lines+1);
}

int main(int argc, const char *argv[])
{
    bool lines = 0, reverse = 0;
    int quantity;
    FILE *fp = NULL;
    
    t_error error = manage_args(argc, argv, &fp, &quantity, &lines, 1, &reverse);
    if (error)
    {
        error_to_output(error);
        help();
        exit(error);
    }

    if (!fp) 
    {
        fp = stdin;
        tail_stdin(fp, quantity, reverse);
    }
    else
    {
       tail(fp, quantity, reverse);
       fclose(fp);
    } 
    
    exit(E_OK);
}