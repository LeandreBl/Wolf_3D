/*
** draw_line.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Dec 19 18:35:33 2016 Léandre Blanchard
** Last update Sat Jan  7 20:32:14 2017 Léandre Blanchard
*/

#include "wolf.h"

void            x_lines(t_my_framebuffer *pixels, sfVector2f
			from, sfVector2f to, sfColor color)
{
  float         b;
  float         a;
  int           x;
  int           y;

  if (from.x >= to.x)
    x = to.x;
  else
    x = from.x;
  y = from.y;
  a = (to.y - from.y) / (to.x - from.x);
  b = from.y - (a * from.x);
  while ((x < to.x || x < from.x) && (to.x != from.x) && x < pixels->width && x > 0)
    {
      y = (a * x + b) / 1;
      (y >= 0 && y <= pixels->height) ? my_put_pixel(pixels, x, y, color) : 0;
      x = x + 1;
    }
  y = from.y;
  while ((to.x == from.x) && (y != to.y) && y >= 0)
    {
      (y >= 0 && y <= pixels->height) ? my_put_pixel(pixels, x, y, color) : 0;
      y = y + 1;
    }
}

void            y_lines(t_my_framebuffer *pixels, sfVector2f
			from, sfVector2f to, sfColor color)
{
  float         b;
  float         a;
  int           x;
  int           y;

  if (from.y >= to.y)
    y = to.y;
  else
    y = from.y;
  x = from.x;
  a = (to.x - from.x) / (to.y - from.y);
  b = from.x - a * from.y;
  while ((y < to.y || y < from.y) && (to.y != from.y) && x < pixels->width && x > 0)
    {
      x = (a * y + b) / 1;
      (y >= 0 && y <= pixels->height) ? my_put_pixel(pixels, x, y, color) : 0;
      y = y + 1;
    }
  while ((to.y == from.y) && (x != to.x))
    {
      (y >= 0 && y <= pixels->height) ? my_put_pixel(pixels, x, y, color) : 0;
      y = (y >= to.x) ? y - 1 : y + 1;
    }
}

void            my_draw_line(t_my_framebuffer *pixels, sfVector2f
			     from, sfVector2f to, sfColor color)
{
  float         a;
  sfVector2f    swap;

  if (from.y >= to.y)
    {
      swap = to;
      to = from;
      from = swap;
    }
  a = (to.x - from.x) / (to.y - from.y);
  if (a < (-1) || a > (1))
    x_lines(pixels, from, to, color);
  else
    y_lines(pixels, from, to, color);
}
