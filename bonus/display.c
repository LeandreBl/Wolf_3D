/*
** display.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Dec 21 16:33:39 2016 Léandre Blanchard
** Last update Sun Jan 15 19:35:42 2017 Léandre Blanchard
*/

#include "include/wolf.h"

int			destroy_window(t_win *window)
{
  sfRenderWindow_destroy(window->window);
  sfTexture_destroy(window->texture);
  sfSprite_destroy(window->sprite);
  free(window);
  return (0);
}

int			start(t_map *map, t_win *window)
{
  t_pos			pos;

  map->guard = sfImage_createFromFile("sprites/guard.png");
  add_ennemies(map);
  pos.pos = get_pos(map->map);
  pos.direction = 50;
  pos.ammo = 20;
  init_window(window);
  screen_loop(map, window, pos);
  free(window->pixels);
  destroy_window(window);
  init_textures(2);
  init_weapons(2);
  return (0);
}

int			screen_loop(t_map *map, t_win *window,
				    t_pos pos)
{
  char			*ammo;

  while (sfRenderWindow_isOpen(window->window))
    {
      pos = events(map, window, pos);
      sfRenderWindow_clear(window->window, color_rgb(200, 150, 255));
      sfTexture_updateFromPixels(window->texture,
				 window->pixels, window->width, window->height, 0, 0);
      sfRenderWindow_drawSprite(window->window, window->sprite, NULL);
      ammo = int_char(pos.ammo);
      put_word(ammo, xy_vector(window->width - window->width / 1.3 / 2 + 24,
				   window->height - window->height / 10 + 5), window);
      free(ammo);
      sfRenderWindow_display(window->window);
      clear_pixel_buffer(window->pixels, pos, window);
      walls(window, map, pos);
      visor(window);
      walls_gui(map, window, 1, 1);
      minimap(map, window, pos);
      pos = hud(map, window, pos);
      sounds(1);
    }
  return (0);
}

void			clear_pixel_down(t_win *window, int y)
{
  int			x;

  while (y != window->height)
    {
      x = 0;
      while (x != window->width)
	{
	  my_put_pixel(window, x, y, color_rgb(53, 53, 53));
	  x = x + 1;
	}
      y = y + 1;
    }
}

void			clear_pixel_buffer(sfUint8 *pixels, t_pos pos, t_win *window)
{
  sfVector2i		xy;
  sfImage		*image;

  image = init_textures(1)[DIRT];
  xy.y = 0;
  while (xy.y != window->height / 2)
    {
      xy.x = 0;
      while (xy.x != window->width)
	{
	  if (lights == 1)
	    my_put_pixel(window, xy.x, xy.y, sfBlack);
	  else
	    my_put_pixel(window, xy.x, xy.y,
			 color_rgb(pos.pos.x * 10, pos.pos.y * 15, 160));
	  xy.x = xy.x + 1;
	}
      xy.y = xy.y + 1;
    }
  clear_pixel_down(window, xy.y);
}
