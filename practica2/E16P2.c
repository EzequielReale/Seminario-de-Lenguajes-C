#include <stdio.h>
#define macro1(expr) printf(#expr "= %g\n", expr);
#define mi_macro(t, a, b) {t _z##a##_##b = a; a = b; b = _z##a##_ ##b ;}

int main()
{
    int a = 1, b = 2;
    mi_macro(int, a, b);
    return 0;
}