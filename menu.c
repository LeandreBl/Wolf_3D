/*
** menu.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Jan  9 12:28:40 2017 Léandre Blanchard
** Last update Wed Jan 25 16:22:16 2017 Léandre Blanchard
*/

#include "include/wolf.h"

void		pairs()
{
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_YELLOW, COLOR_BLACK);
}

void		names_print(char **names)
{
  int		j;

  j = 0;
  while (names[j] != NULL)
    {
      if (test_wf(names[j]) == 0)
	attron(COLOR_PAIR(3));
      else
	attron(COLOR_PAIR(2) | A_BOLD);
      mvprintw(LINES / 2 - 7 + j, COLS / 2 -
	       my_strlen(names[j]) / 2, names[j]);
      attron(COLOR_PAIR(1) | A_BOLD);
      j = j + 1;
    }
}

int		receive_keys(int i, int a, char **names)
{
  if (i == KEY_DOWN)
    a = a + 1;
  if (i == KEY_UP)
    a = a - 1;
  if (names[a] == NULL)
    a = 0;
  if (a < 0)
    a = my_tablenc(names) - 1;
  refresh();
  if (i == 'x' || i == 'X')
    a = (-1);
  return (a);
}

char		*menu_loop(char **names)
{
  int		i;
  int		a;

  a = 0;
  while (a != (-1))
    {
      clear();
      menu_lines();
      if (names == NULL)
	break;
      names_print(names);
      attron(COLOR_PAIR(5) | A_BOLD);
      mvprintw(LINES / 2 - 7 + a, COLS / 2 -
		my_strlen(names[a]) / 2 - 3, "->");
      i = getch();
      a = receive_keys(i, a, names);
      if (i == 10)
	return (names[a]);
      if (i == 'e' || i == 'E')
	return (editor());
      refresh();
      if (i == 'x' || i == 'X')
	break;
    }
  endwin();
  if (names != NULL)
    free_tabc(names);
  return (NULL);
}

char		*menu()
{
  char		**names;
  char		*file;
  char		*dup;

  if ((names = display_files(opendir("."))) == NULL)
    {
      my_printf("\n%sNo files found in current repository\n\n%s",
		BOLDRED, RESET);
      return (NULL);
    }
  initscr();
  clear();
  curs_set(0);
  start_color();
  pairs();
  keypad(stdscr, TRUE);
  dup = menu_loop(names);
  if (dup != NULL)
    file = my_strdup(dup);
  else
    file = NULL;
  if (file != NULL)
    free_tabc(names);
  return (file);
}
