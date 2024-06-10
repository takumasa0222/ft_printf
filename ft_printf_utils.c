/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 03:42:01 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/11 04:46:12 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

size_t	set_format(char *c, t_format *fmt, size_t s_len)
{
	size_t	i;
	int		dot_flg;

	dot_flg = 0;
	i = 1;
	while (ft_strchr(" +-#0", c[i]))
		fmt->flg = set_flg(c[i++], fmt->flg);
	fmt->flg = validate_flg(c[0], s_len, fmt->flg);
	fmt->min_w = ft_printf_atoi(c[i], &i);
	if ((ft_strchr(".", c[i])))
		fmt->dot = 1;
	fmt->precision = ft_printf_atoi(c[i], &i);
	return (s_len);
}

unsigned int	*set_flg(char c, unsigned int flags)
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
