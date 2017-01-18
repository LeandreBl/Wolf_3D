/*
** weapons.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Jan 11 14:07:09 2017 Léandre Blanchard
** Last update Fri Jan 13 21:24:34 2017 Léandre Blanchard
*/

#include "include/wolf.h"

sfImage			**init_weapons(int a)
{
  static sfImage	**images;

  if (a == 1)
    return (images);
  if (a == 2)
    {
      free_textures(images);
      return (NULL);
    }
  if ((images = malloc(sizeof(sfImage *) * 11)) == NULL)
    return (NULL);
  if (a == 3)
    images = weapons(images);
}

sfImage			**weapons(sfImage **images)
{
  images[0] = sfImage_createFromFile("sprites/pistol/pistol0.png");
  images[1] = sfImage_createFromFile("sprites/pistol/pistol1.png");
  images[2] = sfImage_createFromFile("sprites/pistol/pistol2.png");
  images[3] = sfImage_createFromFile("sprites/pistol/pistol3.png");
  images[4] = sfImage_createFromFile("sprites/pistol/pistol4.png");
  images[5] = sfImage_createFromFile("sprites/cut/cut0.png");
  images[6] = sfImage_createFromFile("sprites/cut/cut1.png");
  images[7] = sfImage_createFromFile("sprites/cut/cut2.png");
  images[8] = sfImage_createFromFile("sprites/cut/cut3.png");
  images[9] = sfImage_createFromFile("sprites/cut/cut4.png");
  images[10] = NULL;
  return (images);
}

void			add_ennemies(t_map *map)
{
  if ((map->ennemies = malloc(sizeof(sfVector2i) *
			      (map->lines * map->cols + 1))) == NULL)
    return;
  map->ennemies[0] = xy_vectori(7, 4);
  map->ennemies[1] = xy_vectori(4, 4);
}

void			put_guard(t_map *map, t_win *window, float dist, int x)
{
  t_image		image;
  float			guard_h;

  guard_h = window->dist_proj / dist;
  image.image = map->guard;
  image.rsize = xy_vectori(64, 64);
  image.size = xy_vectori(guard_h, guard_h);
  put_image(window, image, xy_vectori(x, window->height / 2 - guard_h));
}
