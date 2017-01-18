/*
** mallocs.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Dec 19 23:19:48 2016 Léandre Blanchard
** Last update Tue Jan  3 16:51:31 2017 Léandre Blanchard
*/

#include "include/wolf.h"

int		*my_str_malloc(char *map)
{
  int		i;
  int		*str;

  i = 0;
  str = malloc(sizeof(int) * (line_len(map) + 1));
  if (str == NULL)
    return (NULL);
  while (i != line_len(map) + 1)
    {
      str[i] = 0;
      i = i + 1;
    }
  return (str);
}

int             **my_tab_malloc(char *map)
{
  int           **tab;

  tab = malloc(sizeof(int *) * (nb_lines(map) + 1));
  if (tab == NULL)
    return (NULL);
  tab[nb_lines(map)] = NULL;
  return (tab);
}
