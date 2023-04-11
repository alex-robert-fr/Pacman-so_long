# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alrobert <alrobert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 14:23:23 by alrobert          #+#    #+#              #
#    Updated: 2022/11/10 17:14:53 by alrobert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	others.a
CC			=	clang
SRC			=	ft_atoi.c \
				ft_isdigit.c \
				ft_memcpy.c \
				ft_putstr_fd.c \
				ft_strjoin.c \
				ft_strnstr.c \
				ft_bzero.c \
				ft_isprint.c \
				ft_memmove.c \
				ft_strlcat.c \
				ft_strrchr.c \
				ft_calloc.c \
				ft_itoa.c \
				ft_nblen.c \
				ft_memset.c \
				ft_split.c \
				ft_strlcpy.c \
				ft_strtrim.c \
				ft_isalnum.c \
				ft_putchar_fd.c \
				ft_strchr.c \
				ft_strlen.c \
				ft_substr.c \
				ft_isalpha.c \
				ft_memchr.c \
				ft_putendl_fd.c \
				ft_strdup.c \
				ft_strmapi.c \
				ft_tolower.c \
				ft_isascii.c \
				ft_memcmp.c \
				ft_putnbr_fd.c \
				ft_striteri.c \
				ft_strncmp.c \
				ft_memlen.c \
				ft_toupper.c \
				ft_int_to_binary.c \
				ft_binary_to_int.c
BONUS		=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c
CFLAGS		=	-Wall -Wextra -Werror
OBJ			=	$(SRC:.c=.o)
OBJ_BONUS	=	$(BONUS:.c=.o)


$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

all: $(NAME)

.PHONY:
	all clear fclean re bonus
