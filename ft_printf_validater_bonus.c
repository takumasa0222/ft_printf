/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_validater_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:22:44 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/29 22:21:27 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_all_format(char *c)
{
	size_t	i;
	int		valided_len;

	i = 0;
	while (c[i])
	{
		if (c[i] == '%')
		{
			valided_len = valid_format_check(&c[i]);
			if (!valided_len)
				return (INVLD_SYNTX);
			i = i + valided_len;
		}
		i++;
	}
	return (1);
}

/*
Check if the format is correct.
if the format is invalid, this function returns INVLD_SYTX
if the format is valid, this function returns format character position
*/
size_t	valid_format_check(char *c)
{
	size_t	i;

	i = 1;
	while (ft_strchr(" +-#0", c[i]))
		i++;
	while (ft_isdigit(c[i]))
		i++;
	if ((ft_strchr(".", c[i])))
		i++;
	while (ft_isdigit(c[i]))
		i++;
	if (ft_strchr("cspdiuxX%%", c[i]))
		return (i);
	else
		return (INVLD_SYNTX);
}

/*
This function checks valid flag.
If the flag is not valid, turn off the flag.
Return value is flags.
*/
unsigned int	validate_flg(char *c, size_t s_len, unsigned int flags)
{
	if (flags & MN_FLG && flags & ZR_FLG)
		flags &= ~ZR_FLG;
	if (flags & PLS_FLG && flags & SP_FLG)
		flags &= ~SP_FLG;
	if (flags & ZR_FLG && ft_strchr("csp%%", c[s_len]))
		flags &= ~ZR_FLG;
	if (flags & PLS_FLG && !ft_strchr("di%%", c[s_len]))
		flags &= ~PLS_FLG;
	if (flags & SP_FLG && !ft_strchr("di%%", c[s_len]))
		flags &= ~SP_FLG;
	if (flags & HASH_FLG && !ft_strchr("xX%%", c[s_len]))
		flags &= ~HASH_FLG;
	return (flags);
}
