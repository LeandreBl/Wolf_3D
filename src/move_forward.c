/*
** move_forward.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/src
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat Jan  7 20:26:49 2017 Léandre Blanchard
** Last update Sat Jan  7 20:34:30 2017 Léandre Blanchard
*/

#include "wolf.h"

sfVector2f      move_forward(sfVector2f pos, float direction, float distance)
{
  direction = direction * M_PI / 160;
  pos.x = pos.x + distance * cos(direction);
  pos.y = pos.y - distance * sin(direction);
  return (pos);
}
