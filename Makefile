# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 18:58:58 by gpatrici          #+#    #+#              #
#    Updated: 2025/12/09 16:31:37 by gpatrici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	$(wildcard srcs/*.c) $(wildcard srcs/ft_printf/*.c)
OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re