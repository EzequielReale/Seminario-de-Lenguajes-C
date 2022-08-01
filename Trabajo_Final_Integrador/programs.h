#ifndef PROGRAMS_H
#define PROGRAMS_H 1
#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "t_lista_generica.h"
    
    int right_lines(FILE*, int);

    int right_bytes(FILE*, int);

    void reverse_lines(FILE*, int);

    void tail_stdin(FILE*, int, bool);

#endif