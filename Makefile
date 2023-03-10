NAME		=	so_long
CC		=	gcc
LIB_PATH	=	lib/
SRC		=	main.c
MAP_SRC		=	./map/check_map.c \
				./map/generate_map.c
ENGINE_SRC	=	./engine/vector.c \
				./engine/images.c \
				./engine/time.c
WIN_SRC		=	./window/window.c
ENTITY_SRC	=	./entities/entity.c
LIBFT_PATH	=	$(LIB_PATH)libft
LIBFT_NAME	=	libft.a
MLX_PATH	=	$(LIB_PATH)minilibx-linux
MLX_NAME	=	mlx_Linux
GNL_PATH	=	$(LIB_PATH)get_next_line/
GNL_SRC		=	$(GNL_PATH)get_next_line.c \
			$(GNL_PATH)get_next_line_utils.c

all: $(LIBFT_NAME) $(NAME) #$(MLX_NAME)

$(NAME):
	$(CC) -g -I$(LIB_PATH)minilibx-linux/ $(SRC) $(WIN_SRC) $(MAP_SRC) $(ENTITY_SRC) $(ENGINE_SRC) $(GNL_SRC) -L$(LIB_PATH)minilibx-linux -l$(MLX_NAME) -L/usr/lib -lXext -lX11 $(LIBFT_PATH)/$(LIBFT_NAME) -o $(NAME) #-Wextra -Wall -Werror
	
$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

$(MLX_NAME):
	make -C $(MLX_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	#make clean -C $(MLX_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm $(NAME)

re: fclean all

run: all
	./$(NAME)
