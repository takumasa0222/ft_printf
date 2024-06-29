/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 23:03:47 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/12 18:21:47 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t			len;
	unsigned int	i;

	i = 0;
	len = 0;
	if (!s)
		return (i);
	while (s[i])
	{
		len++;
		i++;
	}
	return (len);
}
