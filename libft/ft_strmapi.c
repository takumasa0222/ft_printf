/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:50:19 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/03 14:02:15 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ans;
	unsigned int	i;
	size_t			size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	ans = (char *)malloc((size + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	i = 0;
	while (i < (unsigned int)size)
	{
		ans[i] = f(i, s[i]);
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
