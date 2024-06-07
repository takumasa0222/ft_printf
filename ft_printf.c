/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:27:56 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/07 23:43:42 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <stdio.h>

// unsigned long	arg_to_output(char	*c, va_list l);
// int				validatenextc(char *c);

/*
int	ft_printf(const char *s, ...)
{
	static t_format	fmt = {.dot = 0, .flg = NULL, .min_w = 0, .precision = 0};
	va_list			l;
	int				ret;
	char			*c;

	ret = 0;
	if (!s)
		return (ret);
	c = (char *)s;
	va_start(l, s);
	while (*c)
	{
		if (*c == '%')
		{
			if (validate_format(c, &fmt) == INVALID_SYNTAX)
				return (ret = 0, ret);
			c = c + validate_format(c, &fmt);
			ret = ret + print_var(fmt, l, DEFAULT_OUTPUT);
			continue ;
		}
		ret = ret + ft_putchar_fd_vp(*c++, DEFAULT_OUTPUT);
	}
	va_end(l);
	return (ret);
}

*/
//this function return format length
// ssize_t	validate_format(char *c, t_format *fmt)
// {
// 	ssize_t	s_len;

// 	s_len = validate_format_sp(*c);
// 	if (s_len == INVALID_SYNTAX | validate_flg(*c, s_len) == INVALID_SYNTAX \
// 	| validate_precision() == INVALID_SYNTAX)
// 		return (INVALID_SYNTAX);
// 	return (s_len);
// }

ssize_t	validate_format_sp(char *c)
{
	ssize_t	i;

	i = 0;
	while (c[++i])
	{
		if (ft_strchr("cpdiuxX%", c[i]))
			return (i);
	}
	return (INVALID_SYNTAX);
}

// unsigned long	arg_to_output(char	*c, va_list l)
// {
// 	unsigned long	i;
// 	//printf ("59 gyuome%c\n",*c);
// 	if (*c == 'c')
// 		return (ft_putchar_fd_vp(va_arg(l, int), 1));
// 	else if (*c == 's')
// 		return (ft_putstr_fd_vp(va_arg(l, char *), 1));
// 	else if (*c == 'p')
// 		return (ft_putnbr_fd_16base_vp(va_arg(l, int), 1));
// 	else if (*c == 'd' || *c == 'i')
// 		return (ft_putnbr_fd_vp(va_arg(l, int), 1));
// 	else if (*c == 'u')
// 		return (ft_putunbr_fd_vp(va_arg(l, unsigned int), 1));
// 	else if (*c == 'x')
// 			return (0);
// 	else if (*c == 'X')
// 			return (0);
// 	else if (*c == '%')
// 		return (ft_putchar_fd_vp('%', 1));
// 	return (i);
// }

//*/
#include <stdio.h>
#include <limits.h>
int	main(void)
{
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
	// printf("%q");//incomplete format specifier [-Werror,-Wformat]
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


	char *s = "";
	printf("testvalidate_format%ld\n",validate_format_sp(s));
	char *c;
	c = "a";

	// printf("test%d\n",c);
	printf("test%p\n",c);
	// ft_printf("test%d\n",123);
	// ft_printf("test%d\n",c);
	// ft_printf("test%i\n",UINT_MAX);
	// ft_printf("test%i\n",UINT_MAX + 1);
	// ft_printf("test%s\n",NULL);
}
