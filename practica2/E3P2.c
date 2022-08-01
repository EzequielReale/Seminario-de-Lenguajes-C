#include <stdio.h>

int main()
{
    int c = getchar();
    
    while (c != EOF)
    {
        if (c != 10)
        {
            printf("Trabajo muy duro, como un esclavo!\n");
        }
        c = getchar();
    }
    return 0;
}