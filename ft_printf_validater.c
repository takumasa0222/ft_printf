/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_validater.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:22:44 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/09 23:37:16 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

int	check_all_validations(char *c, va_list *args)
{
	size_t	s_len;

	while (*c)
	{
		if (c == '%')
		{
			s_len = validate_format_sp(*c);
			if (s_len == INVLD_SYNTX \
			|| !validate_flg(*c, s_len, fmt) \
			|| !validate_min_fld() \
			|| !validate_precision())
				return (INVLD_SYNTX);
		}
		c++;
	}
	return (1);
}

//check if format specifier exist
size_t	validate_format_sp(char *c)
{
	size_t	i;

	i = 0;
	while (c[++i])
	{
		if (ft_strchr("cpdiuxX%", c[i]))
			return (i);
	}
	return (INVLD_SYNTX);
}

unsigned int	validate_flg(char *c, size_t s_len, t_format *fmt)
{
	size_t			i;
	int				flg_cnt;
	unsigned int	flags;

	i = 0;
	if (s_len < 2)
		return (NO_FLG);
	flg_cnt = 0;
	flags = 0;
	while (i < s_len && ft_strchr("-+ 0#", c[i]) && c[i])
		flags = set_flg(c[i], flags);
	if (ft_strchr("%", fmt->fmt_sp))
		return (flags);
	if (flags & MN_FLG && flags & ZR_FLG || flags & PLS_FLG && flags & SP_FLG)
		return (INVLD_SYNTX);
	if (flags & ZR_FLG && ft_strchr("csp", fmt->fmt_sp))
		return (INVLD_SYNTX);
	if (flags & PLS_FLG && !ft_strchr("di", fmt->fmt_sp) \
		|| flags & SP_FLG && !ft_strchr("di", fmt->fmt_sp))
		return (INVLD_SYNTX);
	if (flags & HASH_FLG && !ft_strchr("xX", fmt->fmt_sp))
		return (INVLD_SYNTX);
	return (flags);
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
// #include <stdio.h>
// int	main(void)
// {
// 	unsigned int flags;

// 	flags = 0;
// 	flags = set_flg(' ',flags);
// 	flags = set_flg('x',flags);
// 	flags = set_flg('+',flags);
// 	flags = set_flg('0',flags);
// 	flags = set_flg('a',flags);
// 	printf("%u", flags);
// }