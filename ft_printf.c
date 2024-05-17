/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:27:56 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/17 23:28:36 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	l;
	int		i;

	if (!s)
		return (0);
	i = 0;
	va_start(l, s);
	while (*s)
	{
		if (*s == '%')
		{

		}
		s++;
	}
}

#include <stdio.h>
int	main(void)
{
	printf("%d%s\n",123);
	printf("%d%s%x\n",123);
	printf("%d%s\n",123);
	printf("%d%d%p\n",123);
	printf("%d%%\n",123);
	printf("%d%%\n",123,456);
	printf("%d%%\n",123);
//printf(NULL);
	printf("%abcd\n");
}
