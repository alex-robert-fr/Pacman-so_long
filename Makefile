NAME		=	so_long
CC			=	clang
SRC			=	main.c						\
				./engine/images.c			\
				./engine/keyboard.c			\
				./engine/time.c				\
				./engine/vector.c			\
				./map/check_map.c			\
				./map/generate_map.c		\
				./map/pac_gomme.c			\
				./entities/entity.c			\
				./entities/ia.c				\
				./entities/player.c			\
				./window/ui.c				\
				./window/window.c
LIBFT		=	lib/libft/others/
FT_PRINTF	=	lib/libft/ft_printf/
GNL			=	lib/libft/get_next_line/
MLX			=	lib/minilibx-linux/
LIBFT_NAME	=	libft.a
CFLAGS		=	-I$(LIBFT) -I$(FT_PRINTF) -I$(GNL) -I$(MLX) -Iincludes/

all: $(LIBFT_NAME) $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -Llib/minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm lib/libft/$(LIBFT_NAME) -o $(NAME) -g
	
$(LIBFT_NAME):
	make -C lib/libft

clean:
	make clean -C lib/libft

fclean: clean
	make fclean -C lib/libft
	rm -f $(NAME)

re: fclean all
