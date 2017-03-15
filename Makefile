##
## Makefile for Makefile in /home/lblanchard/WireFrame
## 
## Made by Leandre Blanchard
## Login   <lblanchard@epitech.net>
## 
## Started on  Mon Nov 21 12:31:51 2016 Leandre Blanchard
## Last update Wed Mar  1 19:29:32 2017 Léandre Blanchard
##

NAME	= wolf_3d

CC	= gcc

LIB	= -L./lib -lmy -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio -lcsfml-network -lm -lncurses

SRCS	= main.c \
	  draw_line.c \
	  pixels.c \
	  realloc.c \
	  color.c \
	  str_ft.c \
	  map_to_tab.c \
	  mallocs.c \
	  display.c \
	  xy_fcts.c \
	  raycast.c \
	  add_color.c \
	  move.c \
	  menu.c \
	  files.c \
	  print.c \
	  editor.c \
	  event.c \
	  editor_parsing.c \
	  init.c \
	  minimap.c \
	  texture.c \
	  hud.c \
	  music.c \
	  weapons.c \
	  screen.c \
	  save.c \
	  tab_ft.c \
	  font.c \
	  fire_at_anomaly.c

OBJ	= $(SRCS:.c=.o)

RM	= rm -f

CFLAGS	= -W -g3 -Werror -Wall -Wextra -I ./include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIB)
	@       tput setaf 2; cat include/signature; tput sgr0
	@	touch map.dat
clean:
	$(RM) $(OBJ)

fclean: clean
	rm map.dat
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
