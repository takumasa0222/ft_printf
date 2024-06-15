/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_validater.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:22:44 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/16 04:07:46 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"


int	check_all_format(char *c)
{
	while (*c)
	{
		if (*c == '%')
		{
			if (!valid_format_check(c))
				return (INVLD_SYNTX);
		}
		c++;
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
	if (ft_strchr("cpdiuxX%%", c[i]))
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


/*
#include <stdio.h>
int	main(void)
{
	// unsigned int	flags;

	// flags = 0;
	// flags = set_flg(' ',flags);
	// flags = set_flg('x',flags);
	// flags = set_flg('+',flags);
	// flags = set_flg('0',flags);
	// flags = set_flg('a',flags);
	//	printf("%u", flags);

	// check validate_format_sp(char *c)
	// printf("%ld\n",validate_format_sp("%d"));
	// printf("%ld\n",validate_format_sp("%a"));
	// printf("%ld\n",validate_format_sp("%03.5d"));
	// printf("%ld\n",validate_format_sp("%0d"));
	// printf("%ld\n",validate_format_sp("%+4d"));
	// printf("%ld\n",validate_format_sp("%+5.d"));
	// printf("%ld\n",validate_format_sp("%+.d"));
	// printf("%ld\n",validate_format_sp("%+.4d"));
	// printf("%ld\n",validate_format_sp("%7.9d"));
	// printf("%ld\n",validate_format_sp("%7d"));
	// printf("%ld\n",validate_format_sp("%8.d"));
	// printf("%ld\n",validate_format_sp("%.3d"));
	// printf("%ld\n",validate_format_sp("%%"));
	// printf("%ld\n",validate_format_sp("%+5.00001d"));

	//invalid case
	printf("%ld\n",validate_format_sp("%e.d"));
	printf("%ld\n",validate_format_sp("% +-012345.12345q"));
	printf("%ld\n",validate_format_sp("%0\2003.5d"));
	printf("%ld\n",validate_format_sp("%00000.00-0d"));
	printf("%ld\n",validate_format_sp("%+4..d"));
	printf("%ld\n",validate_format_sp("%+.d"));
	printf("%ld\n",validate_format_sp("%+.4d"));
	printf("%ld\n",validate_format_sp("%7.9d"));
	printf("%ld\n",validate_format_sp("%7d"));
	printf("%ld\n",validate_format_sp("%8.d"));
	printf("%ld\n",validate_format_sp("%.3d"));
	printf("%ld\n",validate_format_sp("%.d"));
}
*/