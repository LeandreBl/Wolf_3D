/*
** map_to_tab.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Dec 19 23:18:36 2016 Léandre Blanchard
** Last update Tue Jan  3 16:51:20 2017 Léandre Blanchard
*/

#include "include/wolf.h"

int		map_to_tab(t_map *map)
{
  t_vars	v;

  v.i = 0;
  v.k = 0;
  if ((map->map = my_tab_malloc(map->file)) == NULL)
    return (1);
  while (map->file[v.i] != '\0')
    {
      v.j = 0;
      if ((map->map[v.k] = my_str_malloc(map->file)) == NULL)
	return (1);
      while (map->file[v.i] != '\n')
	{
	  map->map[v.k][v.j] = map->file[v.i];
	  v.i = v.i + 1;
	  v.j = v.j + 1;
	}
      v.k = v.k + 1;
      v.i = v.i + 1;
    }
  return (0);
}
