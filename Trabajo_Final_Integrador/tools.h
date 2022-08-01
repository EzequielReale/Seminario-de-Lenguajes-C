#ifndef TOOLS_H
#define TOOLS_H 1

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "errors.h"

#ifndef DEFAULT
#define DEFAULT 5
#endif

    typedef char bool;

    void help();

    t_error manage_args(int, const char**, FILE**, int*, bool*, bool, ...);

    char *dynamic_fgets(char**, FILE*);

#endif