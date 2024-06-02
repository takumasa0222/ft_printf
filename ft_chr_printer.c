/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:52:28 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/20 19:41:40 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"


unsigned long	ft_putchar_fd_vp(int i, int fd)
{
	ft_putchar_fd(i, fd);
	return (1);
}

unsigned long	ft_putstr_fd_vp(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		return (ft_strlen(s));
	}
	else
	{
		ft_putstr_fd("(null)", fd);
		return (ft_strlen("(null)"));
	}
}
