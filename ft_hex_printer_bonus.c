/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_printer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:57:28 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/29 22:21:16 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_hex(t_format *fmt, uintptr_t i, char *hex, int fd)
{
	size_t	ret;

	ret = 0;
	if (fmt->flg & MN_FLG)
	{
		if (fmt->flg & HASH_FLG && i != 0)
			ret = ft_putstr_fd_vp("0x", fd);
		ret += ft_hex_prec_fd(fmt, i, ft_putnbr_base_cnt(i, hex), fd);
		ret = ft_hex_mnw_p(fmt, ret, fd);
	}
	else
	{
		if (!(fmt->dot && !fmt->precision && !i))
			ret = ft_putnbr_base_cnt(i, hex);
		if (ret < (size_t)fmt->precision)
			ret = fmt->precision;
		if (fmt->flg & HASH_FLG && i != 0)
			ret = ret + 2;
		ret = ft_hex_mnw_p(fmt, ret, fd);
		if (fmt->flg & HASH_FLG && i != 0)
			ft_putstr_fd_vp("0x", fd);
		ft_hex_prec_fd(fmt, i, ft_putnbr_base_cnt(i, hex), fd);
	}
	return (ret);
}

size_t	ft_hex_prec_fd(t_format *fmt, uintptr_t i, size_t cnt, int fd)
{
	size_t	ret;

	ret = cnt;
	while (ret < (size_t)fmt->precision)
		ret = ret + ft_putchar_fd_vp('0', fd);
	if (fmt->dot && !fmt->precision && !i)
		return (ret - cnt);
	ft_putnbr_base(i, HXDCML_S, fd);
	return (ret);
}

size_t	ft_print_hex_cap(t_format *fmt, uintptr_t i, char *hex, int fd)
{
	size_t	ret;

	ret = 0;
	if (fmt->flg & MN_FLG)
	{
		if (fmt->flg & HASH_FLG && i != 0)
			ret = ft_putstr_fd_vp("0X", fd);
		ret += ft_hexcap_prec_fd(fmt, i, ft_putnbr_base_cnt(i, hex), fd);
		ret = ft_hex_mnw_p(fmt, ret, fd);
	}
	else
	{
		if (!(fmt->dot && !fmt->precision && !i))
			ret = ft_putnbr_base_cnt(i, hex);
		if (ret < (size_t)fmt->precision)
			ret = fmt->precision;
		if (fmt->flg & HASH_FLG && i != 0)
			ret = ret + 2;
		ret = ft_hex_mnw_p(fmt, ret, fd);
		if (fmt->flg & HASH_FLG && i != 0)
			ft_putstr_fd_vp("0X", fd);
		ft_hexcap_prec_fd(fmt, i, ft_putnbr_base_cnt(i, hex), fd);
	}
	return (ret);
}

size_t	ft_hexcap_prec_fd(t_format *fmt, uintptr_t i, size_t cnt, int fd)
{
	size_t	ret;

	ret = cnt;
	while (ret < (size_t)fmt->precision)
		ret = ret + ft_putchar_fd_vp('0', fd);
	if (fmt->dot && !fmt->precision && !i)
		return (ret - cnt);
	ft_putnbr_base(i, HXDCML_L, fd);
	return (ret);
}

size_t	ft_hex_mnw_p(t_format *fmt, size_t cnt, int fd)
{
	size_t	ret;

	ret = cnt;
	while (!(fmt->flg & ZR_FLG) && ret < (size_t)fmt->min_w)
		ret = ret + ft_putchar_fd_vp(' ', fd);
	while (fmt->flg & ZR_FLG && ret < (size_t)fmt->min_w)
		ret = ret + ft_putchar_fd_vp('0', fd);
	return (ret);
}
