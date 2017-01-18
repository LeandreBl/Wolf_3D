/*
** minimap.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Jan 10 13:30:58 2017 Léandre Blanchard
** Last update Fri Jan 13 21:14:06 2017 Léandre Blanchard
*/

#include "include/wolf.h"

float		distance(sfVector2f bloc, t_map *map, t_pos pos)
{
  float		dist;
  sfVector2f	my;

  my = pos.pos;
  dist = sqrt(((my.x - bloc.x) * (my.x - bloc.x))
		   + ((my.y - bloc.y ) * (my.y - bloc.y)));
  return (dist);
}

float		angle_between(sfVector2f me, sfVector2f pos)
{
  float		angle;

  angle = -atan((me.y - pos.y) / (me.x - pos.x));
  return (angle);
}

void		all_blocs(t_win *window, t_map *map, t_pos pos, t_rot rot)
{
  int		i;
  int		y;

  i = 0;
  y = 0;
  while (y != map->lines)
    {
      i = 0;
      while (i != map->cols)
	{
	  rot.angle = angle_between(xy_vector(i, y), pos.pos);
	  rot.angle += M_PI / 180 * pos.direction;
	  rot.angle += M_PI / 2;
	  if (map->map[y][i] != '0')
	    put_square(window, rot, 5 * distance(xy_vector(i, y), map, pos),
		       color_rgb(100, 100, 100));
	  i++;
	}
      y++;
    }
}

void		display_walls(t_map *map, t_win *window, t_pos pos)
{
  int		i;
  int		j;
  t_rot		rot;

  rot.angle = M_PI / 180.0 * fmodf(pos.direction, 360);
  rot.pos = xy_vectori(80 - 2, 80 - 2);
  i = 0;
  j = 0;
  all_blocs(window, map, pos, rot);
}

void		minimap(t_map *map, t_win *window, t_pos pos)
{
  draw_circle(window, xy_vector(80, 22), 10, color_rgb(134, 82, 0));
  draw_circle(window, xy_vector(80, 80), 60, color_rgb(102, 52, 0));
  draw_circle(window, xy_vector(80, 80), 55, color_rgb(134, 82, 0));
  draw_circle(window, xy_vector(80, 80), 50, color_rgb(200, 200, 200));
  draw_circle(window, xy_vector(80, 80), 3, sfRed);
  draw_line(window, xy_vector(80, 80), xy_vector(60, 80), sfRed);
  display_walls(map, window, pos);
}
