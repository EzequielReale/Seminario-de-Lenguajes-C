#include <stdio.h>
#include <limits.h> // Para usar UINT_MAX

char uno()
{
    char c;
    c = 'A' + 2;
    return (c);
}

int dos()
{
    int a = 10;
    return ((a++ == 10) ? a : --a);
}

float tres()
{
    float x = (int)3.7 + 4.5;
    return x;
}

int cuatro()
{
    float x = 3.6;
    return (int)x;
}

int cinco()
{
    int a = 17, b;
    b = ++a % 3;
    return (b > 1);
}

int seis()
{
    int a = 3;
    a <<= 3;
    return a;
}

int siete()
{
    // Ver:
    // https://www.gnu.org/software/libc/manual/html_node/Range-of-Type.html
    unsigned a = 8, b;
    b = ~a;
    return (b == (UINT_MAX - 8));
}

int ocho()
{
    int i = 320;
    return (char)i;
}

double nueve()
{
    char c = 'A';
    return (double)c;
}

int main()
{
    char un = uno();
    printf("Uno: %c\n", un);

    int doss = dos();
    printf("Dos: %d\n", doss);

    float tre = tres();
    printf("Tres: %f\n", tre);

    int cu = cuatro();
    printf("Cuatro: %d\n", cu);

    int ci = cinco();
    printf("Cinco: %d\n", ci);

    int se = seis();
    printf("Seis: %d\n", se);

    int si = siete();
    printf("Siete: %d\n", si);

    int oc = ocho();
    printf("Ocho: %d\n", oc);

    double nue = nueve();
    printf("Nueve: %f\n", nue);
    return 0;
}