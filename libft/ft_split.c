/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:49:43 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/19 21:04:07 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_sep_cnt(char const *str, char dlm);
char	*push_word(char const *str, int size);
int		validate_words(char **mem, int cnt);
int		ft_is_not_chr(char const *str, char c);

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		size;
	int		i;
	int		k;

	ans = (char **)malloc(sizeof (char *) * (get_sep_cnt(s, c) + 1));
	if (!ans || !s)
		return (free(ans), NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		size = ft_is_not_chr(&(s[i]), c);
		i = i + size;
		if (size != 0 && k <= (get_sep_cnt(s, c)))
			ans[k++] = push_word(&(s[i - size]), size);
		if (validate_words(ans, k - 1))
			return (NULL);
		size = 0;
		while ((s[i] == c) && s[i])
			i++;
	}
	ans[k] = NULL;
	return (ans);
}

int	get_sep_cnt(char const *str, char dlm)
{
	int	i;
	int	sp_cnt;

	i = 0;
	if (!str || !str[i])
		return (0);
	if (ft_strlen(str) == 1)
		return (1);
	sp_cnt = 0;
	while (str[i])
	{
		while (str[i] == dlm && str[i])
			i++;
		if (!str[i])
			break ;
		while (str[i] != dlm && str[i])
			i++;
		sp_cnt++;
	}
	return (sp_cnt);
}

int	validate_words(char **mem, int cnt)
{
	int				i;

	i = 0;
	if (!mem)
		return (1);
	if (cnt < 0)
		return (0);
	if (mem[cnt] == NULL)
	{
		while (i <= cnt)
		{
			free(mem[i]);
			i++;
		}
		free(mem);
		return (1);
	}
	return (0);
}

int	ft_is_not_chr(char const *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != c && str[i])
		i++;
	return (i);
}

char	*push_word(char const *str, int size)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	while (i < size && str)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
//
// int	main(void)
// {
// 	char	str[] = "ab";
// 	char	str1[] = "aabcdaa";
// 	char	str2[] = "abcdea";
// 	char	str3[] = "abcdef";
// 	char	str4[] = "";
// 	char	str5[] = "a";
// 	char	str6[] = "aabbaacc";
// 	char	str7[] = "efhg";
// 	char	*str8 = NULL;
// 	char	str10[] = "aabbaaccaaaa";
// 	char	test1 = 'a';
// 	char	test2 = '\0';

// 	printf("test0 for get_sep_cnt %d\n" ,get_sep_cnt(str, test1));
// 	printf("test1 for get_sep_cnt %d\n" ,get_sep_cnt(str1, test1));
// 	printf("test2 for get_sep_cnt %d\n" ,get_sep_cnt(str2, test1));
// 	printf("test3 for get_sep_cnt %d\n" ,get_sep_cnt(str3, test1));
// 	printf("test4 for get_sep_cnt %d\n" ,get_sep_cnt(str4, test1));
// 	printf("test5 for get_sep_cnt %d\n" ,get_sep_cnt(str5, test1));
// 	printf("test6 for get_sep_cnt %d\n" ,get_sep_cnt(str6, test1));
// 	printf("test7 for get_sep_cnt %d\n" ,get_sep_cnt(str7, test1));
// 	printf("test8 for get_sep_cnt %d\n" ,get_sep_cnt(str8, test1));
// 	printf("test9 for get_sep_cnt %d\n" ,get_sep_cnt(str4, test2));
// 	printf("test10 for get_sep_cnt %d\n" ,get_sep_cnt(str10, test1));
// 	printf("test11 for get_sep_cnt %d\n" ,get_sep_cnt("", ' '));
// 	printf("test12 for get_sep_cnt %d\n" ,get_sep_cnt("ggggggggggg", 'g'));

// 	test(ft_split(str, test1));
// 	test(ft_split(str1, test1));
// 	test(ft_split(str2, test1));
// 	test(ft_split(str3, test1));
// 	test(ft_split(str4, test1));
// 	test(ft_split(str5, test1));
// 	test(ft_split(str6, test1));
// 	test(ft_split(str7, test1));
// 	test(ft_split(str8, test1));
// 	test(ft_split(str4, test2));
// 	test(ft_split(str10, test1));
// 	test(ft_split("", ' '));
// 	test(ft_split("ggggggggggg", 'g'));
// }