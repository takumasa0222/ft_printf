/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:55:18 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/12 18:22:06 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char_find(char const *set, int s);

char	*ft_strtrim(char const *s1, char const *set)
{
	long	s_len;
	char	*ret;
	int		i;

	if (!s1 || !set)
		return (NULL);
	s_len = (long)ft_strlen(s1) - 1;
	i = 0;
	while (s1[i] && ft_char_find(set, s1[i]))
		i++;
	if (i == s_len + 1)
	{
		ret = (char *)malloc(1 * sizeof(char));
		if (!ret)
			return (NULL);
		return (*ret = '\0', ret);
	}
	while (s1[s_len] && ft_char_find(set, s1[s_len]))
		s_len--;
	ret = malloc((s_len - i + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, &(s1[i]), (s_len - i + 2));
	return (ret);
}

int	ft_char_find(char const *set, int s)
{
	int	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char *s1 = "  \t \t \n   \n\n\n\t";
// 	char *s2 = "";
// 	char *ret = ft_strtrim(s1, " \n\t");

// 	if (!strcmp(ret, s2))
// 		printf("false %s\n", ret);
// 	else
// 		printf("true");
// }