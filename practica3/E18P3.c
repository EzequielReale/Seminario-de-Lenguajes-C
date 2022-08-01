#include "E3P3.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char conversion[1024];
    if(argc == 3)
    {
        convertir(atoi(argv[1]), conversion, atoi(argv[2]));
        puts(conversion);
        return 0;
    }
    else return 1;
}