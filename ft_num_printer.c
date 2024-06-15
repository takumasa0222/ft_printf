/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:41:32 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/16 05:30:06 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

size_t	ft_print_d_i(t_format *fmt, int i, int fd)
{
	size_t	n_len;
	size_t	ret;

	n_len = ft_abs_num_len(i);
	ret = 0;
	if (fmt->flg & MN_FLG || fmt->min_w <= (n_len + sign_len((long)i, fmt)))
	{
		ret = ft_print_precision_d_i_u(fmt, (long) i, n_len, fd);
		while (ret <= fmt->min_w)
			ret = ret + ft_putchar_fd_vp(' ', fd);
	}
	else
	{
		while (ret + n_len + sign_len(i, fmt) <= fmt->min_w \
		&& ret < fmt->min_w - fmt->precision)
		{
			if (fmt->flg & ZR_FLG)
				ret = ret + ft_putchar_fd_vp('0', fd);
			else
				ret = ret + ft_putchar_fd_vp(' ', fd);
		}
		ret = ret + ft_print_precision_d_i_u(fmt, (long) i, n_len, fd);
	}
	return (ret);
}
#include <stdio.h>
size_t	ft_print_precision_d_i_u(t_format *fmt, long i, size_t num_len, int fd)
{
	size_t	ret;

	ret = 0;
	if (fmt->flg & PLS_FLG || fmt->flg & SP_FLG || i < 0)
		ret = ft_putchar_fd_vp(get_sign(i, fmt), fd);
	//printf("%d\n",fmt->precision);
	while (ret + num_len <= fmt->precision)
		ret = ret + ft_putchar_fd_vp('0', fd);
	ft_putnbr_fd_vp(i, fd);
	ret = ret + num_len;
	return (ret);
}

size_t	ft_print_u(t_format *fmt, unsigned int i, int fd)
{
	size_t	n_len;
	size_t	ret;

	n_len = ft_abs_num_len(i);
	ret = 0;
	if (fmt->flg & MN_FLG || fmt->min_w <= (n_len + sign_len((long)i, fmt)))
	{
		ret = ft_print_precision_d_i_u(fmt, (long) i, n_len, fd);
		while (ret < fmt->min_w)
			ret = ret + ft_putchar_fd_vp(' ', fd);
	}
	else
	{
		while (ret + n_len + sign_len(i, fmt) < fmt->min_w \
		&& fmt->precision < fmt->min_w)
		{
			if (fmt->flg & ZR_FLG)
				ret = ret + ft_putchar_fd_vp('0', fd);
			else
				ret = ret + ft_putchar_fd_vp(' ', fd);
		}
		ret = ret + ft_print_precision_d_i_u(fmt, (long) i, n_len, fd);
	}
	return (ret);
}

// unsigned long	ft_putnbr_fd_16base_vp(long l, int fd)
// {
// 	unsigned int	cpy_n;
// 	char			*str;

// 	cpy_n = l;

// 	str = ft_itoa(l);
// 	if (!str)
// 		return (0);
// 	return (ft_strlen(str));
// }

// void	ft_putnbr_base(int nbr, char *base)
// {
// 	char	printint;
// 	int		len;


// 	len = ft_strlen(HEXADECIMAL_S);
// 	printint = '0';
// 	if (nbr < 0)
// 	{
// 		ft_putchar_fd('-', 1);
// 		nbr = nbr * -1;
// 		ft_putnbr_base(nbr, HEXADECIMAL_S);
// 	}
// 	else if (nbr > len - 1)
// 	{
// 		ft_putnbr_base(nbr / len, HEXADECIMAL_S);
// 		ft_putnbr_base(nbr % len, HEXADECIMAL_S);
// 	}
// 	else
// 	{
// 		ft_putchar_fd(HEXADECIMAL_S[nbr], 1);
// 	}
// }
