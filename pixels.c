/*
** pixels.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Dec 19 18:37:37 2016 Léandre Blanchard
** Last update Thu Jan 19 17:12:08 2017 Léandre Blanchard
*/

#include "include/wolf.h"

sfRenderWindow		*create_window(char *name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    return (NULL);
  return (window);
}

sfUint8			*pixels_buffer(int width, int height)
{
  int			i;
  sfUint8	       	*pixels;

  pixels = malloc(width * height * 4 * sizeof(sfUint8));
  if (pixels == NULL)
    return (NULL);
  i = 0;
  while (i != width * height * 4)
    {
      pixels[i] = 0;
      i = i + 1;
    }
  return (pixels);
}

void		my_draw_square(t_win *window, sfVector2i xy,
			       int size, sfColor color)
{
  int		i;
  int		j;

  j = 0;
  while (j != size)
    {
      i = 0;
      while (i != size)
	{
	  my_put_pixel(window, i + xy.x, xy.y + j, color);
	  i = i + 1;
	}
      j = j + 1;
    }
}

sfColor		*fill_colors()
{
  sfColor	*colors;

  if ((colors = malloc(sizeof(sfColor) * 9)) == NULL)
    return (NULL);
  colors[0] = color_rgb(113, 113, 113);
  colors[1] = color_rgb(200, 110, 110);
  colors[2] = color_rgb(110, 200, 110);
  colors[3] = color_rgb(110, 110, 200);
  colors[4] = color_rgb(200, 200, 110);
  colors[5] = color_rgb(200, 110, 200);
  colors[6] = color_rgb(200, 200, 200);
  return (colors);
}

void		empty_square(t_win *window, int x, int y, sfColor color)
{
  int		j;
  int		line;

  line = 0;
  while (line != 6)
    {
      j = 0;
      while (j != 50)
	{
	  my_put_pixel(window, x + j, y + line, color);
	  my_put_pixel(window, x + j, y + line + 40, color);
	  j = j + 1;
	}
      j = 0;
      while (j != 40)
	{
	  my_put_pixel(window, x + line, y + j, color);
	  my_put_pixel(window, x + line + 44, y + j, color);
	  j = j + 1;
	}
      line++;
    }
}
