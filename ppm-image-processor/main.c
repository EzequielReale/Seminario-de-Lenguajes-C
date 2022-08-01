#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ppm.h"
#include "ppm-operations.h"
#include "tools.h"

int main(int argc, char *argv[]) {
  FILE *in = NULL, *out = NULL;
  t_ppm p, p_temp;
  int c;
  unsigned short in_quantity = 0, out_quantity = 0;

  while ((c = getopt(argc, argv, "i:o:b:nrhv?")) != -1)
  {
    switch (c)
    {
    case O_INPUT:
      if (in_quantity == 0)
      {
        if (!(in = fopen(optarg, "r"))) manage_errors(E_OPEN_FILE, in, out);
        else
        {
          in_quantity++;
          p = ppm_from_file(in);
        }
      }
      else manage_errors(E_INVALID_ARG, in, out);
      break;
    case O_OUTPUT:
      if ((out_quantity == 0) && (in_quantity == 1))
      {
        if (!(out = fopen(optarg, "w"))) manage_errors(E_OPEN_FILE, in, out);
        else out_quantity++;
      }
      else manage_errors(E_INVALID_ARG, in, out);
      break;
    case O_ROTATION: 
      if (in_quantity == 1)
      {
        p_temp = ppm_operation_rotate90(p);
        ppm_free(p);
        p = p_temp;
      }
      else manage_errors(E_INVALID_ARG, in, out);
      break;
    case O_FLIPH:
      if (in_quantity == 1)
      {
        p_temp = ppm_operation_flip_horizontal(p);
        ppm_free(p);
        p = p_temp;
      }
      else manage_errors(E_INVALID_ARG, in, out);
      break;
    case O_FLIPV:
      if (in_quantity == 1)
      {
        p_temp = ppm_operation_flip_vertical(p);
        ppm_free(p);
        p = p_temp;
      }
      else manage_errors(E_INVALID_ARG, in, out);
      break;
    case O_BLUR:
      if (in_quantity == 1)
      {
        unsigned int ratio = atoi(optarg);
        if (ratio)
        {
          if (ratio > 255) ratio = 255;
          p_temp = ppm_operation_blur(p, ratio);
          ppm_free(p);
          p = p_temp;
        }
        else manage_errors(E_INVALID_ARG, in, out);
      }
      else manage_errors(E_INVALID_ARG, in, out);
      break;
    case O_NEGATIVE:
      if (in_quantity == 1)
      {
        p_temp = ppm_operation_negative(p);
        ppm_free(p);
        p = p_temp;
      }
      else manage_errors(E_INVALID_ARG, in, out);
      break;
    case O_HELP:
      help(argv[0]);
      exit(EXIT_SUCCESS);
      break;
    default:
      manage_errors(E_NOT_IMPLEMENTED, in, out);
      break;
    }
  }
  
  if (in_quantity == 1)
  {
    if (out_quantity == 1)
    {
      ppm_save(p, out);
      fclose(out);
    }
    else manage_errors(E_INVALID_ARG, in, out);
    ppm_free(p);
    fclose(in);
  }
  else manage_errors(E_INVALID_ARG, in, out);

  exit(EXIT_SUCCESS);
}
