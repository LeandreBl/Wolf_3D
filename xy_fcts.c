/*
** xy_fcts.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Dec 28 19:48:44 2016 Léandre Blanchard
** Last update Tue Jan  3 18:34:13 2017 Léandre Blanchard
*/

#include "include/wolf.h"

t_xy		tuple(int x, int y)
{
  t_xy		xy;

  xy.x = x;
  xy.y = y;
  return (xy);
}

int		tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i = i + 1;
  return (i);
}

sfVector2f	xy_vector(int x, int y)
{
  sfVector2f	xy;

  xy.x = x;
  xy.y = y;
  return (xy);
}

sfVector2i	xy_vectori(int x, int y)
{
  sfVector2i	xy;

  xy.x = x;
  xy.y = y;
  return (xy);
}
