/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 04:46:08 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/03 13:55:17 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	size_t	i;
	char	*s_cpy;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	s_cpy = s_len + (char *)s;
	i = 0;
	while (i <= s_len)
	{
		if (*s_cpy == (unsigned char)c)
			return (s_cpy);
		if (i != s_len)
			s_cpy--;
		i++;
	}
	return (NULL);
}
