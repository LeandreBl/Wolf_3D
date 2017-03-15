/*
** add_color.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat Jan  7 19:47:20 2017 Léandre Blanchard
** Last update Wed Mar  1 20:24:08 2017 Léandre Blanchard
*/

#include "include/wolf.h"

int		walls_gui_cols(t_win *window, int i)
{
  my_put_pixel(window, window->width - 50, window->height
	       / 2 - 4 * 40 + i, color_rgb(0, 0, 0));
  my_put_pixel(window, window->width - 10, window->height
	       / 2 - 4 * 40 + i, color_rgb(0, 0, 0));
  return (i + 1);
}

int		walls_gui_lines(t_win *window, int i, int j)
{
  my_put_pixel(window, window->width - 50 + j,
	       window->height / 2 - 4 * 40 + i * 40, color_rgb(0, 0, 0));
  return (j + 1);
}

t_dist		color_finder(int **map, sfVector2f ray, t_dist dist)
{
  int		i;

  i = 0;
  while (i != 8)
    {
      if (map[(int)ray.y][(int)ray.x] == i + 48)
	dist.texture = i - 1;
      i = i + 1;
    }
  if (map[(int)ray.y][(int)ray.x] == 'D')
    {
      if (dist.dist < 1)
	map[(int)ray.y][(int)ray.x] = '0';
      dist.texture = DOOR;
    }
  if (map[(int)ray.y][(int)ray.x] == 57)
    dist.texture = 9;
  if (map[(int)ray.y][(int)ray.x] == 58)
    dist.texture = 10;
  return (dist);
}

int		add_door(t_map *map, t_pos pos)
{
  sfVector2f	ray;

  ray.x = pos.pos.x;
  ray.y = pos.pos.y;
  while (map->map[(int)ray.y][(int)ray.x] == '0')
    ray = move_forward(ray, pos.direction, DIST_);
  if ((int)ray.y != 0 && (int)ray.y != map->lines - 1)
    if ((int)ray.x != 0 && (int)ray.x != map->cols - 1)
      if (map->map[(int)ray.y][(int)ray.x] != '0')
	map->map[(int)ray.y][(int)ray.x] = 'D';
  return (0);
}

int		slot_nb(int a)
{
  static int	nb;

  if (a == (-1))
    nb = nb - 1;
  if (a == (1))
    nb = nb + 1;
  if (nb == (-1))
    nb = 6;
  if (nb == 7)
    nb = 0;
  return (nb);
}
