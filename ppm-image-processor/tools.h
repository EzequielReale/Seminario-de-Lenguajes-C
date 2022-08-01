#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppm.h"

#define O_INPUT 'i'
#define O_OUTPUT 'o'
#define O_ROTATION 'r'
#define O_FLIPH 'h'
#define O_FLIPV 'v'
#define O_BLUR 'b'
#define O_NEGATIVE 'n'
#define O_HELP '?'

#define E_OPEN_FILE 2
#define E_INVALID_ARG 22
#define E_NOT_IMPLEMENTED 38

void manage_errors(int, FILE*, FILE*, t_ppm*);

void help(char *);

#endif