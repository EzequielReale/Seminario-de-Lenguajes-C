#include <stdio.h>

int main(int argc, char const *argv[]){
  int c;
  while((c = getchar())!= EOF){
    switch (c){
      case '\\':
        putchar('\\');
        putchar('\\');
        break;
      case '\t':
        putchar('\\');
        putchar('t');
        break;
      case '\n':
        putchar('\\');
        putchar('n');
        break;
      default:
        putchar(c);
      }        
  }
  return 0;
}