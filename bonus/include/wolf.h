
/*
** wolf.h for wolf3d in /home/leandre/C_graphical_prog/Wolf3d
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Dec 19 18:27:14 2016 Léandre Blanchard
** Last update Sun Jan 15 19:07:37 2017 Léandre Blanchard
*/

#ifndef WOLF_H
# define WOLF_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Sprite.h>
# include <SFML/Graphics/Texture.h>
# include <SFML/Graphics/Export.h>
# include <SFML/Graphics/Rect.h>
# include <SFML/Graphics/Types.h>
# include <SFML/System/InputStream.h>
# include <SFML/System/Vector2.h>
# include <SFML/Window/Joystick.h>
# include <SFML/Window/Keyboard.h>
# include <SFML/Window/Mouse.h>
# include <SFML/Window/Sensor.h>
# include <SFML/Graphics/Color.h>
# include <SFML/Graphics/Transform.h>
# include <stddef.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <termios.h>
# include <curses.h>
# include <dirent.h>
# include <SFML/Audio/Export.h>
# include <SFML/Audio/SoundStatus.h>
# include <SFML/Audio/Types.h>
# include <SFML/System/Time.h>
# include <SFML/System/Vector3.h>
# include <SFML/Graphics/Font.h>
# include <SFML/Graphics/Text.h>

# include "my.h"
# include "colors.h"

# define INVALID_PATH NULL
# define MALLOC_ERROR NULL
# define READ_ERROR NULL
# define sqrt_2_3 0.81649658092
# define DIST_ 0.01
# define P my_printf("%stest\n%s", BOLDGREEN, RESET);
# define MOVEX 0.15 * cos(M_PI / 180.0 * pos.direction)
# define MOVEY 0.15 * sin(M_PI / 180.0 * pos.direction)
# define DIST_C (dist.dist + 1)
# define STONE 0
# define COBBLESTONE 1
# define BRICK 2
# define BOOK 3
# define OAK 4
# define WOOD 5
# define DIRT 6
# define MENU 7
# define DOOR 8
# define HUD 9
# define RD random()

# define ABS(Value)      (((Value) < (0)) ? (-Value) : (Value))

typedef struct		s_image
{
  sfVector2i		size;
  sfVector2i		rsize;
  sfImage		*image;
}			t_image;

typedef struct		s_rot
{
  sfVector2i		pos;
  float			angle;
}			t_rot;

typedef struct		s_dist
{
  float			dist;
  sfColor		color;
  int			texture;
  int			change;
  float			x;
}			t_dist;

typedef	struct		s_map
{
  char			*file;
  int			lines;
  int			cols;
  int			**map;
  sfVector2i	       	*ennemies;
  sfImage		*guard;
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
  float			fov;
  float			dist_proj;
}                       t_win;

typedef	struct		s_xy
{
  int			x;
  int			y;
}			t_xy;

typedef	struct		s_pos
{
  float			direction;
  sfVector2f		pos;
  int			ammo;
}			t_pos;

int			texture_size;

int			lights;

int			option;

sfMusic			*music;

int			theme;

void			free_tabc(char **);

char			*int_char(int);

void			put_word(char *, sfVector2f, t_win *);

int			my_strleni(int);

void			put_tab_int(int **);

void			put_image(t_win *, t_image, sfVector2i);

void			put_guard(t_map *, t_win *, float, int);

float			shot_cast(sfVector2f, float, int **, sfVector2i);

void			add_ennemies(t_map *);

void			mpos_ennemies(int **);

int			**my_tab_dup(t_map *);

float			put_weapon(t_win *, int);

void			save_file(t_map *);

void			screen_size(t_win *, t_map *);

void			sfMusic_stop(sfMusic *);

void			sfMusic_play(sfMusic *);

void			sfMusic_setLoop(sfMusic *, sfBool);

sfImage			**init_weapons(int);

sfImage			**weapons(sfImage **);

void			sfMusic_destroy(sfMusic *);

void			sounds(int);

t_pos			hud(t_map *, t_win *, t_pos);

void			gui_event_handler(t_map *, t_win *, t_pos);

sfImage			**low_quality(sfImage **);

sfImage			**high_quality(sfImage **);

sfImage			**wolf_qualitad(sfImage **);

void			sfImage_destroy(sfImage *);

void			free_textures(sfImage **);

void			put_square(t_win *, t_rot, int, sfColor);

void			minimap(t_map *, t_win *, t_pos);

void			draw_circle(t_win *, sfVector2f, int, sfColor);

void			draw_cube(t_win *, int);

sfImage			**init_textures(int);

sfMusic			*sfMusic_createFromFile(const char *);

sfImage			*sfImage_createFromFile(const char *);

sfColor			sfImage_getPixel(sfImage *, int, int);

void			draw_arrow(int);

t_pos			move_events(t_map *, t_win *, t_pos);

void			repair_walls(t_map *);

void			destroy_bloc(t_map *, t_win *, t_pos);

void			create_bloc(t_map *, t_win *, t_pos);

void			wolf_name();

int			my_tablen(int **);

int			my_tablenc(char **);

char			*editor();

t_pos			events(t_map *, t_win *, t_pos);

t_pos			mv_up(t_pos, t_map *);

int			init_win(t_win *);

t_pos			mv_down(t_pos, t_map *);

char			*calloc_tab(char *, char **, int);

char			*menu();

void			menu_lines();

int			test_wf(char *);

char			**display_files(DIR *);

int			antialiasing(t_win *, int);

t_pos			movex(t_map *, t_win *, t_pos);

void			empty_square(t_win *, int, int, sfColor);

int			slot_nb(int);

t_dist			color_finder(int **, sfVector2f, sfColor *, t_dist);

sfColor			*fill_colors();

int			add_door(t_map *, t_win *, t_pos);

int			walls_gui_cols(t_win *, int);

int			walls_gui_lines(t_win *, int, int);

void			my_draw_square(t_win *, sfVector2i, int, sfColor);

int			visor(t_win *);

int			walls_gui(t_map *, t_win *, int, int);

int			change_wall(t_map *, t_pos, int);

void		        draw_column(t_win *, sfVector2f, int, t_dist);

void			clear_pixel_buffer(sfUint8 *, t_pos, t_win *);

sfVector2f		get_pos(int **);

sfVector2f		move_forward(sfVector2f, float, float);

sfVector2f		xy_vector(int, int);

sfVector2i		xy_vectori(int, int);

t_pos			walls(t_win *, t_map *, t_pos);

int			*my_str_malloc_64(char *);

int			map_to_tab_64(t_map *);

int			**my_tab_malloc_64(char *);

int			start(t_map *, t_win *);

int			screen_loop(t_map *, t_win *, t_pos);

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

sfColor			color_rgba(sfUint8, sfUint8, sfUint8, sfUint8);

char			*inputstring(char *, char *);

sfRenderWindow		*create_window(char *, int, int);

sfUint8			*pixels_buffer(int, int);

void                    my_put_pixel(t_win *, int, int, sfColor);

void                    draw_line(t_win *, sfVector2f,
				     sfVector2f, sfColor);

void                    x_lines(sfUint8 *, sfVector2f, sfVector2f, sfColor);

void                    x_lines(sfUint8 *, sfVector2f, sfVector2f, sfColor);

void                    y_lines(sfUint8 *, sfVector2f, sfVector2f, sfColor);

#endif /* !WOLF_H */
