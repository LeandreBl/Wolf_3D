/*
** screen.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Jan 12 13:43:59 2017 Léandre Blanchard
** Last update Thu Jan 19 17:28:52 2017 Léandre Blanchard
*/

#include "include/wolf.h"

void		screen_size(t_win *window)
{
  if (sfKeyboard_isKeyPressed(sfKeyLAlt) && option == 1)
    {
      while (sfKeyboard_isKeyPressed(sfKeyLAlt));
      window->height += 240;
      if (window->height > 1080)
	window->height = 240;
      if (window->height == 240)
	window->fov = 50;
      if (window->height == 480)
	window->fov = 90;
      if (window->height == 720)
	window->fov = 90;
      window->width = window->height * 16 / 9;
      sfRenderWindow_close(window->window);
      init_window(window);
    }
  (window->fov > 360) ? window->fov = 360 : 0;
  (window->fov < 0) ? window->fov = 0 : 0;
}
