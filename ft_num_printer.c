/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:41:32 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/20 23:22:13 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

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
	char			*str;

	cpy_n = i;
	// if (cpy_n > 9)
	// {
	// 	ft_putnbr_fd(cpy_n / 10, fd);
	// 	cpy_n = cpy_n % 10;
	// }
	// if (cpy_n < 10)
	// 	ft_putchar_fd((cpy_n + 48), fd);
	str = ft_itoa(i);
	if (!str)
		return (0);
	return (ft_strlen(str));
}

unsigned long	ft_putnbr_fd_16base_vp(long l, int fd)
{
	unsigned int	cpy_n;
	char			*str;

	cpy_n = l;
	// if (cpy_n > 15)
	// {
	// 	ft_putnbr_fd(cpy_n / 10, fd);
	// 	cpy_n = cpy_n % 10;
	// }
	// if (cpy_n < 10)
	// 	ft_putchar_fd((cpy_n + 48), fd);
	str = ft_itoa(l);
	if (!str)
		return (0);
	return (ft_strlen(str));
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	printint;
	int		len;


	len = ft_strlen(HEXADECIMAL_S);
	printint = '0';
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nbr = nbr * -1;
		ft_putnbr_base(nbr, HEXADECIMAL_S);
	}
	else if (nbr > len - 1)
	{
		ft_putnbr_base(nbr / len, HEXADECIMAL_S);
		ft_putnbr_base(nbr % len, HEXADECIMAL_S);
	}
	else
	{
		ft_putchar_fd(HEXADECIMAL_S[nbr], 1);
	}
}
