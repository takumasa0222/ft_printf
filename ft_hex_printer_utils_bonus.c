/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_printer_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:02:24 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/30 15:25:25 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ha_mnw_printer(t_format *fmt, uintptr_t i, size_t cnt, int fd)
{
	size_t	ret;

	ret = cnt;
	if (fmt->flg & HASH_FLG && i != 0 && fmt->flg & ZR_FLG)
	{
		ret = ret + ft_putstr_fd_vp("0x", fd);
		ret = ft_hex_mnw_p(fmt, ret, fd);
	}
	else if (fmt->flg & HASH_FLG && i != 0)
	{
		ret = ft_hex_mnw_p(fmt, ret, fd);
		ret = ret + ft_putstr_fd_vp("0x", fd);
	}
	else
	{
		ret = ft_hex_mnw_p(fmt, ret, fd);
	}
	return (ret);
}

size_t	ha_mnw_printer(t_format *fmt, uintptr_t i, size_t cnt, int fd)
{
	size_t	ret;

	ret = cnt;
	if (fmt->flg & HASH_FLG && i != 0 && fmt->flg & ZR_FLG)
	{
		ret = ret + ft_putstr_fd_vp("0X", fd);
		ret = ft_hex_mnw_p(fmt, ret, fd);
	}
	else if (fmt->flg & HASH_FLG && i != 0)
	{
		ret = ft_hex_mnw_p(fmt, ret, fd);
		ret = ret + ft_putstr_fd_vp("0X", fd);
	}
	else
	{
		ret = ft_hex_mnw_p(fmt, ret, fd);
	}
	return (ret);
}
