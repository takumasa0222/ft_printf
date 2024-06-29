/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:42:50 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/07 20:25:15 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	char			*ret;
	unsigned int	i;
	unsigned int	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
		ret[i++] = s2[j++];
	ret[i] = '\0';
	return (ret);
}
