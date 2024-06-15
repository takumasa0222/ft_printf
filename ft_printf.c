/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:27:56 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/16 05:27:38 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <stdio.h>

// unsigned long	arg_to_output(char	*c, va_list l);
// int				validatenextc(char *c);


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
		return (ft_putchar_fd_vp('q', va_arg(l, int)));
	// else if (c[fmt->len] == 's')
	// 	return (ft_putstr_fd_vp(fmt, va_arg(l, char *), fd));
	// else if (c[fmt->len] == 'p')
	// 	return (ft_putnbr_fd_16base_vp(fmt, va_arg(l, int), fd));
	else if (c[fmt->len] == 'd' || *c == 'i')
		return (ft_print_d_i(fmt, va_arg(l, int), fd));
	else if (c[fmt->len] == 'u')
		return (ft_print_u(fmt, va_arg(l, unsigned int), fd));
	// else if (c[fmt->len] == 'x')
	// 		return (0);
	// else if (c[fmt->len] == 'X')
	// 		return (0);
	// else if (c[fmt->len] == '%')
	// 	return (ft_putchar_fd_vp('%', 1));
	return (ret);
}

//*/
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	/*
	printf("%12s\n",NULL);//      (null)$
	printf("%03%\n");//00%$
	// flag conbination pattern
	printf("|%- 5d|\n",123);//| 123 |$
	printf("|%-+5d|\n",1);//|+1   |$
	printf("|%-#5x|\n",1);//|0x1  |$
	printf("|%0 5d|\n",1);//| 0001|$
	printf("|%0+5d|\n",1);//|+0001|$
	printf("|%0#5x|\n",11);//|0x00b|$
	// repeated flgs seem working fine when compiling cc.
	printf("|%- - - - 5d|\n",123);//| 123 |$
	printf("|%-+-+-+-+5d|\n",123);//|+123 |$
	printf("|%#-#-#-5x|\n",123);//|0x7b |$
	// flag conbination pattern for %. it seems only - and 0 will be work.
	printf("|%- 5%|\n");//|%    |$
	printf("|%-+5%|\n");//|%    |$
	printf("|%-#5%|\n");//|%    |$
	printf("|%0 5%|\n");//|0000%|$
	printf("|%0+5%|\n");//|0000%|$
	printf("|%0#5%|\n");//|0000%|$

	printf("|%#0- +5%|\n");//|%    |$
	printf("|%-0+ 5%|\n");//|%    |$
	printf("|%03.30%|\n");//|00%|$
	printf("|%#+0%|\n");//|%|$
	printf("|%03.5d|\n",123);//|00123|$
	printf("|%.5d|\n",123);//|00123|$
	printf("|%6.5d|\n",123);//| 00123|$
	printf("|%6.7d|\n",123);//|0000123|$
	printf("|%-6.7d|\n",123);//|0000123|$
	printf("|%-9.7d|\n",123);//|0000123  |$
	printf("|%-9.d|\n",123);//|123      |$
	printf("|%09.d|\n",123);//|      123|$
	printf("|%+9.d|\n",123);//|     +123|$
	printf("|% 9.d|\n",123);//|      123|
	printf("|%#9.3x|\n",123);//|    0x07b|
	printf("|%#9.5x|\n",123);//|  0x0007b|
	printf("|%#9.3x|\n",12300);//|   0x300c|
	printf("|%0..d|\n",123);//warning: invalid conversion specifier '.'
	printf("|%#9.1x|\n",12300);//|   0x300c|
	printf("|%#2.7x|\n",12300);//|0x000300c|
	printf("|%2.3d|\n",12300);//|12300|
	printf("|%2.3i|\n",12300);//|12300|
	printf("|%2.3u|\n",12300);//|12300|
	printf("|%2.00003u|\n",12300);//|12300
	// test for priority
	printf("|%0.5u|\n",123);//|00123|
	printf("|%0.5d|\n",123);//|00123|
	printf("|%09.d|\n",123);//|      123|
	printf("|%-9.d|\n",123);//|123      |
	printf("|%-.5d|\n",123);//|00123|
	printf("|% .5d|\n",123);//| 00123|
	printf("|%+.5d|\n",123);//|+00123|
	printf("|%04.5d|\n",123);//|00123|
	printf("|%-4.5d|\n",123);//|00123|
	printf("|%-7.5d|\n",123);//|00123  |
	printf("|%07.5d|\n",123);//|  00123|
	printf("|% .5d|\n",-123);//|-00123|
	printf("|%+.5d|\n",-123);//|-00123|
	printf("|%.5d|\n",-123);//|-00123|
	printf("|%.2d|\n",-123);//|-123|
	printf("|%.1d|\n",123);//|123|
	printf("|%.1x|\n",123);//|7b|
	printf("|%.5X|\n",123);//|0007B|
	printf("|%#.5X|\n",123);//|0X0007B|
	printf("|%#.5X|\n",-123);//|0XFFFFFF85|
	printf("|%#3.2X|\n",123);//|0X7B|
	printf("|%#5.2X|\n",123);//| 0X7B|
	printf("|%-10.8d|\n",123);//|00000123  |
	printf("|%-+10.8d|\n",123);//|+00000123 |
	printf("|%-+8.8d|\n",123);//|+00000123|
	printf("|%-8.4d|\n",-123);//|-0123   |
	printf("|%+-8.4d|\n",123);//|+0123   |
	// printf("|%03.30%|\n");//|00%|$
	// printf("%s");//incomplete format specifier [-Werror,-Wformat]
	// printf("%");//incomplete format specifier [-Werror,-Wformat]
	// printf("%d%s\n",123);
	// printf("%d%s%x\n",123);
	// printf("%d%s\n",123);
	// printf("%d%d%p\n",123);
	// printf("%d%%\n",123);
	// printf("%d%%\n",123,456);
	// printf("%d%%\n",123);
//printf(NULL);
	// printf("%abcd\n");
	// printf("%adsf%cbcd\n",'z');
	// printf("test%x\n",123);
	// printf("test%X\n",123);
	// printf("test%p\n","h");
	printf("%d\n", printf("%s",NULL));
	printf("%u\n", UINT_MAX);
	printf("%i\n", UINT_MAX + 1);
	printf("test%p\n",NULL);//0x0
*/
	// ft_printf("|%d|\n",456);
	// ft_printf("|% d|\n",456);
	// ft_printf("|%+d|\n",456);
	// ft_printf("|%-5d|\n",456);
	ft_printf("|%07d|\n",456);
	ft_printf("|%.5d|\n",456);
	ft_printf("|%8.5d|\n",456);
	ft_printf("|%-8.5d|\n",456);
	ft_printf("|%+-8.5d|\n",456);
	ft_printf("|%+8.5d|\n",456);
	printf("|%+8.5d|\n",456);
	ft_printf("|%0 8d|\n",456);
	printf("|%0 8d|\n",456);
	ft_printf("|%+-8.5d|\n",456);
	ft_printf("|%d|\n",456);

	// char *s = "";
	// printf("testvalidate_format%ld\n",validate_format_sp(s));
	// char *c;
	// c = "a";

	// printf("test%d\n",c);
	// printf("test%p\n",c);
	// ft_printf("test%d\n",123);
	// ft_printf("test%d\n",c);
	// ft_printf("test%i\n",UINT_MAX);
	// ft_printf("test%i\n",UINT_MAX + 1);
	// ft_printf("test%s\n",NULL);
	// const char *format = "%-03d\n";
	// const char *format2 = "%07..d\n";
	// int d = 4;

	// printf(format, d);
	// printf(format2, d);

}
