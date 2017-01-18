/*
** draw_line.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Dec 19 18:35:33 2016 Léandre Blanchard
** Last update Sat Jan  7 20:29:18 2017 Léandre Blanchard
*/

#include "wolf.h"

void    my_put_pixel(t_my_framebuffer *pixels, int x, int y, sfColor color)
{
  if (x < 0 || y < 0)
    return;
  if (x > pixels->width || y > pixels->height)
    return;
  pixels->pixels[(pixels->width * y + x) * 4 + 0] = color.r;
  pixels->pixels[(pixels->width * y + x) * 4 + 1] = color.g;
  pixels->pixels[(pixels->width * y + x) * 4 + 2] = color.b;
  pixels->pixels[(pixels->width * y + x) * 4 + 3] = color.a;
}
