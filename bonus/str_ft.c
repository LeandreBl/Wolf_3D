/*
** str_ft.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Dec 19 23:15:17 2016 Léandre Blanchard
** Last update Mon Jan  9 19:00:58 2017 Léandre Blanchard
*/

#include "include/wolf.h"

int		line_len(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\n')
    i = i + 1;
  return (i);
}

int		nb_lines(char *str)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	nb = nb + 1;
      i = i + 1;
    }
  return (nb);
}

int		my_tablen(int **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i = i + 1;
  return (i);
}

void		free_tab(int **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i = i + 1;
    }
  free(tab[i]);
  free(tab);
}

int		my_tablenc(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}
