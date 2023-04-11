NAME		=	libft.a
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -Iothers -g
LIBFT_PATH	=	./others/
LIBFT_NAME	=	others.a
SRC			=	./ft_printf/ft_printf.c				\
				./ft_printf/type_management.c		\
				./ft_printf/convert_management.c	\
				./ft_printf/check_management.c		\
				./ft_printf/str_convert_manager.c	\
				./ft_printf/num_convert_manager.c	\
				./ft_printf/create_struct.c			\
				./ft_printf/ft_puthexa.c			\
				./get_next_line/get_next_line.c		\
				./get_next_line/get_next_line_utils.c
NO_BONUS	=	./ft_printf/flag_management.c		\
				./ft_printf/margin_management.c
BONUS		=	./ft_printf/flag_management_bonus.c	\
				./ft_printf/margin_management_bonus.c
OBJ			=	$(SRC:.c=.o)
NB_OBJ		=	$(NO_BONUS:.c=.o)
B_OBJ		=	$(BONUS:.c=.o)

all: $(LIBFT_NAME) $(NAME)

$(NAME): $(OBJ) $(NB_OBJ)
	ar rcsT $(NAME) $(OBJ) $(NB_OBJ) $(LIBFT_PATH)$(LIBFT_NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJ) $(NB_OBJ) $(B_OBJ)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

bonus: fclean $(LIBFT_NAME) b 

b: $(OBJ) $(B_OBJ)
	ar rcsT $(NAME) $(OBJ) $(B_OBJ) $(LIBFT_PATH)$(LIBFT_NAME)

.PHONY:
	all clear fclean re bonus
