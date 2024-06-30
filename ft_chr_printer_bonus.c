/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_printer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:52:28 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/30 15:50:13 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_print_c(t_format *fmt, int i, int fd)
{
	size_t	ret;

	ret = 0;
	if (fmt->flg & MN_FLG)
	{
		ret = ret + ft_putchar_fd_vp(i, fd);
		ret = ret + ft_print_mnw_c(fmt, fd);
	}
	else
	{
		ret = ret + ft_print_mnw_c(fmt, fd);
		ret = ret + ft_putchar_fd_vp(i, fd);
	}
	return (ret);
}

size_t	ft_print_mnw_c(t_format *fmt, int fd)
{
	size_t	i;

	i = 0;
	if (fmt->flg & ZR_FLG)
	{
		while (i + 1 < (size_t)fmt->min_w)
			i = i + ft_putchar_fd_vp('0', fd);
	}
	else
	{
		while (i + 1 < (size_t)fmt->min_w)
			i = i + ft_putchar_fd_vp(' ', fd);
	}
	return (i);
}

size_t	ft_putchar_fd_vp(int i, int fd)
{
	ft_putchar_fd(i, fd);
	return (1);
}
