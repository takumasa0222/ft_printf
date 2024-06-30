/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_printer_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:01:40 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/30 14:39:41 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_pointer(t_format *fmt, uintptr_t i, int fd)
{
	size_t	ret;

	ret = 0;
	if (fmt->flg & MN_FLG)
	{
		ret = ft_putstr_fd_vp("0x", fd);
		ret += ft_ptr_prec_fd(fmt, i, ft_putnbr_base_cnt(i, HXDCML_S), fd);
		ret = ft_print_mnw_p(fmt, ret, fd);
	}
	else
	{
		ret = ft_putnbr_base_cnt(i, HXDCML_S);
		if (ret < (size_t)fmt->precision)
			ret = fmt->precision;
		ret += 2;
		ret = ft_print_mnw_p(fmt, ret, fd);
		ft_putstr_fd_vp("0x", fd);
		ft_ptr_prec_fd(fmt, i, ft_putnbr_base_cnt(i, HXDCML_S), fd);
	}
	return (ret);
}

size_t	ft_ptr_prec_fd(t_format *fmt, uintptr_t i, size_t cnt, int fd)
{
	size_t	ret;

	ret = cnt;
	while (ret < (size_t)fmt->precision)
		ret = ret + ft_putchar_fd_vp('0', fd);
	ft_putnbr_base(i, HXDCML_S, fd);
	return (ret);
}

size_t	ft_putnbr_base(uintptr_t nbr, char *base, int fd)
{
	size_t	len;
	size_t	ret;

	ret = 0;
	len = ft_strlen(base);
	if (nbr > len - 1)
	{
		ret = ret + ft_putnbr_base(nbr / len, base, fd);
		ret = ret + ft_putnbr_base(nbr % len, base, fd);
	}
	else
	{
		ft_putchar_fd_vp(base[nbr], fd);
		ret++;
	}
	return (ret);
}

size_t	ft_print_mnw_p(t_format *fmt, size_t cnt, int fd)
{
	size_t	ret;

	ret = cnt;
	while (ret < (size_t)fmt->min_w)
		ret = ret + ft_putchar_fd_vp(' ', fd);
	return (ret);
}

size_t	ft_putnbr_base_cnt(uintptr_t nbr, char *base)
{
	size_t	len;
	size_t	ret;

	ret = 0;
	len = ft_strlen(base);
	if (nbr > len - 1)
	{
		ret = ret + ft_putnbr_base_cnt(nbr / len, base);
		ret = ret + ft_putnbr_base_cnt(nbr % len, base);
	}
	else
		ret++;
	return (ret);
}
