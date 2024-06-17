# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 21:12:16 by tamatsuu          #+#    #+#              #
#    Updated: 2024/06/18 02:55:38 by tamatsuu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address
#CFLAGS		=
LIBFT	= ./libft/libft.a
SRCS	= ${wildcard *.c}
OBJS	= ${SRCS:.c=.o}
NAME		= libftprintf.a
AR		= ar

.PHONY: all clean fclean re norm
all: $(NAME)

${NAME}: ${OBJS}
	make -C libft
	cp ${LIBFT} ${NAME}
	${AR} rcs $@ ${OBJS}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

norm :
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine *.h

re: fclean all
