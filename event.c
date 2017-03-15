/*
** event.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Jan  9 18:55:47 2017 Léandre Blanchard
** Last update Thu Jan 19 17:29:24 2017 Léandre Blanchard
*/

#include "include/wolf.h"

t_pos		events(t_map *map, t_win *window, t_pos pos)
{
  if (sfKeyboard_isKeyPressed(sfKeyEscape))
    sfRenderWindow_close(window->window);
  pos = move_events(map, pos);
  gui_event_handler(map, window, pos);
  if (sfKeyboard_isKeyPressed(sfKeyF3))
    {
      while (sfKeyboard_isKeyPressed(sfKeyF3));
      lights = (lights == 0) ? 1 : 0;
    }
  (sfKeyboard_isKeyPressed(sfKeyF2)) ? init_textures(3) : 0;
  if (sfKeyboard_isKeyPressed(sfKeyP))
    {
      window->fov += (sfKeyboard_isKeyPressed(sfKeyRShift)) ? 5 : -5;
      printf("%f\n", window->fov);
    }
  if (sfKeyboard_isKeyPressed(sfKeyM))
    {
      while (sfKeyboard_isKeyPressed(sfKeyM));
      theme = (theme == 0) ? 1 : 0;
      sounds(0);
    }
  if (sfKeyboard_isKeyPressed(sfKeyS))
    save_file(map);
  screen_size(window);
  return (pos);
}

void		gui_event_handler(t_map *map, t_win *window, t_pos pos)
{
  if (sfKeyboard_isKeyPressed(sfKeyF1) && option == 0)
    {
      while (sfKeyboard_isKeyPressed(sfKeyF1));
      walls_gui(window, 0);
    }
  if (sfKeyboard_isKeyPressed(sfKeyA) && walls_gui(window, 1) == 1)
    {
      while (sfKeyboard_isKeyPressed(sfKeyA));
      add_door(map, pos);
    }
  if (sfKeyboard_isKeyPressed(sfKeyE) && walls_gui(window, 1) == 1
      && option == 0)
    change_wall(map, pos, slot_nb(0));
  (sfKeyboard_isKeyPressed(sfKeyPageUp) && option == 0) ? slot_nb(-1) : 0;
  (sfKeyboard_isKeyPressed(sfKeyPageDown)&& option == 0) ? slot_nb(1) : 0;
  if (sfKeyboard_isKeyPressed(sfKeyF) && walls_gui(window, 1) == 1
      && option == 0)
    destroy_bloc(map, pos);
  if (sfKeyboard_isKeyPressed(sfKeyG) && walls_gui(window, 1) == 1
      && option == 0)
    create_bloc(map, pos);
}

void		destroy_bloc(t_map *map, t_pos pos)
{
  sfVector2f	ray;

  ray.x = pos.pos.x;
  ray.y = pos.pos.y;
  while (map->map[(int)ray.y][(int)ray.x] == '0')
    ray = move_forward(ray, pos.direction, DIST_);
  if (map->map[(int)ray.y][(int)ray.x] != '0')
    if ((int)ray.y != 0 && (int)ray.x != 0)
      if ((int)ray.y != map->lines - 1 && (int)ray.x != map->cols - 1)
	map->map[(int)ray.y][(int)ray.x] = '0';
  while (sfKeyboard_isKeyPressed(sfKeyF));
}

void		create_bloc(t_map *map, t_pos pos)
{
  sfVector2f	ray;
  sfVector2f	prev;

  ray.x = pos.pos.x;
  ray.y = pos.pos.y;
  while (map->map[(int)ray.y][(int)ray.x] == '0')
    {
      prev = ray;
      ray = move_forward(ray, pos.direction, DIST_);
    }
  if (map->map[(int)prev.y][(int)prev.x] == '0')
    {
      if ((int)prev.x == (int)pos.pos.x && (int)prev.y == (int)pos.pos.y)
	return;
      else
	map->map[(int)prev.y][(int)prev.x] = 49 + slot_nb(0);
    }
  while (sfKeyboard_isKeyPressed(sfKeyG));
}

t_vars		init_vars()
{
  t_vars	v;

  v.i = 0;
  v.j = 0;
  v.k = 0;
  return (v);
}
