#include "ppm-operations.h"

t_ppm ppm_operation_rotate90(t_ppm p)
{ 
  t_ppm new = ppm_create(p.width, p.height, p.depth);
  unsigned int row, col;

  for (row = 0; row < p.width; row++)
  {
    for (col = 0; col < p.height; col++) new.pixels[row][col] = p.pixels[col][row];
  }
  return new;
}

t_ppm ppm_operation_flip_horizontal(t_ppm p)
{
  t_ppm new = ppm_create(p.height, p.width, p.depth);
  unsigned int row, col;

  for (row = 0; row < p.height; row++)
  {
    for (col = 0; col < p.width; col++) new.pixels[row][col] = p.pixels[row][p.width - col - 1];
  }
  return new;
}

t_ppm ppm_operation_flip_vertical(t_ppm p)
{
  t_ppm new = ppm_create(p.height, p.width, p.depth);
  unsigned int row, col;

  for (row = 0; row < p.height; row++)
  {
    for (col = 0; col < p.width; col++) new.pixels[row][col] = p.pixels[p.height - row - 1][col];
    // En la descripción de la función dice que se calcula como [i-height-1][j],
    // pero intuyo que es un error porque daría resultados erróneos. Entonces, calculo [height-i-1][j]
  }
  return new;
}

unsigned int max(int x, int y)
{
  return (x > y) ? x : y;
}

unsigned int min(int x, int y)
{
  return (x < y) ? x : y;
}

t_ppm ppm_operation_blur(t_ppm p, unsigned char ratio)
{
  t_ppm new = ppm_create(p.height, p.width, p.depth);
  unsigned int row, col, row_max, row_min, col_max, col_min, row_2, col_2, red, blue, green, quantity;

  for (row = 0; row < p.height; row++)
  {
    row_max = max(row - ratio, 0);
    row_min = min(row + ratio, p.height - 1);
    for (col = 0; col < p.width; col++)
    {
      col_max = max(col - ratio, 0);
      col_min = min(col + ratio, p.width - 1);
      red = 0;
      green = 0;
      blue = 0;
      quantity = 0;

      for (row_2 = row_max; row_2 <= row_min; row_2++)
      {
        for (col_2 = col_max; col_2 <= col_min; col_2++)
        { 
          red += p.pixels[row_2][col_2].red;
          green += p.pixels[row_2][col_2].green;
          blue += p.pixels[row_2][col_2].blue;
          quantity++;
        }
      }

      new.pixels[row][col].red = red / quantity;
      new.pixels[row][col].green = green / quantity;
      new.pixels[row][col].blue = blue / quantity;
    }
  }
  return new;
}

void ppm_invert_colours(t_ppm_pixel *p)
{
  p->red=255-p->red;
  p->green=255-p->green;
  p->blue=255-p->blue;
}

t_ppm ppm_operation_negative(t_ppm p)
{
  unsigned int row,col; 
  t_ppm new = ppm_create(p.height, p.width, p.depth);
  for(row=0; row < p.height; row++) for(col=0; col < p.width ; col++){
    new.pixels[row][col] = p.pixels[row][col];
    ppm_invert_colours(&new.pixels[row][col]);
  }
  return new;
}