/*
** editor_parsing.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Jan 10 00:35:10 2017 Léandre Blanchard
** Last update Tue Jan 10 12:30:25 2017 Léandre Blanchard
*/

#include "include/wolf.h"

int		my_strleni(int nb)
{
  int		i;

  i = 0;
  while (nb != 0)
    {
      nb /= 10;
      i = i + 1;
    }
  return (i);
}

char		*calloc_tab(char *line, char **map, int size)
{
  int		i;
  int		j;

  if ((line = malloc(sizeof(char) * (size + 1) * size + 1)) == NULL)
    return (NULL);
  i = 0;
  while (map[i] != NULL)
    {
      j = 0;
      if (i == 0 || i == size - 1)
	{
	  while (j != size)
	    map[i][j++] = '1';
	}
      map[i][0] = '1';
      map[i][size - 1] = '1';
      i = i + 1;
    }
  return (line);
}

void		draw_arrow(int i)
{
  attron(COLOR_PAIR(4) | A_BOLD);
  mvprintw(LINES / 2 - 5, COLS / 2 - 1, "A");
  mvprintw(LINES / 2 - 4, COLS / 2 - 5 - my_strleni(i), "<");
  mvprintw(LINES / 2 - 4, COLS / 2 + 3 + my_strleni(i), ">");
  mvprintw(LINES / 2 - 3, COLS / 2 - 1, "v");
  attron(COLOR_PAIR(5) | A_BOLD);
  mvprintw(LINES / 2 - 4, COLS / 2 - my_strleni(i) - 3, "[%d x %d]", i, i);
  attron(COLOR_PAIR(3) | A_BOLD);
  mvprintw(LINES / 2 - 8, COLS / 2 - 10, "Select a map size :");
  mvprintw(LINES / 2 - 7, COLS / 2 - 9, "Press [x] to quit");
  attroff(COLOR_PAIR(3));
}
