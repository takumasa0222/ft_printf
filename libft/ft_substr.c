/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:08:04 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/19 20:48:43 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	lencheck(size_t len, size_t str_len, unsigned int start, char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;
	unsigned int	j;
	size_t			str_len;

	if (!s || len > SIZE_MAX)
		return (NULL);
	str_len = ft_strlen(s);
	len = lencheck(len, str_len, start, (char *)s);
	ret = malloc(len * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (i < start && i < (unsigned int)ft_strlen(s))
		i++;
	while (j < len && s[i] && j < len - 1)
	{
		ret[j] = s[i];
		j++;
		i++;
	}
	ret[j] = '\0';
	return (ret);
}

size_t	lencheck(size_t len, size_t str_len, unsigned int start, char *s)
{
	if (str_len <= start || len == 0)
		return (1);
	if (str_len < len)
	{
		if (*s == '\0')
			return (1);
		if (str_len < len - start)
			return (str_len - start + 1);
		return (str_len + 1);
	}
	if (start + len > str_len)
		return (str_len - start + 1);
	return (len + 1);
}
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%s\n",ft_substr("hola", 0, 0));//1
// 	printf("%s\n",ft_substr("hola", 0, 1));//2 h
// 	printf("%s\n",ft_substr("hola", 4, 20));//1
// 	printf("%s\n",ft_substr("hola", 2, 3));//3 la
// 	printf("%s\n",ft_substr("hola", 3, 2));//2 a
// 	printf("%s\n",ft_substr("hola", 2, 30));//3 la
// 	printf("%s\n",ft_substr("hola", 2, 0));//1
// 	printf("%s\n",ft_substr("hola", 2, 1));//2 l
// 	printf("%s\n",ft_substr("hola", 3, 0));//1
// }
