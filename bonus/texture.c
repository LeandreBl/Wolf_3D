/*
** texture.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Jan 10 14:05:03 2017 Léandre Blanchard
** Last update Wed Jan 11 13:18:13 2017 Léandre Blanchard
*/

#include "include/wolf.h"

sfImage			**init_textures(int a)
{
  static sfImage	**images;

  if (a == 1)
    return (images);
  if (a == 2)
    {
      free_textures(images);
      return (NULL);
    }
  if ((images = malloc(sizeof(sfImage *) * 11)) == NULL)
    return (NULL);
  if (a == 3)
    {
      while (sfKeyboard_isKeyPressed(sfKeyF2));
      if (texture_size == 64)
	images = low_quality(images);
      else if (texture_size == 32)
	images = high_quality(images);
      else if (texture_size == 512)
	images = wolf_qualitad(images);
    }
  while (sfKeyboard_isKeyPressed(sfKeyF2));
  return (images);
}

void			draw_cube(t_win *window, int i)
{
  sfImage		*image;
  sfVector2i		xy;
  int			x;
  int			y;

  x = 0;
  y = 0;
  xy = xy_vectori(window->width - 49, window->height / 2 - 4 * 40 + i * 40);
  image = init_textures(1)[i];
  while (y != 40)
    {
      x = 0;
      while (x != 40)
	{
	  my_put_pixel(window, xy.x + x, xy.y + y,
		       sfImage_getPixel(image,
	  (float)texture_size / 40 * x, (float)texture_size / 40 * y));
	  x++;
	}
      y++;
    }
}

void			draw_circle(t_win* window, sfVector2f pos,
				    int size, sfColor color)
{
  int			i;
  int			j;
  float			dist;

  i = -size;
  dist = 0;
  while (i < size)
    {
      j = -size;
      while (j < size)
	{
	  dist = sqrt(((pos.x - pos.x + j) * (pos.x - pos.x + j))
		      + ((pos.y - pos.y + i) * (pos.y - pos.y + i)));
	  if (dist < size)
	    my_put_pixel(window, pos.x + j, pos.y + i, color);
	  j++;
	}
      i++;
    }
}

void			free_textures(sfImage **images)
{
  int			i;

  i = 0;
  while (images[i] != NULL)
    {
      sfImage_destroy(images[i]);
      i++;
    }
  free(images);
}
