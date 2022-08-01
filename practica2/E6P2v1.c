#include <stdio.h>

int main()
{
    char s[100];

    for (int i = 0; i < sizeof(s)/sizeof(char); i++)
    {
        s[i] = getchar();

        switch (s[i])
        {
        case '\\':
            i++;
            s[i] = '\\';
            break;
        case 9:
            s[i] = '\\';
            i++;
            s[i] = 't';
            break;
        case 10:
            s[i] = '\\';
            i++;
            s[i] = 'n';
            break;
        default:
            break;
        }
    }

    printf("%s", s);
    return 0;
}