#include <stdio.h>

int main()
{
    int x, y;
    scanf(" %d", &x);
    printf("%d\n\n",x);
    scanf(" %d %d", &x, &y);
    printf("%-5d%d\n\n",x, y);
    scanf(" %d %d", &x, &y);
    printf("%-5d%d\n\n",x, y);
    return 0;
}