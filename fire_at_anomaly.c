/*
** fire_at_anomaly.c for wolf3D in /home/leandre/Games/Wolf3D
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Mar  1 19:28:31 2017 Léandre Blanchard
** Last update Thu Mar  2 12:40:16 2017 Léandre Blanchard
*/

#include "wolf.h"

int		destroy_anomaly(t_pos pos, int **map)
{
  sfVector2f	ray;

  ray = xy_vector(pos.pos.x, pos.pos.y);
  while (map[(int)ray.y][(int)ray.x] == '0')
    ray = move_forward(ray, pos.direction, DIST_);
  if (map[(int)ray.y][(int)ray.x] == '9')
    {
      map[(int)ray.y][(int)ray.x] = ':';
      return (0);
    }
  if (map[(int)ray.y][(int)ray.x] == ':')
    {
      map[(int)ray.y][(int)ray.x] = '0';
      return (0);
    }
  return (-1);
}
