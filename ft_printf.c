/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:27:56 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/25 00:36:44 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *s, ...)
{
	static t_format	fmt = {.dot = 0, .flg = 0, .min_w = 0, .precision = 0};
	va_list			l;
	int				ret;
	char			*c;
	size_t			fmt_len;

	ret = 0;
	c = (char *)s;
	va_start(l, s);
	if (!s || !check_all_format(c))
		return (va_end(l), ret);
	while (*c)
	{
		if (*c == '%')
		{
			fmt_len = set_format(c, &fmt, valid_format_check(c));
			ret = ret + print_var(c, l, &fmt, DEFAULT_OUTPUT);
			reset_t_format(&fmt);
			c = c + fmt_len + 1;
			continue ;
		}
		ret = ret + ft_putchar_fd_vp(*c++, DEFAULT_OUTPUT);
	}
	va_end(l);
	return (ret);
}

void	reset_t_format(t_format *fmt)
{
	fmt->dot = 0;
	fmt->flg = 0;
	fmt->min_w = 0;
	fmt->precision = 0;
	fmt->len = 0;
}

/*
this function is controler.
Decide which printer function should be called.
return value is number of printed charcter.
*/
size_t	print_var(char *c, va_list l, t_format *fmt, int fd)
{
	size_t	ret;

	ret = 0;
	if (c[fmt->len] == 'c')
		return (ft_print_c(fmt, va_arg(l, int), fd));
	else if (c[fmt->len] == 's')
		return (ft_print_str(fmt, va_arg(l, char *), fd));
	else if (c[fmt->len] == 'p')
		return (ft_print_pointer(fmt, va_arg(l, uintptr_t), fd));
	else if (c[fmt->len] == 'd' || c[fmt->len] == 'i')
		return (ft_print_d_i(fmt, va_arg(l, int), fd));
	else if (c[fmt->len] == 'u')
		return (ft_print_u(fmt, va_arg(l, unsigned int), fd));
	else if (c[fmt->len] == 'x')
		return (ft_print_hex(fmt, va_arg(l, uintptr_t), HXDCML_S, fd));
	else if (c[fmt->len] == 'X')
		return (ft_print_hex_cap(fmt, va_arg(l, uintptr_t), HXDCML_L, fd));
	else if (c[fmt->len] == '%')
		return (ft_putchar_fd_vp('%', fd));
//		return (ft_print_percent(fmt, va_arg(l, int), fd));
	return (ret);
}
