/*
** editor.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Jan  9 15:52:01 2017 Léandre Blanchard
** Last update Sun Jan 15 18:54:04 2017 Léandre Blanchard
*/

#include "include/wolf.h"

int		receive_arrow(int i, int a)
{
  if (i == KEY_DOWN)
    a = a  * 10;
  if (i == KEY_UP)
    a = a / 10;
  if (i == KEY_LEFT)
    a = a - 1;
  if (i == KEY_RIGHT)
    a = a + 1;
  if (a < 5)
    a = 5;
  if (a > 100)
    a = 100;
  refresh();
  return (a);
}

char		*morph(char **map, int size)
{
  char		*line;
  int		i;
  int		j;
  int		k;

  line = calloc_tab(line, map, size);
  map[(size - 1) / 2][(size - 1) / 2] = 'P';
  i = 0;
  j = 0;
  k = 0;
  while (map[i] != NULL)
    {
      j = 0;
      while (map[i][j] != 0)
	{
	  line[k] = map[i][j];
	  j = j + 1;
	  k = k + 1;
	}
      line[k] = '\n';
      k = k + 1;
      i = i + 1;
    }
  line[k] = 0;
  return (line);
}

char		*create_map(int size)
{
  char		**map;
  int		i;
  int		j;
  char		*line;

  i = 0;
  if ((map = malloc(sizeof(char*) * size + 1)) == NULL)
    return (NULL);
  while (i != size)
    {
      j = 0;
      if ((map[i] = malloc(sizeof(char) * size + 1)) == NULL)
	return (NULL);
      while (j != size)
	{
	  map[i][j] = '0';
	  j = j + 1;
	}
      map[i][j] = 0;
      i = i + 1;
    }
  map[j] = NULL;
  line = morph(map, size);
  return (line);
}

int		display_size()
{
  int		a;
  int		i;

  i = 0;
  a = 5;
  attron(COLOR_PAIR(5) | A_BOLD);
  while (1)
    {
      clear();
      curs_set(0);
      draw_arrow(a);
      i = getch();
      a = receive_arrow(i, a);
      if (i == 10)
	break;
      if (i == 'x' || i == 'X')
	{
	  endwin();
	  exit(0);
	}
    }
  return (a);
}

char		*editor()
{
  int		i;
  char		*map;

  i = display_size();
  map = create_map(i);
  write(open("map.dat", O_WRONLY),
	map, (i + 1) * i);
  free(map);
  return ("map.dat");
}
