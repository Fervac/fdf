# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/09 16:57:49 by gjuste            #+#    #+#              #
#    Updated: 2019/01/29 14:56:07 by gjuste           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Werror -Wextra -Wall
CCLIB = make -C libft/
SRC =	main.c			\
		fdf.c			\
		rotation.c		\
		parse.c			\
		get_input.c		\
		print_line.c	\
		image.c			\
		set_exit.c

OBJ = $(SRC:.c=.o)
HEADER = fdf.h
NAME = fdf

all: $(NAME) Makefile

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -I $(HEADER) -L libft/ -lft -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CCLIB)
	$(CC) $(FLAGS) -o $@ -c $< -I $(HEADER)

clean:
	$(CCLIB) clean
	rm -f $(OBJ)

fclean: clean
	$(CCLIB) fclean
	rm -f $(NAME)

re: fclean all
