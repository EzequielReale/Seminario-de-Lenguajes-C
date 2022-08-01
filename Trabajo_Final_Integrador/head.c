#include <stdlib.h>
#include "tools.h"
#include "programs.h"

int main(int argc, const char *argv[])
{
    bool lines = 0, bytes = 0;
    int quantity;
    FILE *fp = NULL;
    
    t_error error = manage_args(argc, argv, &fp, &quantity, &lines, 0, &bytes);
    if (error)
    {
        error_to_output(error);
        help();
        exit(error);
    }

    if (!fp) fp = stdin;
    
    int total;
    if (lines)
    {
        total = right_lines(fp, quantity);
        if ((total < quantity) && (fp != stdin)) fprintf(stderr, "\n***Aclaración: usted pidió leer %d lineas pero el archivo "
                                              "solo contenía %d. Se imprimieron las primeras %d líneas\n", quantity, total, total);
    } 
    else if (bytes)
    {
        total = right_bytes(fp, quantity);
        if ((total < quantity) && (fp != stdin)) fprintf(stderr, "\n***Aclaración: usted pidió leer %d bytes pero el archivo "
                                              "solo contenía %d. Se imprimieron los primeros %d bytes\n", quantity, total, total);
    } 

    if (fp != stdin) fclose(fp);
    
    exit(E_OK);
}