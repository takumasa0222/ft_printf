/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:27:56 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/19 22:34:32 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <stdio.h>

unsigned long	arg_to_output(char	*c, va_list l);
int				validatenextc(char *c);

int	ft_printf(const char *s, ...)
{
	va_list	l;
	int		i;
	char	*c;

	if (!s)
		return (0);
	c = (char *)s;
	i = 0;
	va_start(l, s);
	while (*c)
	{
		if (*c == '%' && validatenextc(c + 1))
		{
			arg_to_output(c + 1, l);
			c++;
		}
		else if (*c != '%')
			ft_putchar_fd(*c, 1);
		c++;
	}
	va_end(l);

	return (0);
}

int	validatenextc(char *c)
{
	if (!c)
		return (0);
	if (!*c)
		return (0);
	if (ft_strchr("cspdiuxX%",*c))
		return (1);
	return (0);
}

unsigned long	arg_to_output(char	*c, va_list l)
{
	unsigned long	i;
	//printf ("59 gyuome%c\n",*c);
	if (*c == 'c')
		return (ft_putchar_fd_vp(va_arg(l, int), 1));
	else if (*c == 's')
		return (ft_putstr_fd_vp(va_arg(l, char *), 1));
	else if (*c == 'p')
		return (0);
	else if (*c == 'd' || *c == 'i')
		return (ft_putnbr_fd_vp(va_arg(l, int), 1));
	else if (*c == 'u')
		return (ft_putunbr_fd_vp(va_arg(l, unsigned int), 1));
	else if (*c == 'x')
			return (0);
	else if (*c == 'X')
			return (0);
	else if (*c == '%')
		return (ft_putchar_fd_vp('%', 1));
	return (i);
}


#include <stdio.h>
#include <limits.h>
int	main(void)
{
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

	ft_printf("test%d\n",123);
	ft_printf("test%i\n",UINT_MAX);
	ft_printf("test%i\n",UINT_MAX + 1);
	ft_printf("test%s\n",NULL);
}
