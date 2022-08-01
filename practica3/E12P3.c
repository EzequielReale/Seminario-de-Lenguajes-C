#include <stdio.h>
#include <string.h>
#define PALABRA "neuquen"

int es_palindromo(const char *word){
    int j = strlen(word)-1, capicua = 1;

    for(int i=0; capicua && (i < j); i++, j--) capicua = (word[i] == word[j]);
    return capicua;
}

char *encripta(char *dest, const char *src)
{
    int length = strlen(src), i = 0;
    for(; i < length; i++) dest[i] = ~src[i];
    dest[i] = '\0';
    return dest;
}

/*
int main ()
{
    char w[] = PALABRA, encr[strlen(w)];
    printf("Es capicua? %d\n",es_palindromo(w));
    encripta(encr, w);
    printf("Palabra: %s\nPalabra encriptada: %s\n",w,encr);
    return 0;
}
*/