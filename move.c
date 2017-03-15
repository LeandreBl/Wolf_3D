/*
** move.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Jan  8 03:44:04 2017 Léandre Blanchard
** Last update Thu Jan 19 17:19:19 2017 Léandre Blanchard
*/

#include "include/wolf.h"

t_pos			move_events(t_map *map, t_pos pos)
{
  if (option == 1)
    return (pos);
  if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyUp))
    pos = mv_up(pos, map);
  if (sfKeyboard_isKeyPressed(sfKeyW) || sfKeyboard_isKeyPressed(sfKeyDown))
    pos = mv_down(pos, map);
  if (sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyLeft))
    pos.direction -= 3.0;
  if (sfKeyboard_isKeyPressed(sfKeyD) || sfKeyboard_isKeyPressed(sfKeyRight))
    pos.direction += 3.0;
  if (pos.direction < 0)
    pos.direction = 360 + pos.direction;
  if (pos.direction > 360)
    pos.direction = pos.direction - 360;
  return (pos);
}

t_pos			mv_up(t_pos pos, t_map *map)
{
  t_pos			prev;

  prev = pos;
  pos.pos.x += MOVEX;
  pos.pos.y -= MOVEY;
  if (map->map[(int)pos.pos.y][(int)pos.pos.x] != '0')
    {
      if (map->map[(int)pos.pos.y][(int)prev.pos.x] == '0')
	{
	  prev.pos.y = pos.pos.y;
	  return (prev);
	}
      if (map->map[(int)prev.pos.y][(int)pos.pos.x] == '0')
	{
	  prev.pos.x = pos.pos.x;
	  return (prev);
	}
      return (prev);
    }
  return (pos);
}

t_pos			mv_down(t_pos pos, t_map *map)
{
  t_pos			prev;

  prev = pos;
  pos.pos.x -= MOVEX;
  pos.pos.y += MOVEY;
  if (map->map[(int)pos.pos.y][(int)pos.pos.x] != '0')
    {
      if (map->map[(int)pos.pos.y][(int)prev.pos.x] == '0')
	{
	  prev.pos.y = pos.pos.y;
	  return (prev);
	}
      if (map->map[(int)prev.pos.y][(int)pos.pos.x] == '0')
	{
	  prev.pos.x = pos.pos.x;
	  return (prev);
	}
      return (prev);
    }
  return (pos);
}
