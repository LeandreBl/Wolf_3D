/*
** music.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Jan 11 13:23:52 2017 Léandre Blanchard
** Last update Wed Jan 11 13:48:09 2017 Léandre Blanchard
*/

#include "include/wolf.h"

void			sounds(int a)
{
  if (a == 0 && theme != 0)
    {
      sfMusic_play(music);
      sfMusic_setLoop(music, sfTrue);
    }
  if (theme == 0 && a == 0)
    {
      sfMusic_stop(music);
      sfMusic_setLoop(music, sfFalse);
    }
}
