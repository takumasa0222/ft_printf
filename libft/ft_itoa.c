/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 02:40:07 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/03 12:46:05 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_pstv_int_pow(unsigned int x, unsigned int y);
int				ft_get_digit_size(int n);
unsigned int	ft_abs_int(int i);

char	*ft_itoa(int n)
{
	char	*ans;
	int		i;
	int		size;

	size = ft_get_digit_size(n);
	ans = (char *)malloc((size + 1) * sizeof (char));
	if (!ans)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		ans[i++] = '-';
		size = size - 1;
	}
	while (0 < size--)
	{
		if (n != 0)
			ans[i++] = ft_abs_int(n) / ft_pstv_int_pow(10, size) + 48;
		else
			ans[i++] = 48;
		if (n != 0)
			n = ft_abs_int(n) % ft_pstv_int_pow(10, size);
	}
	return (ans[i] = '\0', ans);
}

unsigned int	ft_abs_int(int i)
{
	unsigned int	ans;

	if (i < 0)
	{
		ans = i * -1;
		return (ans);
	}
	return ((unsigned int) i);
}

unsigned long	ft_pstv_int_pow(unsigned int x, unsigned int y)
{
	unsigned long	ans;
	unsigned int	i;

	i = 1;
	ans = (unsigned long)x;
	if (y == 0)
	{
		return (1);
	}
	while (i < y)
	{
		ans = ans * x;
		i++;
	}
	return (ans);
}

int	ft_get_digit_size(int n)
{
	long	i;
	int		dig_size;
	int		j;

	i = n;
	dig_size = 0;
	j = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i = i * -1;
		dig_size = dig_size + 1;
	}
	if (i < 10)
		return (dig_size + 1);
	while (10 <= i / ft_pstv_int_pow(10, j))
		j++;
	return (j + dig_size + 1);
}

// #include <stdio.h>
// void test(int a)
// {
// 	char *test = ft_itoa(a);
// 	printf("testresult %s\n",test);
// 	free(test);
// }

// int	main(void)
// {
// 	test(0);
// 	test(10);
// 	test(100);
// 	test(9999);
// 	test(-111110);
// 	test(-2147483648);
// 	test(2147483647);
// }