#include <stdio.h>

int esEOF()
{
    if (getchar() != EOF)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    printf("Es EOF?: %d",esEOF());
    return 0;
}