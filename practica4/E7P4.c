#include <stdio.h>

struct
{
    int a;
    char b;
} test;

int main()
{
    printf("sizeof(struct)= %ld, sizeof(int)= %ld, sizeof(char)= %ld\n", sizeof(test), sizeof(test.a), sizeof(test.b));
    return 0;
}