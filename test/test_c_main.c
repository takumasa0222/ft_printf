/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:26:59 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/18 04:45:25 by tamatsuu         ###   ########.fr       */
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
	ret_ft = ft_printf("1|%07c|\n", 'a');
	ret_std = printf("1|%07c|\n", 'a');
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 2
	ret_ft = ft_printf("2|%.5c|\n", 'a');
	ret_std = printf("2|%.5c|\n", 'a');
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 3
	ret_ft = ft_printf("3|%8.5c|\n", 'a');
	ret_std = printf("3|%8.5c|\n", 'a');
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 4
	ret_ft = ft_printf("4|%-8.5c|\n", 'a');
	ret_std = printf("4|%-8.5c|\n", 'a');
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 5
	ret_ft = ft_printf("5|%+-8.5c|\n", 'a');
	ret_std = printf("5|%+-8.5c|\n", 'a');
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);
	    // テストケース 6
	ret_ft = ft_printf("6|%+8.5c|\n", 'a');
	ret_std = printf("6|%+8.5c|\n", 'a');
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 7
	ret_ft = ft_printf("7|%+8.5c|\n", 'a');
	ret_std = printf("7|%+8.5c|\n", 'a');
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 8
	ret_ft = ft_printf("8|%0 8c|\n", 'a');
	ret_std = printf("8|%0 8c|\n", 'a');
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 9
	ret_ft = ft_printf("9|%0 8c|\n", 'a');
	ret_std = printf("9|%0 8c|\n", 'a');
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 10
	ret_ft = ft_printf("10|%+-8.5c|\n", 'a');
	ret_std = printf("10|%+-8.5c|\n", 'a');
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 11
	ret_ft = ft_printf("11|%c|\n", INT_MAX);
	ret_std = printf("11|%c|\n", INT_MAX);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 12
	ret_ft = ft_printf("12|%c|\n", UINT_MAX);
	ret_std = printf("12|%c|\n", UINT_MAX);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 13
	ret_ft = ft_printf("13|%c|\n", INT_MIN);
	ret_std = printf("13|%c|\n", INT_MIN);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 14
	ret_ft = ft_printf("14|%05c|\n", 0);
	ret_std = printf("14|%05c|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// 追加のテストケース
	ret_ft = ft_printf("15|% c|\n", 'a');
	ret_std = printf("15|% c|\n", 'a');
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

    // ret_ft = ft_printf("16|%#x|\n", 'a');
    // ret_std = printf("16|%#x|\n", 'a');
    // printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

    // ret_ft = ft_printf("17|%#X|\n", 'a');
    // ret_std = printf("17|%#X|\n", 'a');
    // printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);
	ret_ft = ft_printf("18|%-10c|\n", 'a');
	ret_std = printf("18|%-10c|\n", 'a');
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("19|%010c|\n", 'a');
	ret_std = printf("19|%010c|\n", 'a');
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("20|%.0c|\n", 0);
	ret_std = printf("20|%.0c|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("21|%10.5c|\n", -'a');
	ret_std = printf("21|%10.5c|\n", -'a');
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("22|%.0c|\n", 'a');
	ret_std = printf("22|%.0c|\n", 'a');
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("23|%.c|\n", 0);
	ret_std = printf("23|%.c|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("24|%.2c|\n", 0);
	ret_std = printf("24|%.2c|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("25|%1.c|\n", 0);
	ret_std = printf("25|%1.c|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("26|%5.c|\n", -0);
	ret_std = printf("26|%5.c|\n", -0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("27|%5c|\n", 0);
	ret_std = printf("27|%5c|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);
}

int main() {
    test_printf();
    return 0;
}
