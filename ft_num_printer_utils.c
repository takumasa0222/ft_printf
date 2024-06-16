/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_printer_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 03:31:16 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/16 18:50:18 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

size_t	sign_len(long i, t_format *fmt)
{
	if (i < 0)
		return (1);
	if (fmt->flg & PLS_FLG || fmt->flg & SP_FLG)
		return (1);
	return (0);
}

char	get_sign(long i, t_format *fmt)
{
	if (i < 0)
		return ('-');
	else if (fmt->flg & PLS_FLG)
		return ('+');
	else if (fmt->flg & SP_FLG)
		return (' ');
	else
		return ('\0');
}

void	ft_putnbr_fd_vp(long i, int fd)
{
	long	cpy_n;

	cpy_n = i;
	if (cpy_n < 0)
		cpy_n = cpy_n * -1;
	if (cpy_n > 9)
	{
		ft_putnbr_fd(cpy_n / 10, fd);
		cpy_n = cpy_n % 10;
	}
	if (cpy_n < 10)
		ft_putchar_fd((cpy_n + 48), fd);
}

size_t	ft_abs_num_len(long i, t_format *fmt)
{
	size_t	ret;

	ret = 1;
	if (i < 0)
		i = i * -1;
	if (i == 0 && fmt->dot)
		return (0);
	while (i >= 10)
	{
		i = i / 10;
		ret++;
	}
	return (ret);
}
