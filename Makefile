# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroard <maroard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/01 11:16:55 by maroard           #+#    #+#              #
#    Updated: 2025/12/01 15:10:20 by maroard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR          = ar rcs
NAME        = push_swap
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRC         = $(wildcard *.c)
OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(OBJ) libft/libft.a -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 