/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:55:16 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/12 14:49:17 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *heystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!*needle)
		return ((char *)heystack);
	while (i < len && heystack[i])
	{
		j = 0;
		while (heystack[i] == needle[j] && i < len)
		{
			if (j == ft_strlen(needle) - 1)
				return ((char *)&(heystack[i - j]));
			if (!heystack[i])
				return (NULL);
			i++;
			j++;
		}
		i = i - j + 1;
	}
	return (NULL);
}
