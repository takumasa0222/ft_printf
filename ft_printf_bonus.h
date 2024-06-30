/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:52:57 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/30 15:52:26 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

# define HXDCML_S "0123456789abcdef"
# define HXDCML_L "0123456789ABCDEF"
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
size_t			valid_format_check(char *c);
int				check_all_format(char *c);
unsigned int	validate_flg(char *c, size_t s_len, unsigned int flags);

//ft_num_printer.c
size_t			ft_print_d_i(t_format *fmt, int i, int fd);
size_t			ft_print_prec_d_i_u(t_format *fmt, long i, size_t nlen, int fd);
size_t			ft_print_sign(t_format *fmt, long i, int fd);
size_t			ft_print_u(t_format *fmt, unsigned int i, int fd);

//ft_num_printer_utils.c
size_t			sign_len(long i, t_format *fmt);
char			get_sign(long i, t_format *fmt);
void			ft_putnbr_fd_vp(long i, int fd);
size_t			ft_abs_num_len(long i, t_format *fmt);
size_t			ft_print_mnw_d_i_u(t_format *fmt, size_t i, long val, int fd);

//ft_chr_printer.c
size_t			ft_putchar_fd_vp(int i, int fd);
size_t			ft_print_c(t_format *fmt, int i, int fd);
size_t			ft_print_mnw_c(t_format *fmt, int fd);

//ft_pointer_printer.c
size_t			ft_print_pointer(t_format *fmt, uintptr_t i, int fd);
size_t			ft_ptr_prec_fd(t_format *fmt, uintptr_t i, size_t cnt, int fd);
size_t			ft_print_mnw_p(t_format *fmt, size_t cnt, int fd);
size_t			ft_putnbr_base(uintptr_t nbr, char *base, int fd);
size_t			ft_putnbr_base_cnt(uintptr_t nbr, char *base);

//ft_str_printer.c
size_t			ft_print_str(t_format *fmt, char *str, int fd);
size_t			ft_print_str_fd(t_format *fmt, char *s, int fd);
size_t			ft_putstr_null_fd(t_format *fmt, char *nul_str, int fd);
size_t			ft_putstr_mnw_str(t_format *fmt, char *s, int fd);
size_t			ft_putstr_fd_vp(char *s, int fd);

size_t			ft_print_hex(t_format *fmt, uintptr_t i, char *hex, int fd);
size_t			ft_hex_prec_fd(t_format *fmt, uintptr_t i, size_t cnt, int fd);
size_t			ft_hexcap_prec_fd(t_format *fmt, uintptr_t i, size_t c, int fd);
size_t			ft_print_hex_cap(t_format *fmt, uintptr_t i, char *hex, int fd);
size_t			ft_hex_mnw_p(t_format *fmt, size_t cnt, int fd);

size_t			ft_print_percent(t_format *fmt, int c, int fd);

//ft_hex_printer_utils_bonus.c
size_t			ha_mnw_printer(t_format *fmt, uintptr_t i, size_t cnt, int fd);
size_t			hl_mnw_printer(t_format *fmt, uintptr_t i, size_t cnt, int fd);
#endif