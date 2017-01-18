/*
** tab_ft.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Jan 13 12:03:10 2017 Léandre Blanchard
** Last update Fri Jan 13 12:58:07 2017 Léandre Blanchard
*/

#include "include/wolf.h"

int			my_strlenint(int *str)
{
  int			i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void			put_tab_int(int **tab)
{
  int			i;
  int			j;

  i = 0;
  while (tab[i] != NULL)
    {
      j = 0;
      while (tab[i][j] != 0)
	{
	  my_printf("%c", tab[i][j]);
	  j++;
	}
      my_printf("\n");
      i++;
    }
}

int                     *my_strdupi(int *line)
{
  int                   i;
  int                   *str;

  i = 0;
  if ((str = malloc(sizeof(int) * (my_strlenint(line) + 1))) == NULL)
    return (NULL);
  while (line[i] != 0)
    {
      str[i] = line[i];
      i++;
    }
  str[i] = 0;
  return (str);
}

int                     **my_tab_dup(t_map *map)
{
  int                   i;
  int                   **pos_map;

  i = 0;
  if ((pos_map = malloc(sizeof(int *) * (map->lines + 1))) == NULL)
    return (NULL);
  while (map->map[i] != NULL)
    {
      pos_map[i] = my_strdupi(map->map[i]);
      i++;
    }
  pos_map[i] = NULL;
  return (pos_map);
}
