/*
** raycast.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/src
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat Jan  7 20:19:20 2017 Léandre Blanchard
** Last update Sat Jan  7 20:24:31 2017 Léandre Blanchard
*/

#include "wolf.h"

float		raycast(sfVector2f pos, float direction,
			int **map, sfVector2i mapsize)
{
  sfVector2f	ray;

  ray.x = pos.x;
  ray.y = pos.y;
  while (map[(int)ray.y][(int)ray.x] == '0')
    ray = move_f(ray, direction, DIST_);
  return (sqrt(((pos.x - ray.x) * (pos.x - ray.x))
	       + ((pos.y - ray.y ) * (pos.y - ray.y))));
}

sfVector2f      move_f(sfVector2f pos, float direction, float distance)
{
  direction = direction * M_PI / 160;
  pos.x = pos.x + distance * cos(direction);
  pos.y = pos.y - distance * sin(direction);
  return (pos);
}
