/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_p_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:29:01 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/18 04:45:18 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "../ft_printf.h"

// ft_printfの宣言

///*

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// あなたのft_printfのヘッダーをインクルード
#include "../libftprintf.h"

void	test_printf(void)
{
	char c;
	char *d = NULL;
	int std_ret, ft_ret;

	c = 'c';

	// std_ret = printf("|%p|\n", &c);
	// ft_ret = ft_printf("|%p|\n", &c);
	// printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// std_ret = printf("|%#18p|\n", &c);
	// ft_ret = ft_printf("|%#18p|\n", &c);
	// printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	std_ret = printf("|%018p|\n", &c);
	ft_ret = ft_printf("|%018p|\n", &c);
	printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// std_ret = printf("|%-18p|\n", &c);
	// ft_ret = ft_printf("|%-18p|\n", &c);
	// printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// std_ret = printf("|%-4.18p|\n", &d);
	// ft_ret = ft_printf("|%-4.18p|\n", &d);
	// printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// std_ret = printf("|%25.18p|\n", &d);
	// ft_ret = ft_printf("|%25.18p|\n", &d);
	// printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// std_ret = printf("|%#p|\n", d);
	// ft_ret = ft_printf("|%#p|\n", d);
	// printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	std_ret = printf("|%05p|\n", d);
	ft_ret = ft_printf("|%05p|\n", d);
	printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// std_ret = printf("|%5.8p|\n", d);
	// ft_ret = ft_printf("|%5.8p|\n", d);
	// printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// std_ret = printf("|%8p|\n", d);
	// ft_ret = ft_printf("|%8p|\n", d);
	// printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// std_ret = printf("|%-8p|\n", d);
	// ft_ret = ft_printf("|%-8p|\n", d);
	// printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// std_ret = printf("|%-8.4p|\n", d);
	// ft_ret = ft_printf("|%-8.4p|\n", d);
	// printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// std_ret = printf("|%-+8.4p|\n", d);  // このフォーマットはprintfでは未定義の動作を引き起こすかもしれません
	// ft_ret = ft_printf("|%-+8.4p|\n", d);  // このフォーマットもft_printfで未定義の動作を引き起こすかもしれません
	// printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// std_ret = printf("|%- 8.4p|\n", d);  // このフォーマットもprintfでは未定義の動作を引き起こすかもしれません
	// ft_ret = ft_printf("|%- 8.4p|\n", d);  // このフォーマットもft_printfで未定義の動作を引き起こすかもしれません
	// printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// std_ret = printf("|%-4.8p|\n", d);
	// ft_ret = ft_printf("|%-4.8p|\n", d);
	// printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

}

//*/
void	check_printf()
{
	char	c;
	char	*d = NULL;

	c = 'c';
	printf("|%p|\n",&c);
	printf("|%#18p|\n",&c);
	printf("|%018p|\n",&c);
	printf("|%-18p|\n",&c);
	printf("|%-4.18p|\n",&d);
	printf("|%25.18p|\n",&d);
	printf("|%#p|\n",d);
	printf("|%05p|\n",d);
	printf("|%5.8p|\n",d);
	printf("|%8p|\n",d);
	printf("|%-8p|\n",d);
	printf("|%-8.4p|\n",d);
	printf("|%-+8.4p|\n",d);
	printf("|%- 8.4p|\n",d);
	printf("|%-4.8p|\n",d);

}


int	main(void)
{
	test_printf();
	//check_printf();
	return (0);
}
