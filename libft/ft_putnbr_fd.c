/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:40:02 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/19 22:18:23 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	cpy_n;

	cpy_n = n;
	if (cpy_n < 0)
	{
		cpy_n = cpy_n * -1;
		ft_putchar_fd('-', fd);
	}
	if (cpy_n > 9)
	{
		ft_putnbr_fd(cpy_n / 10, fd);
		cpy_n = cpy_n % 10;
	}
	if (cpy_n < 10)
		ft_putchar_fd((cpy_n + 48), fd);
}

// #include <stdio.h>
// int	main(void)
// {
// 	ft_putnbr_fd(1, 2);
// 	printf("\n");
// 	ft_putnbr_fd(2147483647, 2);
// 	printf("\n");
// 	ft_putnbr_fd(2147483648, 2);
// 	printf("\n");
// 	ft_putnbr_fd(0, 2);
// 	printf("\n");
// 	ft_putnbr_fd(-100000000, 2);
// 	printf("\n");
// 	ft_putnbr_fd(1, 1);
// }
