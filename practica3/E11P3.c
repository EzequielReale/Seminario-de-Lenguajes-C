#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *my_strcat(char *dest, const char *src)
{
    for (; *dest != '\0'; dest++);

    for (; *src != '\0'; src++, dest++) *dest = *src;

    *dest = '\0';

    return dest;
}

int my_strcmp(const char *s1, const char *s2)
{
    int ret = 0;

    while ((*s1 == *s2) && (*s1 != '\0') && (*s2 != '\0'))
    {
        s1++;
        s2++;
    }

    if (*s1 > *s2) ret++;
    else if (*s1 < *s2) ret--;

    return ret;
}

char *my_strcpy(char *dest, const char *src)
{
    for (; *src != 0; src++, dest++) *dest = *src;
    *dest = '\0';

    return dest;
}

size_t my_strlen(const char *s)
{
    int i = 0;
    for (; s[i] != 0; i++);
    return i;
}

const char *my_strstr(const char *haystack, const char *needle)
{
    int i = 0, size = strlen(needle);
    while (haystack[i] != 0)
    {
        if (strncmp(haystack + i, needle, size) == 0) return haystack + i;
        i++;
    }
    return NULL;
}

int main()
{
    char s1[255] = "Hola";
    char s2[255] = " abhoasdadhola";

    printf("s1: %s\n",s1);
    printf("s2: %s\n",s2);

    my_strcat(s1, s2);
    printf("s1 + s2: %s\n", s1);

    printf("Comparacion de s1 y s2 (0 iguales; 1 o -1 distintos): %d\n", my_strcmp(s1, s2));

    my_strcpy(s2, s1);
    printf("Copia de s1 en s2 --> s2: %s\n", s2);

    my_strcat(s1, s2);
    printf("s1 + s2: %s\n", s1);

    printf("El tamaño del string s1 es: %ld\n", my_strlen(s1));

    printf("Substring \"hola\": %s\n", my_strstr(s2, "hola"));

    return 0;
}