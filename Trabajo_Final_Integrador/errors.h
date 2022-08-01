#ifndef ERRORS_H
#define ERRORS_H 1
#include <stdio.h>

    typedef short t_error;

    #define E_OK 0
    #define E_INVALID_ARG 1
    #define E_OPEN_FILE 2
    #define E_ALLOC 3

    void error_to_output(t_error);

#endif