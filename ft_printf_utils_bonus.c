/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 03:42:01 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/29 22:21:26 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
this function set the valid format to 2nd argument.
return value is the string length of format.
*/
size_t	set_format(char *c, t_format *fmt, size_t s_len)
{
	size_t	i;

	i = 1;
	while (ft_strchr(" +-#0", c[i]))
		fmt->flg = set_flg(c[i++], fmt->flg);
	fmt->flg = validate_flg(c, s_len, fmt->flg);
	fmt->min_w = ft_printf_atoi(&c[i], &i);
	if ((ft_strchr(".", c[i])))
	{
		fmt->dot = 1;
		fmt->flg &= ~ZR_FLG;
		i++;
	}
	fmt->precision = ft_printf_atoi(&c[i], &i);
	fmt->len = s_len;
	return (s_len);
}

unsigned int	set_flg(char c, unsigned int flags)
{
	if (c == ' ')
		flags |= SP_FLG;
	else if (c == '+')
		flags |= PLS_FLG;
	else if (c == '-')
		flags |= MN_FLG;
	else if (c == '0')
		flags |= ZR_FLG;
	else if (c == '#')
		flags |= HASH_FLG;
	return (flags);
}

/*
this function convert char to integer.
Second argument is iterator and this function changes the iterator value.
This is because set_format is not using while loop.
*/
int	ft_printf_atoi(char	*c, size_t *i)
{
	size_t	j;
	char	*c_cpy;

	j = 0;
	while (ft_isdigit(c[j]))
		j++;
	if (!j)
		return (0);
	*i = *i + j;
	c_cpy = c;
	return (ft_atoi(c_cpy));
}
