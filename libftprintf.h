/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:52:57 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/07 22:38:04 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEXADECIMAL_S "0123456789abcdef"
# define HEXADECIMAL_L "0123456789ABCDEF"
# define DEFAULT_OUTPUT 1
# define INVALID_SYNTAX -1

typedef struct s_format
{
	char	*flg;
	int		min_w;
	int		dot;
	int		precision;
}	t_format;

unsigned long	ft_putchar_fd_vp(int i, int fd);
unsigned long	ft_putstr_fd_vp(char *s, int fd);
unsigned long	ft_putnbr_fd_vp(long l, int fd);
void			ft_putnbr_base(int nbr, char *base);


#endif