/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:52:57 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/16 04:27:06 by tamatsuu         ###   ########.fr       */
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
	size_t			len;
}	t_format;

//ft_printf.c
int				ft_printf(const char *s, ...);
void			reset_t_format(t_format *fmt);
size_t			print_var(char *c, va_list l, t_format *fmt, int fd);

//ft_printf_utils.c
size_t			set_format(char *c, t_format *fmt, size_t s_len);
unsigned int	set_flg(char c, unsigned int flags);
int				ft_printf_atoi(char	*c, size_t *i);

//ft_printf_validater.c
int				check_all_format(char *c);
size_t			valid_format_check(char *c);
unsigned int	validate_flg(char *c, size_t s_len, unsigned int flags);

//ft_num_printer.c
size_t			ft_print_d_i(t_format *fmt, int i, int fd);
size_t			ft_print_precision_d_i_u(t_format *fmt, long i, size_t num_len, int fd);
size_t			ft_print_u(t_format *fmt, unsigned int i, int fd);

//ft_num_printer_utils.c
size_t			sign_len(long i, t_format *fmt);
char			get_sign(long i, t_format *fmt);
size_t			ft_putnbr_fd_vp(long i, int fd);
size_t			ft_abs_num_len (long i);

unsigned long	ft_putchar_fd_vp(int i, int fd);
unsigned long	ft_putstr_fd_vp(char *s, int fd);
void			ft_putnbr_base(int nbr, char *base);

unsigned long	ft_print_u(t_format *fmt, unsigned int i, int fd);



#endif