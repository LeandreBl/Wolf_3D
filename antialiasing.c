/*
** antialiasing.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Jan  9 11:09:40 2017 Léandre Blanchard
** Last update Tue Jan 10 13:26:21 2017 Léandre Blanchard
*/

#include "include/wolf.h"

sfColor		get_pixel_color(sfUint8 *pixels, sfVector2i xy)
{
  sfColor	color;

  color.r = pixels[(xy.y * WIDTH + xy.x) * 4 + 0];
  color.g = pixels[(xy.y * WIDTH + xy.x) * 4 + 1];
  color.b = pixels[(xy.y * WIDTH + xy.x) * 4 + 2];
  color.a = pixels[(xy.y * WIDTH + xy.x) * 4 + 3];
  return (color);
}

sfColor		diff_color(sfUint8 *pixels, sfVector2i xy)
{
  sfColor       color[3];
  t_vars	x;
  int		i;

  i = 0;
  color[0] = get_pixel_color(pixels, xy);
  color[1] = get_pixel_color(pixels, xy_vectori(xy.x, xy.y + 1));
  color[2] = get_pixel_color(pixels, xy_vectori(xy.x + 1, xy.y));
  while (i != 3)
    {
      x.i += color[i].r;
      x.j += color[i].g;
      x.k += color[i].b;
      i = i + 1;
    }
  x.i = x.i / 3;
  x.j = x.j / 3;
  x.k = x.k / 3;
  return (color[0]);
}

int		antialiasing(t_win *window, int aa)
{
  sfVector2i	xy;
  sfColor	color;

  xy = xy_vectori(0, 0);
  while (xy.y < HEIGHT)
    {
      xy.x = 0;
      while (xy.x < WIDTH)
	{
	  my_put_pixel(window, xy.x, xy.y, diff_color(window->pixels, xy));
	  xy.x = xy.x + 1;
	}
      xy.y = xy.y + 1;
    }
  return (0);
}
