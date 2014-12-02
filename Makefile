##
## Makefile for pure plaisir :p in /home/labadi_g/snake-console
##
## Made by Gautier Labadie
## Login   <labadi_g@epitech.eu>
##
## Started on  lun. déc. 01 23:29:06 14 Gautier Labadie
## Last Update lun. déc. 01 23:29:06 14 Gautier Labadie
##

NAME		=	bin/snake-console

SRC		=	src/main.c \
			src/menu.c \
			src/my_str.c

OBJ		=	$(SRC:src/%.c=build/%.o)

CFLAGS		+=	-Wall -Wextra -Iinclude

$(NAME)		:	$(OBJ)
			mkdir -pv bin
			cc -o $(NAME) $(OBJ)

build/%.o	:	src/%.c
			cc -c $(CFLAGS) -o $@ $<

all		:	$(NAME)

clean		:
			rm -f $(OBJ)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
