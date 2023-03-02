CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address
NAME	=	cub3D
SRC		=	utils/render.c utils/utils.c  parse_mapv2.c parse_rgb2.c parse_texture2.c find_elements.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c check_arg2.c main.c 
LIBFT	=	libft/libft.a
OBG		=	$(SRC:.c=.o)	

all	:	$(NAME)

$(NAME)	:	$(OBG)
			$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit  $(OBG) $(LIBFT) -o $(NAME)
clean:
	rm -rf $(OBG)
fclean:	clean
	rm -rf $(NAME)