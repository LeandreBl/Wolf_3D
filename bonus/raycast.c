/*
** raycast.c for wold3d in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Jan  3 15:22:27 2017 Léandre Blanchard
** Last update Sun Jan 15 19:17:06 2017 Léandre Blanchard
*/

#include "include/wolf.h"

t_dist		raycast(sfVector2f pos, float direction,
			int **map, sfVector2i mapsize)
{
  sfVector2f	ray;
  t_dist        dist;
  sfColor	*colors;
  sfVector2f	prev;

  if ((colors = fill_colors()) == NULL)
    return (dist);
  ray.x = pos.x;
  ray.y = pos.y;
  while (map[(int)ray.y][(int)ray.x] == '0'
	 && ray.y < mapsize.y && ray.x < mapsize.x)
    {
      prev = ray;
      ray = move_forward(ray, direction, DIST_);
    }
  dist.dist = sqrt(((pos.x - ray.x) * (pos.x - ray.x))
	      + ((pos.y - ray.y) * (pos.y - ray.y)));
  dist = color_finder(map, ray, colors, dist);
  if ((int)ray.x != (int)prev.x || (int)ray.y != (int)prev.y)
    ((int)ray.y != (int)prev.y) ? (dist.change = 1) : (dist.change = 0);
  (dist.change == 1) ? (dist.x = texture_size *
			fmodf(ray.x, 1)) : (dist.x = texture_size * fmodf(ray.y, 1));
  free(colors);
  return (dist);
}

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  direction = direction * M_PI / 180;
  pos.x = pos.x + distance * cos(direction);
  pos.y = pos.y - distance * sin(direction);
  return (pos);
}

sfVector2f	get_pos(int **map)
{
  int		i;
  int		j;

  j = 0;
  while (map[j] != NULL)
    {
      i = 0;
      while (map[j][i] != '\0')
	{
	  if (map[j][i] == 'P')
	    {
	      map[j][i] = '0';
	      return (xy_vector(i + 1, j + 1));
	    }
	  i = i + 1;
	}
      j = j + 1;
    }
  my_printf("Player position not found, start anywhere ?\n");
  return (xy_vector(5, 5));
}

t_pos		walls(t_win *window, t_map *map, t_pos pos)
{
  float		wall_h;
  int		x;
  t_dist	dist;
  float		angle;
  float		guard;

  guard = sqrt(((pos.pos.x - 7) * (pos.pos.x - 7))
	       + ((pos.pos.y - 7) * (pos.pos.y - 7)));
  angle = window->fov / (-2);
  dist.dist = 0;
  x = 0;
  while (x < window->width)
    {
      dist = raycast(pos.pos, pos.direction + angle, map->map,
		       xy_vectori(map->cols, map->lines));
      dist.dist *= cos(M_PI / 200 * angle);
      wall_h = window->dist_proj / dist.dist;
      draw_column(window, xy_vector(x, window->height / 2 - wall_h / 2),
		  wall_h, dist);
      angle += (float)window->fov / (float)(window->width);
      x++;
    }
  return (pos);
}
