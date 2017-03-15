/*
** color.c for wolf in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Dec 19 21:22:38 2016 Léandre Blanchard
** Last update Thu Jan 19 17:15:04 2017 Léandre Blanchard
*/

#include "include/wolf.h"

sfColor         color_rgb(sfUint8 r, sfUint8 g, sfUint8 b)
{
  sfColor       color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = 255;
  return (color);
}

sfColor		color_rgba(sfUint8 r, sfUint8 g, sfUint8 b, sfUint8 a)
{
  sfColor	color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
  return (color);
}

int		change_wall(t_map *map, t_pos pos, int a)
{
  sfVector2f	ray;

  ray.x = pos.pos.x;
  ray.y = pos.pos.y;
  while (map->map[(int)ray.y][(int)ray.x] == '0')
    ray = move_forward(ray, pos.direction, DIST_);
  if (map->map[(int)ray.y][(int)ray.x] != 'D')
    map->map[(int)ray.y][(int)ray.x] = a + 49;
  return (0);
}

int		visor(t_win *window)
{
  int		i;

  i = 0;
  while (i != 10)
    {
      my_put_pixel(window, window->width / 2 - i,
		   window->height / 2, color_rgb(0, 0, 0));
      my_put_pixel(window, window->width / 2 + i,
		   window->height / 2, color_rgb(0, 0, 0));
      my_put_pixel(window, window->width / 2,
		   window->height / 2 + i, color_rgb(0, 0, 0));
      my_put_pixel(window, window->width / 2,
		   window->height / 2 - i, color_rgb(0, 0, 0));
      i = i + 1;
    }
  return (0);
}

int		walls_gui(t_win *window, int on)
{
  sfColor	*colors;
  static int	a;
  int		i;
  int		j;

  colors = fill_colors();
  if (on == 0)
    (a == 0) ? (a = 1) : (a = 0);
  i = 0;
  while (i != 8 && a == 1)
    {
      j = 0;
      if (i < 7)
	draw_cube(window, i);
      while (j != 40)
	j = walls_gui_lines(window, i, j);
      i = i + 1;
    }
  i = 0;
  while (i != 7 * 40 && a == 1)
    i = walls_gui_cols(window, i);
  (a == 1) ? empty_square(window, window->width - 55,
  window->height / 2 - 160 + slot_nb(0) * 40, color_rgb(210, 210, 210)) : 0;
  free(colors);
  return (a);
}
