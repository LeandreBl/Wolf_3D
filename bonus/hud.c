/*
** hud.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Jan 11 12:37:55 2017 Léandre Blanchard
** Last update Sun Jan 15 18:30:22 2017 Léandre Blanchard
*/

#include "include/wolf.h"

void			put_image(t_win *window, t_image image,
				  sfVector2i pos)
{
  int			i;
  int			j;
  sfColor		color;
  sfVector2f		coef;

  coef.x = (float)image.rsize.x / (float)image.size.x;
  coef.y = (float)image.rsize.y / (float)image.size.y;
  i = pos.y;
  while (i - pos.y != image.rsize.y / coef.y)
    {
      j = pos.x;
      while (j - pos.x != image.rsize.x / coef.x)
	{
	  color = sfImage_getPixel(image.image,
				   coef.x * (j - pos.x), coef.y * (i - pos.y));
	  if (color.a != 0)
	    my_put_pixel(window, j, i, color);
	  j++;
	}
      i++;
    }
}

void			options(t_map *map, t_win *window, t_pos pos)
{
  t_image		menu;

  menu.image = init_textures(1)[MENU];
  menu.size = xy_vectori(250, 250);
  menu.rsize = xy_vectori(250, 250);
  if (sfKeyboard_isKeyPressed(sfKeyO))
    {
      while (sfKeyboard_isKeyPressed(sfKeyO));
      option = (option == 1) ? 0 : 1;
    }
  if (option == 1)
    put_image(window, menu, xy_vectori(window->width / 2 - 125,
				       window->height / 2 - 125));
}

t_pos			hud(t_map *map, t_win *window, t_pos pos)
{
  t_image		hud;
  t_image		gun;
  float			i;

  hud.image = init_textures(1)[HUD];
  hud.rsize = xy_vectori(304, 35);
  hud.size = xy_vectori(window->width / 1.3, window->height / 10);
  put_image(window, hud, xy_vectori(window->width / 2 - hud.size.x / 2,
				    window->height - 10 - hud.size.y));
  if (sfKeyboard_isKeyPressed(sfKeySpace))
    pos.ammo = put_weapon(window, pos.ammo);
  if (pos.ammo < 0)
    pos.ammo = 0;
  options(map, window, pos);
  return (pos);
}

float			put_weapon(t_win *window, int ammo)
{
  t_image		gun;
  static float		a;

  if (a > 4)
    a = 0;
  if (ammo == 0)
    gun.image = init_weapons(1)[(int)a + 5];
  else
    gun.image = init_weapons(1)[(int)a];
  gun.rsize = xy_vectori(64, 64);
  gun.size = xy_vectori(200, 200);
  put_image(window, gun, xy_vectori(window->width / 2 - gun.size.x / 2,
				    window->height - 10 - window->height / 10 - gun.size.y));
  a = a + 0.25;
  if (a == 4)
    return (ammo - 1);
  return (ammo);
}
