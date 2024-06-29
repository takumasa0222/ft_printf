/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:26:59 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/29 22:59:23 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//*/
#include <stdio.h>
#include <limits.h>
#include "../ft_printf.h"

// ft_printfの宣言
int ft_printf(const char *format, ...);

void test_printf() {
	int ret_ft, ret_std;
///*
	// テストケース 1
	ret_ft = ft_printf("1|%07s|\n", "Hello");
	ret_std = printf("1|%07s|\n", "Hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 2
	ret_ft = ft_printf("2|%.5s|\n", "Hello");
	ret_std = printf("2|%.5s|\n", "Hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 3
	ret_ft = ft_printf("3|%8.5s|\n", "Hello");
	ret_std = printf("3|%8.5s|\n", "Hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 4
	ret_ft = ft_printf("4|%-8.5s|\n", "Hello");
	ret_std = printf("4|%-8.5s|\n", "Hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 5
	ret_ft = ft_printf("5|%+-8.5s|\n", "Hello");
	ret_std = printf("5|%+-8.5s|\n", "Hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);
	// テストケース 6
	ret_ft = ft_printf("6|%+8.5s|\n", "Hello");
	ret_std = printf("6|%+8.5s|\n", "Hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 7
	ret_ft = ft_printf("7|%+8.5s|\n", "Hello");
	ret_std = printf("7|%+8.5s|\n", "Hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 8
	ret_ft = ft_printf("8|%0 8s|\n", "Hello");
	ret_std = printf("8|%0 8s|\n", "Hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 9
	ret_ft = ft_printf("9|%0 8s|\n", "Hello");
	ret_std = printf("9|%0 8s|\n", "Hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 10
	ret_ft = ft_printf("10|%+-8.3s|\n", "Hello");
	ret_std = printf("10|%+-8.3s|\n", "Hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 11
	ret_ft = ft_printf("11|%s|\n", NULL);
	ret_std = printf("11|%s|\n", NULL);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 12
	ret_ft = ft_printf("12|%8s|\n", NULL);
	ret_std = printf("12|%8s|\n", NULL);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 13
	ret_ft = ft_printf("13|%08s|\n", NULL);
	ret_std = printf("13|%08s|\n", NULL);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 14
	ret_ft = ft_printf("14|%05s|\n", 0);
	ret_std = printf("14|%05s|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// 追加のテストケース
	ret_ft = ft_printf("15|% s|\n", "Hello");
	ret_std = printf("15|% s|\n", "Hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("16|%.s|\n", "Hello");
    ret_std = printf("16|%.s|\n", "Hello");
    printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

    ret_ft = ft_printf("17|%.4s|\n", "Hello");
    ret_std = printf("17|%.4s|\n", "Hello");
    printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("18|%-10s|\n", "Hello");
	ret_std = printf("18|%-10s|\n", "Hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("19|%010s|\n", "Hello");
	ret_std = printf("19|%010s|\n", "Hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("20|%.0s|\n", 0);
	ret_std = printf("20|%.0s|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("21|%10.5s|\n", "Hello");
	ret_std = printf("21|%10.5s|\n", "Hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("22|%.0s|\n", "Hello");
	ret_std = printf("22|%.0s|\n", "Hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("23|%.s|\n", 0);
	ret_std = printf("23|%.s|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("24|%.2s|\n", 0);
	ret_std = printf("24|%.2s|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("25|%1.s|\n", 0);
	ret_std = printf("25|%1.s|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("26|%5.s|\n", -0);
	ret_std = printf("26|%5.s|\n", -0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("27|%5s|\n", 0);
	ret_std = printf("27|%5s|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("28|%5.1s|\n", "hello");
	ret_std = printf("28|%5.1s|\n", "hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("29|%.7s%.2s|\n", "hello", "world");
	ret_std = printf("29|%.7s%.2s|\n", "hello", "world");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("30|%.5s%7s|\n", "yo", "boi");
	ret_std = printf("30|%.5s%7s|\n", "yo", "boi");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("31|%-7.5s|\n", "yolo");
	ret_std = printf("31|%-7.5s|\n", "yolo");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("28|%5.1s|\n", "hello");
	ret_std = printf("28|%5.1s|\n", "hello");
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

}

int	main(void)
{
	test_printf();
	return (0);
}
