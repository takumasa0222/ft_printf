/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:52:57 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/11 03:36:38 by tamatsuu         ###   ########.fr       */
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
# define INVLD_SYNTX 0
# define NO_FLG 32
# define HASH_FLG 1
# define MN_FLG 2
# define ZR_FLG 4
# define PLS_FLG 8
# define SP_FLG 16

typedef struct s_format
{
	unsigned int	flg;
	int				min_w;
	int				dot;
	int				precision;
}	t_format;

unsigned long	ft_putchar_fd_vp(int i, int fd);
unsigned long	ft_putstr_fd_vp(char *s, int fd);
unsigned long	ft_putnbr_fd_vp(long l, int fd);
void			ft_putnbr_base(int nbr, char *base);


#endif