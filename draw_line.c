/*
** draw_line.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Dec 19 18:35:33 2016 Léandre Blanchard
** Last update Wed Mar  1 20:24:58 2017 Léandre Blanchard
*/

#include "include/wolf.h"

void    my_put_pixel(t_win *window, int x, int y, sfColor color)
{
  if (x < 0 || y < 0)
    return;
  if (x > window->width || y > window->height)
    return;
  window->pixels[(window->width * y + x) * 4 + 0] = color.r;
  window->pixels[(window->width * y + x) * 4 + 1] = color.g;
  window->pixels[(window->width * y + x) * 4 + 2] = color.b;
  window->pixels[(window->width * y + x) * 4 + 3] = color.a;
}

void		draw_column(t_win *window, sfVector2f from,
			    int size, t_dist dist)
{
  int		y;
  sfImage	**images;
  sfColor	color;
  int		i;

  images = init_textures(1);
  i = 0;
  y = from.y;
  while (y < from.y + size && y < window->height)
    {
      if (dist.texture < 9)
	color = sfImage_getPixel(images[dist.texture],
      (int)dist.x % texture_size, (float)texture_size / size * i);
      else if (dist.texture == 9)
	color = sfColor_fromRGB(rand() % 155, rand() % 155, rand() % 155);
      else
	color = sfColor_fromRGB(rand() % 255, rand() % 255, rand() % 255);
      if (lights == 1)
	color = color_rgb(color.r / DIST_C, color.g / DIST_C, color.b / DIST_C);
      if (dist.change == 1)
	color = color_rgb(color.r / 1.3, color.g / 1.3, color.b / 1.3);
      my_put_pixel(window, from.x, y, color);
      y++;
      i++;
    }
}

void		put_square(t_win *window, t_rot rot, int size, sfColor color)
{
  int		i;
  int		j;

  i = rot.pos.y;
  while (i != rot.pos.y + 5)
    {
      j = rot.pos.x;
      while (j != rot.pos.x + 5)
	{
	  if (size < 50)
	    my_put_pixel(window, j + size * cos(rot.angle),
			 i + size * sin(rot.angle), color);
	  j++;
	}
      i++;
    }
}

void			draw_line(t_win *window, sfVector2f from,
				  sfVector2f to, sfColor color)
{
  int			y;

  y = from.y;
  while (y != to.y)
    {
      my_put_pixel(window, from.x, y, color);
      y++;
    }
}
