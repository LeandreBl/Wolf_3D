/*
** main.c for wolf3d in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Dec 19 18:26:49 2016 Léandre Blanchard
** Last update Wed Mar  1 19:31:40 2017 Léandre Blanchard
*/

#include "include/wolf.h"

void			free_map(t_map *map)
{
  if (map->file != NULL)
    free(map->file);
  if (map->file != NULL)
    free_tab(map->map);
  theme = 0;
  sounds(0);
  sfMusic_destroy(music);
  free(map->ennemies);
  sfImage_destroy(map->guard);
  free(map);
}

void			init_window(t_win *window)
{
  window->window = create_window("Wolf_3D", window->width, window->height);
  window->sprite = sfSprite_create();
  window->texture = sfTexture_create(window->width, window->height);
  sfSprite_setTexture(window->sprite, window->texture, sfTrue);
  window->pixels = pixels_buffer(window->width, window->height);
}

int			map_test(char *input)
{
  int			i;

  i = 0;
  while (input[i] != '\0')
    {
      if (input[i] < '0' && input[i] != '\n')
	return (1);
      if (input[i] > '9' && input[i] < 'A')
	return (1);
      if (input[i] > 'Z' && input[i] < 'a')
	return (1);
      i = i + 1;
    }
  return (0);
}

char                    *file_test(char *input)
{
  int                   size;
  int                   stream;
  char			*buffer;

  if (input == NULL || map_test(input) == 0)
    {
      endwin();
      (input == NULL) ? 0 : ERROR_FILE
      exit(84);
    }
  if ((stream = open(input, O_RDONLY)) == (-1))
    return (INVALID_PATH);
  if (stream == (-1))
    return (INVALID_PATH);
  if ((buffer = malloc(sizeof(char) * 16001)) == NULL)
    return (MALLOC_ERROR);
  size = read(stream, buffer, 16000);
  if (size == (-1))
    return (READ_ERROR);
  buffer[size] = '\0';
  close(stream);
  free(input);
  return (buffer);
}

int			main()
{
  t_map			*map;
  t_win			*window;

  if ((map = malloc(sizeof(t_map))) == NULL)
      return (84);
  if ((window = malloc(sizeof(t_win))) == NULL)
    return (84);
  if ((map->file = file_test(menu())) == NULL)
    return (84);
  endwin();
  map->lines = nb_lines(map->file);
  map->cols = line_len(map->file);
  window->map = map;
  init_win(window);
  map_to_tab(map);
  if (start(map, window) == 1)
    return (84);
  free_map(map);
  return (0);
}
