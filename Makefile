# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroard <maroard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/01 11:16:55 by maroard           #+#    #+#              #
#    Updated: 2026/02/02 17:41:48 by maroard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR			= ar rcs
NAME		= push_swap
NAME_BONUS	= checker
CC			= gcc
CFLAGS		= -I. -Wall -Wextra -Werror -g
RM			= rm -f

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC_DIR		= src
OBJ_DIR		= obj

ALL_SRC		= $(shell find $(SRC_DIR) -type f -name "*.c")

MAIN		= $(SRC_DIR)/push_swap.c
BONUS_MAIN	= $(SRC_DIR)/bonus/push_swap_bonus.c

SRC_COMMON	= $(filter-out $(MAIN) $(BONUS_MAIN), $(ALL_SRC))

SRC			= $(SRC_COMMON) $(MAIN)
SRC_BONUS	= $(SRC_COMMON) $(BONUS_MAIN)

OBJ			= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
OBJ_BONUS	= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_BONUS))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -lm -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(OBJ_BONUS) $(LIBFT) -lm -o $(NAME_BONUS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(NAME_BONUS)
	$(RM) -r $(OBJ_DIR)

re: fclean all

.PHONY: all bonus clean fclean re
