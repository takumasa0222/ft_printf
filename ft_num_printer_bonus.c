/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_printer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:41:32 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/30 14:23:34 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_d_i(t_format *fmt, int i, int fd)
{
	size_t	n_len;
	size_t	ret;

	n_len = ft_abs_num_len(i, fmt);
	ret = 0;
	if (fmt->flg & MN_FLG)
	{
		ret = ret + ft_print_sign(fmt, (long) i, fd);
		ret = ret + ft_print_prec_d_i_u(fmt, (long) i, n_len, fd);
		ret = ft_print_mnw_d_i_u(fmt, ret, i, fd);
	}
	else if (fmt->flg & ZR_FLG)
	{
		ret = ret + ft_print_sign(fmt, (long) i, fd);
		ret = ft_print_mnw_d_i_u(fmt, ret, i, fd);
		ret = ret + ft_print_prec_d_i_u(fmt, (long) i, n_len, fd);
	}
	else
	{
		ret = ft_print_mnw_d_i_u(fmt, ret, i, fd);
		ret = ret + ft_print_sign(fmt, (long) i, fd);
		ret = ret + ft_print_prec_d_i_u(fmt, (long) i, n_len, fd);
	}
	return (ret);
}

size_t	ft_print_prec_d_i_u(t_format *fmt, long i, size_t n_len, int fd)
{
	size_t	ret;

	ret = 0;
	while (ret + n_len < (size_t)fmt->precision)
		ret = ret + ft_putchar_fd_vp('0', fd);
	if (!i && fmt->dot)
		return (ret);
	ft_putnbr_fd_vp(i, fd);
	ret = ret + n_len;
	return (ret);
}

size_t	ft_print_mnw_d_i_u(t_format *fmt, size_t i, long val, int fd)
{
	size_t	len;

	len = ft_abs_num_len(val, fmt);
	if (fmt->flg & MN_FLG)
	{
		while (i < (size_t)fmt->min_w)
			i = i + ft_putchar_fd_vp(' ', fd);
	}
	else if (fmt->flg & ZR_FLG)
	{
		while (i + len < (size_t)fmt->min_w && \
		(int)i < fmt->min_w - fmt->precision)
			i = i + ft_putchar_fd_vp('0', fd);
	}
	else
	{
		while (i + len + sign_len(val, fmt) < (size_t)fmt->min_w \
			&& (int)i < fmt->min_w - fmt->precision - (int)sign_len(val, fmt))
			i = i + ft_putchar_fd_vp(' ', fd);
	}
	return (i);
}

size_t	ft_print_sign(t_format *fmt, long i, int fd)
{
	size_t	ret;

	ret = 0;
	if (fmt->flg & PLS_FLG || fmt->flg & SP_FLG || i < 0)
		ret = ft_putchar_fd_vp(get_sign(i, fmt), fd);
	return (ret);
}

size_t	ft_print_u(t_format *fmt, unsigned int i, int fd)
{
	size_t	n_len;
	size_t	ret;

	n_len = ft_abs_num_len(i, fmt);
	ret = 0;
	if (fmt->flg & MN_FLG)
	{
		ret = ret + ft_print_sign(fmt, (long) i, fd);
		ret = ret + ft_print_prec_d_i_u(fmt, (long) i, n_len, fd);
		ret = ft_print_mnw_d_i_u(fmt, ret, i, fd);
	}
	else if (fmt->flg & ZR_FLG)
	{
		ret = ret + ft_print_sign(fmt, (long) i, fd);
		ret = ft_print_mnw_d_i_u(fmt, ret, i, fd);
		ret = ret + ft_print_prec_d_i_u(fmt, (long) i, n_len, fd);
	}
	else
	{
		ret = ft_print_mnw_d_i_u(fmt, ret, i, fd);
		ret = ret + ft_print_sign(fmt, (long) i, fd);
		ret = ret + ft_print_prec_d_i_u(fmt, (long) i, n_len, fd);
	}
	return (ret);
}
