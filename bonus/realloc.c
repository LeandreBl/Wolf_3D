/*
** realloc.c for realloc in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Dec 19 20:29:13 2016 Léandre Blanchard
** Last update Mon Dec 19 20:48:28 2016 Léandre Blanchard
*/

#include <stdlib.h>

int		my_strlen(char *);
char		*my_strcpy(char *, char *);

void		*my_realloc(void *str, int size)
{
  char		*realloc;

  realloc = malloc(sizeof(*str) * my_strlen(str) + size + 1);
  if (malloc == NULL)
    return (NULL);
  my_strcpy(realloc, str);
  return (realloc);
}
