/*
** files.c for wireframe in /home/lblanchard/C_graphical_prog/wireframe/bonus
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Fri Dec  9 20:45:05 2016 Leandre Blanchard
** Last update Thu Jan 19 08:09:57 2017 Léandre Blanchard
*/

#include "include/wolf.h"

void            free_tabc(char **tab)
{
  int           i;

  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
}

int		test_c(char *name)
{
  if (name[my_strlen(name) - 1] == 'c' || name[my_strlen(name) - 1] == 'o')
    if (name[my_strlen(name) - 2] == '.')
      return (1);
  if (name[0] == '.')
    return (1);
  return (0);
}

int		test_wf(char *name)
{
  if (my_strlen(name) < 4)
    return (1);
  if (name[my_strlen(name) - 1] == '3')
    if (name[my_strlen(name) - 2] == 'w')
      if (name[my_strlen(name) - 3] == '.')
	return (0);
  return (1);
}

char		**display_files(DIR *dir)
{
  struct dirent	*folder;
  char		**names;
  int		i;

  i = 0;
  if ((names = malloc(sizeof (char*) * 50)) == NULL)
    return (NULL);
  folder = readdir(dir);
  while ((folder = readdir(dir)) != NULL)
    {
      if (test_c(folder->d_name) == 0)
	{
	  names[i] = my_strdup(folder->d_name);
	  i = i + 1;
	}
    }
  names[i] = NULL;
  while (i < 0)
    {
      mvprintw(LINES / 2 - 8 - i, COLS / 2 -
	       my_strlen(names[i]) / 2, names[i]);
      i = i + 1;
    }
  closedir(dir);
  return (names);
}
