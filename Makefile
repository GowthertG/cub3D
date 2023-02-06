CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g
NAME	=	cub3D
SRC		=	utils/render.c utils/utils.c
LIBFT	=	libft/libft.a
OBG		=	$(SRC:.c=.o)	

all	:	$(NAME)

$(NAME)	:	$(OBG)
			$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit main.c $(OBG) $(LIBFT) -o $(NAME)
clean:
	rm -rf $(OBG)
fclean:	clean
	rm -rf $(NAME)