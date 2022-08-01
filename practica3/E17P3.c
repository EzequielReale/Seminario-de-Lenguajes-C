#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char password[] = "12345";

    int ok = 0, i;
    for(i = 1; i < argc; i++){
        if((ok = !strcmp(argv[i],password))) {
            puts("C is quirky, flawed, and an enormous success. - Dennis Ritchie\n");
            break;
        } 
    }
    if(!ok) fprintf(stderr,"Casi\n");
    return 0;
}