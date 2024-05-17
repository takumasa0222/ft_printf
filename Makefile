# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 21:12:16 by tamatsuu          #+#    #+#              #
#    Updated: 2024/05/17 21:24:42 by tamatsuu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address
SRCS		=
OBJS		= $(SRCS:%.c=%.o)
NAME		= libftprintf.a

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

bonus:
	make WITH_BONUS=1

re: fclean all

