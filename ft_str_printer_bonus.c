/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_printer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:57:24 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/29 23:38:33 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_str(t_format *fmt, char *str, int fd)
{
	size_t	ret;

	ret = 0;
	if (fmt->flg & MN_FLG)
	{
		ret = ret + ft_print_str_fd(fmt, str, fd);
		ret = ret + ft_putstr_mnw_str(fmt, str, fd);
	}
	else
	{
		ret = ret + ft_putstr_mnw_str(fmt, str, fd);
		ret = ret + ft_print_str_fd(fmt, str, fd);
	}
	return (ret);
}

size_t	ft_print_str_fd(t_format *fmt, char *s, int fd)
{
	size_t	i;
	size_t	str_len;

	i = 0;
	if (!s)
		return (ft_putstr_null_fd(fmt, "(null)", fd));
	str_len = ft_strlen(s);
	if (fmt->dot)
	{
		while (i < (size_t)fmt->precision && i < str_len)
			ft_putchar_fd(s[i++], fd);
	}
	else
	{
		while (s[i])
			ft_putchar_fd(s[i++], fd);
	}
	return (i);
}

size_t	ft_putstr_null_fd(t_format *fmt, char *nul_str, int fd)
{
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen(nul_str);
	i = 0;
	if (fmt->dot)
	{
		while (i < (size_t)fmt->precision && i < str_len)
			ft_putchar_fd(nul_str[i++], fd);
	}
	else
	{
		while (nul_str[i])
			ft_putchar_fd(nul_str[i++], fd);
	}
	return (i);
}

size_t	ft_putstr_mnw_str(t_format *fmt, char *s, int fd)
{
	size_t	s_len;
	size_t	i;

	if (!s)
		s_len = 6;
	else
		s_len = ft_strlen(s);
	i = 0;
	if (fmt->dot && (size_t)fmt->precision < s_len)
		s_len = fmt->precision;
	if (fmt->flg & ZR_FLG)
	{
		while (i + s_len < (size_t)fmt->min_w)
			i = i + ft_putchar_fd_vp('0', fd);
	}
	else
	{
		while (i + s_len < (size_t)fmt->min_w)
			i = i + ft_putchar_fd_vp(' ', fd);
	}
	return (i);
}

size_t	ft_putstr_fd_vp(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	ft_putstr_fd(s, fd);
	return (ft_strlen(s));
}
