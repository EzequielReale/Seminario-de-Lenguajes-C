#include <stdio.h>
#define min(x,y) ((x < y) ? x : y)
#define max(x,y) ((x > y) ? x : y)

int main()
{
    int x = 7, y = 8;
    printf("El minimo entre x=%d e y=%d es: %d\n",x,y,min(x++,y++));
    printf("El maximo entre x=%d e y=%d es: %d\n",x,y,max(x++,y++));
    return 0;
}