/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:33:51 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/12 13:58:18 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	long	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	while (dst && *dst)
		dst++;
	if (dstsize <= src_len + dst_len)
	{
		while (i++ < ((long)dstsize - (long)dst_len - 1))
			*dst++ = *src++;
	}
	else
	{
		while (*src)
			*dst++ = *src++;
	}
	if (dst)
		*dst = '\0';
	if (dst_len < dstsize)
		return (dst_len + src_len);
	else
		return (src_len + dstsize);
}
