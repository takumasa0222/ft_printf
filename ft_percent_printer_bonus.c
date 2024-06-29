/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_printer_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:49:34 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/29 22:21:21 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_percent(t_format *fmt, int c, int fd)
{
	size_t	ret;

	ret = 0;
	if (fmt->flg & MN_FLG)
	{
		ret = ret + ft_putchar_fd_vp(c, fd);
		ret = ret + ft_print_mnw_c(fmt, fd);
	}
	else
	{
		ret = ret + ft_print_mnw_c(fmt, fd);
		ret = ret + ft_putchar_fd_vp(c, fd);
	}
	return (ret);
}
