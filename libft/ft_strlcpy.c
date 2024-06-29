/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 05:21:42 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/12 13:51:06 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned long	i;

	i = 0;
	if (!dst)
		return (ft_strlen(src));
	if (size != 0)
	{
		while (i + 1 < size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	if (size != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
