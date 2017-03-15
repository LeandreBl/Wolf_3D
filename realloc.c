/*
** realloc.c for realloc in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Dec 19 20:29:13 2016 Léandre Blanchard
** Last update Thu Jan 19 17:12:45 2017 Léandre Blanchard
*/

#include <stdlib.h>

int		my_strlen(char *);
char		*my_strcpy(char *, char *);

void		*my_realloc(void *str, int size)
{
  char		*rrealloc;

  rrealloc = malloc(sizeof(*str) * my_strlen(str) + size + 1);
  if (rrealloc == NULL)
    return (NULL);
  my_strcpy(rrealloc, str);
  return (rrealloc);
}
