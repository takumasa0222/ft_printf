/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:52:28 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/19 22:36:10 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"


unsigned long	ft_putchar_fd_vp(int i, int fd)
{
	ft_putchar_fd(i, fd);
	return (1);
}

unsigned long	ft_putstr_fd_vp(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		return (ft_strlen(s));
	}
	else
	{
		ft_putstr_fd("(null)", fd);
		return (ft_strlen("(null)"));
	}
}

unsigned long	ft_putnbr_fd_vp(long l, int fd)
{
	char	*str;

	ft_putnbr_fd(l, fd);
	str = ft_itoa(l);
	if (!str)
		return (0);
	return (ft_strlen(str));
}


unsigned long	ft_putunbr_fd_vp(unsigned int i, int fd)
{
	unsigned int	cpy_n;

	cpy_n = i;
	if (cpy_n > 9)
	{
		ft_putnbr_fd(cpy_n / 10, fd);
		cpy_n = cpy_n % 10;
	}
	if (cpy_n < 10)
		ft_putchar_fd((cpy_n + 48), fd);
}
