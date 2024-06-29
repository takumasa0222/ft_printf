# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 21:12:16 by tamatsuu          #+#    #+#              #
#    Updated: 2024/06/29 22:45:35 by tamatsuu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SRCS	= ft_chr_printer.c ft_hex_printer.c ft_num_printer.c ft_num_printer_utils.c ft_pointer_printer.c ft_str_printer.c \
ft_printf_utils.c ft_printf_validater.c ft_printf.c ft_percent_printer.c

OBJS	= $(SRCS:%.c=%.o)
BONUS	= ft_chr_printer_bonus.c ft_hex_printer_bonus.c ft_num_printer_bonus.c ft_num_printer_utils_bonus.c ft_pointer_printer_bonus.c ft_str_printer_bonus.c \
ft_printf_utils_bonus.c ft_printf_validater_bonus.c ft_printf_bonus.c ft_percent_printer_bonus.c
LIB	= ./libft/libft.a
BOBJS		= $(BONUS:%.c=%.o)
NAME		= libftprintf.a
AR		= ar

.PHONY: all clean fclean re norm bonus
.SILENT: all
all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	cp $(LIB) $(NAME)
	$(AR) rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

bonus: $(BOBJS)
	@make -C libft
	cp $(LIB) $(NAME)
	$(AR) rcs $(NAME) $(BOBJS)

$(BOBJS): $(BONUS)
	$(CC) $(CFLAGS) -c $(BONUS)


norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS)
	norminette -R CheckDefine *.h

re: fclean all
