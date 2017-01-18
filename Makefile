##
## Makefile for Makefile in /home/lblanchard/WireFrame
## 
## Made by Leandre Blanchard
## Login   <lblanchard@epitech.net>
## 
## Started on  Mon Nov 21 12:31:51 2016 Leandre Blanchard
## Last update Sun Jan 15 14:47:12 2017 Léandre Blanchard
##

NAME	= wolf_3d

CC	= gcc

LIB	= -L./lib -lmy -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio -lcsfml-network -lm -lncurses

SRCS	= main.c \

OBJ	= $(SRCS:.c=.o)

RM	= rm -f

FLAGS	= -W -g3 -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(LIB)
	@       tput setaf 2; cat include/signature; tput sgr0
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
