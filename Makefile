# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroard <maroard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/01 11:16:55 by maroard           #+#    #+#              #
#    Updated: 2025/12/11 11:01:30 by maroard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR			= ar rcs
NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC_DIR		= src
OBJ_DIR		= obj

SRC_FILES	= $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES	= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(OBJ_FILES) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ_FILES)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)
	$(RM) -r $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re