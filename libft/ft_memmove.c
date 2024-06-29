/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 04:07:25 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/04/22 06:03:38 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*destcpy;
	unsigned char	*srccpy;

	destcpy = (unsigned char *)dest;
	srccpy = (unsigned char *)src;
	if (!dest || !src || src == dest || size == 0)
		return (dest);
	if (dest > src)
	{
		destcpy = destcpy + size - 1;
		srccpy = srccpy + size - 1;
		while (size--)
			*destcpy-- = *srccpy--;
	}
	else
	{
		while (size--)
			*destcpy++ = *(unsigned char *)src++;
	}
	return (dest);
}
