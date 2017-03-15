/*
** save.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Jan 12 15:46:44 2017 Léandre Blanchard
** Last update Sun Jan 15 19:14:51 2017 Léandre Blanchard
*/

#include "include/wolf.h"

char			*my_strcati(char *dest, int *str)
{
  int			i;
  int			j;

  j = 0;
  i = my_strlen(dest);
  while (str[j] != 0)
    {
      dest[i] = str[j];
      i++;
      j++;
    }
  dest[i] = '\n';
  dest[i + 1] = '\0';
  return (dest);
}

char			*followed(t_map *map)
{
  char			*maper;
  int			i;

  i = 0;
  if ((maper = malloc(map->lines * (map->cols + 1) + 1)) == NULL)
    return (NULL);
  while (map->map[i] != NULL)
    {
      maper = my_strcati(maper, map->map[i]);
      i++;
    }
  return (maper);
}

void			save_file(t_map *map)
{
  FILE			*fileptr;
  char			maper[map->lines * (map->cols + 1) + 1];
  int			i;
  char			*trunc;
  int			j;

  while (sfKeyboard_isKeyPressed(sfKeyS));
  trunc = followed(map);
  i = 0;
  j = 0;
  while (trunc[i] != '\0' || j == map->lines * (map->cols + 1))
    {
      if ((trunc[i] >= '0' && trunc[i] <= '9')
	  || trunc[i] == 'D' || trunc[i] == '\n' || trunc[i] == 0)
	{
	  maper[j++] = trunc[i];
	  maper[j] = 0;
	}
      i++;
    }
  fileptr = fopen("custom_map.w3", "wb+");
  fwrite(&maper, sizeof(char), my_strlen(map->file), fileptr);
  fclose(fileptr);
  my_printf("%s%s\n%s", BOLDGREEN, "file saved !", RESET);
  free(trunc);
}
