# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 10:20:20 by gpatrici          #+#    #+#              #
#    Updated: 2025/12/16 14:23:08 by gpatrici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src
LIBFT_DIR = $(SRC_DIR)/libft
PRINTF_DIR = $(SRC_DIR)/printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRC = $(SRC_DIR)/push_swap.c \
      $(SRC_DIR)/parsing.c \
      $(SRC_DIR)/parsing_utils.c \
      $(SRC_DIR)/parsing_convert.c \
      $(SRC_DIR)/stack_handling.c \
      $(SRC_DIR)/stack_creation.c \
      $(SRC_DIR)/stack_utils.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
