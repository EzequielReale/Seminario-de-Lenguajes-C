#include "tools.h"

void manage_errors(int error, FILE *in, FILE *out, t_ppm *p)
{
  fprintf(stderr, "ERROR: %s. CODE %d.\n"
          "Try -%c for some help.\n", strerror(error), error, O_HELP);
  if (in) fclose(in);
  if (out) fclose(out);
  ppm_free(*p);

  exit(error);
}

void help(char *name)
{
  printf("This program makes operations on ppm images and is used as follows:\n"
         "\t%s -i <input> -o <output> <arguments...>\n\n"
         "Possible arguments are:\n"
         "\t-n: calculates the negative\n"
         "\t-r: rotate 90 degrees\n"
         "\t-h: horizontal mirroring\n"
         "\t-v: vertical mirroring\n"
         "\t-b <NUMBER>: blur with radius NUMBER (up to 255)\n"
         "\t-?: displays program's help\n", name);
}