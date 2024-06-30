/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_d_i_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:26:59 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/30 14:18:18 by tamatsuu         ###   ########.fr       */
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
	ret_ft = ft_printf("1|%07d|\n", 456);
	ret_std = printf("1|%07d|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 2
	ret_ft = ft_printf("2|%.5d|\n", 456);
	ret_std = printf("2|%.5d|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 3
	ret_ft = ft_printf("3|%8.5d|\n", 456);
	ret_std = printf("3|%8.5d|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 4
	ret_ft = ft_printf("4|%-8.5d|\n", 456);
	ret_std = printf("4|%-8.5d|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 5
	ret_ft = ft_printf("5|%+-8.5d|\n", 456);
	ret_std = printf("5|%+-8.5d|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);
	    // テストケース 6
	ret_ft = ft_printf("6|%+8.5d|\n", 456);
	ret_std = printf("6|%+8.5d|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 7
	ret_ft = ft_printf("7|%+8.5d|\n", 456);
	ret_std = printf("7|%+8.5d|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 8
	ret_ft = ft_printf("8|%0 8d|\n", 456);
	ret_std = printf("8|%0 8d|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 9
	ret_ft = ft_printf("9|%0 8d|\n", 456);
	ret_std = printf("9|%0 8d|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 10
	ret_ft = ft_printf("10|%+-8.5d|\n", 456);
	ret_std = printf("10|%+-8.5d|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 11
	ret_ft = ft_printf("11|%d|\n", INT_MAX);
	ret_std = printf("11|%d|\n", INT_MAX);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 12
	ret_ft = ft_printf("12|%d|\n", UINT_MAX);
	ret_std = printf("12|%d|\n", UINT_MAX);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 13
	ret_ft = ft_printf("13|%d|\n", INT_MIN);
	ret_std = printf("13|%d|\n", INT_MIN);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 14
	ret_ft = ft_printf("14|%05d|\n", 0);
	ret_std = printf("14|%05d|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// 追加のテストケース
	ret_ft = ft_printf("15|% d|\n", 456);
	ret_std = printf("15|% d|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

    // ret_ft = ft_printf("16|%#x|\n", 456);
    // ret_std = printf("16|%#x|\n", 456);
    // printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

    // ret_ft = ft_printf("17|%#X|\n", 456);
    // ret_std = printf("17|%#X|\n", 456);
    // printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);
	ret_ft = ft_printf("18|%-10d|\n", 456);
	ret_std = printf("18|%-10d|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("19|%010d|\n", 456);
	ret_std = printf("19|%010d|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("20|%.0d|\n", 0);
	ret_std = printf("20|%.0d|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("21|%10.5i|\n", -456);
	ret_std = printf("21|%10.5i|\n", -456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("22|%.0i|\n", 456);
	ret_std = printf("22|%.0i|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("23|%.i|\n", 0);
	ret_std = printf("23|%.i|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("24|%.2i|\n", 0);
	ret_std = printf("24|%.2i|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("25|%1.i|\n", 0);
	ret_std = printf("25|%1.i|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("26|%5.i|\n", -0);
	ret_std = printf("26|%5.i|\n", -0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("27|%5i|\n", 0);
	ret_std = printf("27|%5i|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);
// additional test
	ret_ft = ft_printf("28|%4.15d|\n", 42);
	ret_std = printf("28|%4.15d|\n", 42);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("29|%40.50d|\n", 50);
	ret_std = printf("29|%40.50d|\n", 50);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);


}

int main() {
    test_printf();
    return 0;
}
