/*
** wolf.h for wolf3d in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Dec 19 18:27:14 2016 Léandre Blanchard
** Last update Sun Jan 15 14:59:08 2017 Léandre Blanchard
*/

#include "my.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

#define INVALID_PATH NULL
#define MALLOC_ERROR NULL
#define READ_ERROR NULL
#define sqrt_2_3 0.81649658092
#define DIST_ 0.01

#define P my_printf("test\n");

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef	struct		s_map
{
  char			*file;
  int			lines;
  int			cols;
  int			**map;
  int			**map_64;
}			t_map;

typedef struct          s_vars
{
  int                   i;
  int                   j;
  int                   k;
}                       t_vars;

typedef struct          s_win
{
  int                   width;
  int                   height;
  sfRenderWindow        *window;
  sfSprite              *sprite;
  sfEvent               event;
  sfUint8               *pixels;
  sfTexture             *texture;
}                       t_win;

typedef	struct		s_xy
{
  int			x;
  int			y;
}			t_xy;

float			raycast(sfVector2f, float, int **, sfVector2i);

sfVector2f		move_f(sfVector2f, float, float);

int			map_to_tab_64(t_map *);

int			**my_tab_malloc_64(char *);

int			start(t_map *, t_win *);

void			free_map(t_map *);

void			free_tab(int **);

void			init_window(t_win *);

void			my_put_tab(int **);

int			nb_lines(char *);

int			line_len(char *);

int			map_to_tab(t_map *);

int			*my_str_malloc(char *);

int			**my_tab_malloc(char *);

sfColor			color_rgb(sfUint8, sfUint8, sfUint8);

char			*inputstring(char *, char *);

sfRenderWindow		*create_window(char *, int, int);

sfUint8			*pixels_buffer(int, int);

void                    my_put_pixel(t_my_framebuffer *, int, int, sfColor);

void                    my_draw_line(t_my_framebuffer *, sfVector2f,
				     sfVector2f, sfColor);

void                    x_lines(t_my_framebuffer *, sfVector2f, sfVector2f, sfColor);

void                    y_lines(t_my_framebuffer *, sfVector2f, sfVector2f, sfColor);

