#include "errors.h"

void error_to_output(t_error e)
{
    switch (e)
    {
    case E_OK:
        fprintf(stdout, "Sin errores. Code %d (OK)\n", E_OK);
        break;
    case E_INVALID_ARG:
        fprintf(stderr, "Argumento/s inválido/s. Code %d (INVALID_ARG)\n", E_INVALID_ARG);
        break;
    case E_OPEN_FILE:
        fprintf(stderr, "Error abriendo el archivo. Code %d (OPEN_FILE)\n", E_OPEN_FILE);
        break;
    case E_ALLOC:
        fprintf(stderr, "Error alocando memoria. Code %d (ALLOC)\n", E_ALLOC);
        break;
    default:
        fprintf(stderr, "Error desconocido. Code ? (UNKNOWN)\n");
        break;
    }
}