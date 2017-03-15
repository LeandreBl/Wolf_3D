/*
** raycast.c for wold3d in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Jan  3 15:22:27 2017 Léandre Blanchard
** Last update Thu Mar  2 12:47:37 2017 Léandre Blanchard
*/

#include "include/wolf.h"

void			test_guard(int x, int y, t_map *map, float dist)
{
  int			i;

  i = 0;
  while (i != 2)
    {
      if (map->ennemies[i].x == x && map->ennemies[i].y == y)
	{
	  map->is_guard = 1;
	  map->guard_dist = dist;
	}
      i++;
    }
}

t_dist		raycast(sfVector2f pos, float direction,
			int **map, sfVector2i mapsize, t_map *carte)
{
  sfVector2f	ray;
  t_dist        dist;
  sfColor	*colors;
  sfVector2f	prev;
  float		size;

  size = DIST_;
  if ((colors = fill_colors()) == NULL)
    return (dist);
  ray.x = pos.x;
  ray.y = pos.y;
  while (map[(int)ray.y][(int)ray.x] == '0'
	 && ray.y < mapsize.y && ray.x < mapsize.x)
    {
      prev = ray;
      ray = move_forward(ray, direction, size);
      dist.dist = sqrt(((pos.x - ray.x) * (pos.x - ray.x))
		       + ((pos.y - ray.y) * (pos.y - ray.y)));
      if (dist.dist > 10)
	size = 0.05;
      test_guard((int)ray.x, (int)ray.y, carte, dist.dist);
    }
  dist = color_finder(map, ray, dist);
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

  angle = window->fov / (-2);
  dist.dist = 0;
  x = 0;
  while (x < window->width)
    {
      dist = raycast(pos.pos, pos.direction + angle, map->map,
		     xy_vectori(map->cols, map->lines), map);
      dist.dist *= cos(M_PI / 200 * angle);
      if (dist.dist < 0.15)
	dist.dist = 0.15;
      wall_h = window->dist_proj / dist.dist;
      draw_column(window, xy_vector(x, window->height / 2 - wall_h / 2),
		  wall_h, dist);
      angle += (float)window->fov / (float)(window->width);
      if (map->is_guard == 1)
	{
	  put_guard(map, window, map->guard_dist, x);
	  map->is_guard = 0;
	}
      x++;
    }
  return (pos);
}
