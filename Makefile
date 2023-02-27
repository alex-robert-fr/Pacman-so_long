NAME		=	so_long
CC		=	clang
LIB_PATH	=	lib/
SRC		=	main.c
MAP_SRC		=	./map/map.c 
ENGINE_SRC	=	./engine/vector.c
LIBFT_PATH	=	$(LIB_PATH)libft
LIBFT_NAME	=	libft.a
GNL_PATH	=	$(LIB_PATH)get_next_line/
GNL_SRC		=	$(GNL_PATH)get_next_line.c \
			$(GNL_PATH)get_next_line_utils.c

all: $(LIBFT_NAME) $(NAME)

$(NAME):
	$(CC) -I$(LIB_PATH)minilibx-linux/ $(SRC) $(WIN_SRC) $(MAP_SRC) $(ENGINE_SRC) $(GNL_SRC) -L$(LIB_PATH)minilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 $(LIBFT_PATH)/$(LIBFT_NAME) -o $(NAME) -g
	
$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm $(NAME)

re: fclean all

run: all
	./$(NAME)
