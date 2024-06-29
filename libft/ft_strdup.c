/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:43:28 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/04/23 20:46:24 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	src_len;
	char	*ret;

	if (!s1)
		return (NULL);
	src_len = ft_strlen(s1);
	ret = malloc((src_len + 1) * sizeof (char));
	if (!ret)
		return (NULL);
	while (*s1)
		*ret++ = *s1++;
	*ret = '\0';
	return (ret - src_len);
}
