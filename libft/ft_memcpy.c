/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 02:19:40 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/04/22 06:02:49 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*destcpy;

	i = 0;
	destcpy = (unsigned char *)dest;
	if (!dest || !src)
		return (dest);
	while (i < size)
	{
		*destcpy = *(unsigned char *)src;
		destcpy++;
		src++;
		i++;
	}
	return (dest);
}
