/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:10:00 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/17 20:27:33 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	overflowcheck(int sign, long res, char c);

int	ft_atoi(const char *str)
{
	int		minus_flag;
	long	result;

	minus_flag = 1;
	result = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' \
	|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus_flag = -1;
		str++;
	}
	while (ft_isdigit(*str) && *str)
	{
		if (overflowcheck(minus_flag, result, *str) == 1)
			return ((int)LONG_MAX);
		if (overflowcheck(minus_flag, result, *str) == -1)
			return ((int)LONG_MIN);
		result = result * 10 + (long)(*str - 48);
		str++;
	}
	return ((int)(minus_flag * result));
}

int	overflowcheck(int sign, long res, char c)
{
	int	i;

	i = c - 48;
	if (sign > 0)
	{
		if (LONG_MAX / 10 < res || (LONG_MAX / 10 == res && LONG_MAX % 10 <= i))
			return (1);
	}
	else
	{
		if (LONG_MIN / -10 < res \
		|| (LONG_MIN / -10 == res && LONG_MIN % 10 * -1 <= i))
			return (-1);
	}
	return (0);
}
