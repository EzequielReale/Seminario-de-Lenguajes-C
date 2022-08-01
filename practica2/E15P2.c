#include <stdio.h>
#define macro1(expr) printf(#expr " = %g\n", expr);
#define macro2(uno, dos) uno ## dos

int main()
{
    macro2(mac,ro1)(2.2) // = macro1(2.2);
    return 0;
}