# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroard <maroard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/02 21:13:43 by maroard           #+#    #+#              #
#    Updated: 2026/02/01 18:17:10 by maroard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR      = ar rcs
NAME    = libft.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES_ALL   = $(shell find $(SRC_DIR) -type f -name "*.c")
SRC_FILES_BONUS = $(shell find $(SRC_DIR) -type f -name "*_bonus.c")
SRC_FILES       = $(filter-out $(SRC_FILES_BONUS), $(SRC_FILES_ALL))

OBJ_FILES       = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
OBJ_FILES_BONUS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES_BONUS))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) $(NAME) $(OBJ_FILES)

bonus: $(OBJ_FILES_BONUS)
	$(AR) $(NAME) $(OBJ_FILES_BONUS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_FILES) $(OBJ_FILES_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
