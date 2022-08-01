#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    long bytes;
    if (argv[1]) 
    {
        char *ptr;
        bytes = strtol(argv[1], &ptr, 10);
    }
    else bytes = 10;

    char *buffer = NULL;
    size_t n = 0;

    for(int i = 0; i < bytes; i++)
    {
       if (getline(&buffer,&n,stdin) != EOF) puts(buffer);
       else exit(1); 
    }

    return 0;
}