/*
** font.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Jan 15 17:59:04 2017 Léandre Blanchard
** Last update Sun Jan 15 19:06:48 2017 Léandre Blanchard
*/

#include "include/wolf.h"

void		put_word(char *word, sfVector2f pos, t_win *window)
{
  sfFont	*font;
  sfText	*text;

  font = sfFont_createFromFile("font.ttf");
  text = sfText_create();
  sfText_setString(text, word);
  sfText_setFont(text, font);
  sfText_setCharacterSize(text, 30);
  sfText_setPosition(text, pos);
  sfRenderWindow_drawText(window->window, text, NULL);
  sfRenderWindow_display(window->window);
  sfText_destroy(text);
  sfFont_destroy(font);
}

char		*int_char(int nb)
{
  char		*word;
  int		i;

  if ((word = malloc(sizeof(char) * my_strleni(nb) + 1)) == NULL)
    return (NULL);
  i = 0;
  while (i != my_strleni(nb) + 1)
    {
      word[i] = 0;
      i = i + 1;
    }
  i = 0;
  while (nb != 0)
    {
      word[i] = nb % 10 + 48;
      nb = nb / 10;
      i++;
    }
  my_revstr(word);
  return (word);
}
