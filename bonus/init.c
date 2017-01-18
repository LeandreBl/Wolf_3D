/*
** init.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Jan 10 12:52:16 2017 Léandre Blanchard
** Last update Wed Jan 11 14:18:43 2017 Léandre Blanchard
*/

#include "include/wolf.h"

int		init_win(t_win *window)
{
  window->fov = 90.0;
  window->height = 480;
  window->width = window->height * 16 / 9;
  window->dist_proj = window->width / 2 *
    tan(30 * M_PI / (180 - window->fov * 2 / 3));
  lights = 1;
  texture_size = 64;
  init_textures(3);
  init_weapons(3);
  option = 0;
  theme = 0;
}

sfImage		**low_quality(sfImage **images)
{
  texture_size = 32;
  images[0] = sfImage_createFromFile("sprites/normal/stone.png");
  images[1] = sfImage_createFromFile("sprites/normal/cobblestone.png");
  images[2] = sfImage_createFromFile("sprites/normal/brick.png");
  images[3] = sfImage_createFromFile("sprites/normal/bookshelf.png");
  images[4] = sfImage_createFromFile("sprites/normal/log_oak.png");
  images[5] = sfImage_createFromFile("sprites/normal/wood.png");
  images[6] = sfImage_createFromFile("sprites/normal/dirt.png");
  images[7] = sfImage_createFromFile("sprites/normal/menu.png");
  images[8] = sfImage_createFromFile("sprites/normal/door.png");
  images[9] = sfImage_createFromFile("sprites/normal/hud.png");
  images[10] = NULL;
  if (theme == 1)
    sfMusic_stop(music);
  music = sfMusic_createFromFile("music/minecraft/base.ogg");
  sounds(0);
  return (images);
}

sfImage		**high_quality(sfImage **images)
{
  texture_size = 512;
  images[0] = sfImage_createFromFile("sprites/R3D/stone.png");
  images[1] = sfImage_createFromFile("sprites/R3D/cobblestone.png");
  images[2] = sfImage_createFromFile("sprites/R3D/brick.png");
  images[3] = sfImage_createFromFile("sprites/R3D/bookshelf.png");
  images[4] = sfImage_createFromFile("sprites/R3D/log_oak.png");
  images[5] = sfImage_createFromFile("sprites/R3D/wood.png");
  images[6] = sfImage_createFromFile("sprites/R3D/dirt.png");
  images[7] = sfImage_createFromFile("sprites/R3D/menu.png");
  images[8] = sfImage_createFromFile("sprites/R3D/door.png");
  images[9] = sfImage_createFromFile("sprites/normal/hud.png");
  images[10] = NULL;
  return (images);
}

sfImage		**wolf_qualitad(sfImage **images)
{
  texture_size = 64;
  images[0] = sfImage_createFromFile("sprites/wolf/stone.png");
  images[1] = sfImage_createFromFile("sprites/wolf/cobblestone.png");
  images[2] = sfImage_createFromFile("sprites/wolf/brick.png");
  images[3] = sfImage_createFromFile("sprites/wolf/bookshelf.png");
  images[4] = sfImage_createFromFile("sprites/wolf/log_oak.png");
  images[5] = sfImage_createFromFile("sprites/wolf/wood.png");
  images[6] = sfImage_createFromFile("sprites/wolf/dirt.png");
  images[7] = sfImage_createFromFile("sprites/wolf/menu.png");
  images[8] = sfImage_createFromFile("sprites/wolf/door.png");
  images[9] = sfImage_createFromFile("sprites/normal/hud.png");
  images[10] = NULL;
  sfMusic_stop(music);
  music = sfMusic_createFromFile("music/wolf/ambiance.ogg");
  sounds(0);
  return (images);
}
