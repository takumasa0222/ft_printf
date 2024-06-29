/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_x_X_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:06:45 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/06/18 04:45:10 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//*/
#include <stdio.h>
#include <limits.h>
#include "../ft_printf.h"

// ft_printfの宣言
int ft_printf(const char *format, ...);

void test_x_printf() {
	int ret_ft, ret_std;
///*
	// テストケース 1
	ret_ft = ft_printf("1|%07x|\n", 456);
	ret_std = printf("1|%07x|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 2
	ret_ft = ft_printf("2|%.5x|\n", 456);
	ret_std = printf("2|%.5x|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 3
	ret_ft = ft_printf("3|%8.5x|\n", 456);
	ret_std = printf("3|%8.5x|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 4
	ret_ft = ft_printf("4|%-8.5x|\n", 456);
	ret_std = printf("4|%-8.5x|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 5
	ret_ft = ft_printf("5|%+-8.5x|\n", 456);
	ret_std = printf("5|%+-8.5x|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);
	    // テストケース 6
	ret_ft = ft_printf("6|%+8.5x|\n", 456);
	ret_std = printf("6|%+8.5x|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 7
	ret_ft = ft_printf("7|%+8.5x|\n", 456);
	ret_std = printf("7|%+8.5x|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 8
	ret_ft = ft_printf("8|%0 8x|\n", 456);
	ret_std = printf("8|%0 8x|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 9
	ret_ft = ft_printf("9|%0 8x|\n", 456);
	ret_std = printf("9|%0 8x|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 10
	ret_ft = ft_printf("10|%+-8.5x|\n", 456);
	ret_std = printf("10|%+-8.5x|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 11
	ret_ft = ft_printf("11|%x|\n", INT_MAX);
	ret_std = printf("11|%x|\n", INT_MAX);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 12
	ret_ft = ft_printf("12|%x|\n", UINT_MAX);
	ret_std = printf("12|%x|\n", UINT_MAX);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 13
	ret_ft = ft_printf("13|%x|\n", INT_MIN);
	ret_std = printf("13|%x|\n", INT_MIN);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 14
	ret_ft = ft_printf("14|%05x|\n", 0);
	ret_std = printf("14|%05x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// 追加のテストケース
	ret_ft = ft_printf("15|% x|\n", 456);
	ret_std = printf("15|% x|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

    // ret_ft = ft_printf("16|%#x|\n", 456);
    // ret_std = printf("16|%#x|\n", 456);
    // printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

    // ret_ft = ft_printf("17|%#X|\n", 456);
    // ret_std = printf("17|%#X|\n", 456);
    // printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);
	ret_ft = ft_printf("18|%-10x|\n", 456);
	ret_std = printf("18|%-10x|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("19|%010x|\n", 456);
	ret_std = printf("19|%010x|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("20|%.0x|\n", 0);
	ret_std = printf("20|%.0x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("21|%10.5x|\n", -456);
	ret_std = printf("21|%10.5x|\n", -456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("22|%.0x|\n", 456);
	ret_std = printf("22|%.0x|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("23|%.x|\n", 0);
	ret_std = printf("23|%.x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("24|%.2x|\n", 0);
	ret_std = printf("24|%.2x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("25|%1.x|\n", 0);
	ret_std = printf("25|%1.x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("26|%5.x|\n", -0);
	ret_std = printf("26|%5.x|\n", -0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("27|%5x|\n", 0);
	ret_std = printf("27|%5x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("28|%#x|\n", 10);
	ret_std = printf("28|%#x|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("29|%#5x|\n", 10);
	ret_std = printf("29|%#5x|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("30|%+#5x|\n", 10);
	ret_std = printf("30|%+#5x|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("31|%-#5x|\n", 10);
	ret_std = printf("31|%-#5x|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("32|% #5x|\n", 10);
	ret_std = printf("32|% #5x|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("33|%0#5x|\n", 10);
	ret_std = printf("33|%0#5x|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("34|%#.x|\n", 10);
	ret_std = printf("34|%#.x|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("35|%#.5x|\n", 10);
	ret_std = printf("35|%#.5x|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("36|%#8.5x|\n", 10);
	ret_std = printf("36|%#8.5x|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("37|%#5.8x|\n", 10);
	ret_std = printf("37|%#5.8x|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("38|%#-8.5x|\n", 10);
	ret_std = printf("38|%#-8.5x|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("39|%#x|\n", 0);
	ret_std = printf("39|%#x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("40|%#5x|\n", 0);
	ret_std = printf("40|%#5x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("41|%+#5x|\n", 0);
	ret_std = printf("41|%+#5x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("42|%-#5x|\n", 0);
	ret_std = printf("42|%-#5x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("43|% #5x|\n", 0);
	ret_std = printf("43|% #5x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("44|%0#5x|\n", 0);
	ret_std = printf("44|%0#5x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("45|%#.x|\n", 0);
	ret_std = printf("45|%#.x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("46|%#.5x|\n", 0);
	ret_std = printf("46|%#.5x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("47|%#8.5x|\n", 0);
	ret_std = printf("47|%#8.5x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("48|%#5.8x|\n", 0);
	ret_std = printf("48|%#5.8x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("49|%#-8.5x|\n", 0);
	ret_std = printf("49|%#-8.5x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("50|%#-4.x|\n", 0);
	ret_std = printf("50|%#-4.x|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);
}

void test_X_printf() {
	int ret_ft, ret_std;
///*
	// テストケース 1
	ret_ft = ft_printf("1|%07X|\n", 456);
	ret_std = printf("1|%07X|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 2
	ret_ft = ft_printf("2|%.5X|\n", 456);
	ret_std = printf("2|%.5X|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 3
	ret_ft = ft_printf("3|%8.5X|\n", 456);
	ret_std = printf("3|%8.5X|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 4
	ret_ft = ft_printf("4|%-8.5X|\n", 456);
	ret_std = printf("4|%-8.5X|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 5
	ret_ft = ft_printf("5|%+-8.5X|\n", 456);
	ret_std = printf("5|%+-8.5X|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);
	    // テストケース 6
	ret_ft = ft_printf("6|%+8.5X|\n", 456);
	ret_std = printf("6|%+8.5X|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 7
	ret_ft = ft_printf("7|%+8.5X|\n", 456);
	ret_std = printf("7|%+8.5X|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 8
	ret_ft = ft_printf("8|%0 8X|\n", 456);
	ret_std = printf("8|%0 8X|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 9
	ret_ft = ft_printf("9|%0 8X|\n", 456);
	ret_std = printf("9|%0 8X|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 10
	ret_ft = ft_printf("10|%+-8.5X|\n", 456);
	ret_std = printf("10|%+-8.5X|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 11
	ret_ft = ft_printf("11|%X|\n", INT_MAX);
	ret_std = printf("11|%X|\n", INT_MAX);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 12
	ret_ft = ft_printf("12|%X|\n", UINT_MAX);
	ret_std = printf("12|%X|\n", UINT_MAX);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 13
	ret_ft = ft_printf("13|%X|\n", INT_MIN);
	ret_std = printf("13|%X|\n", INT_MIN);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// テストケース 14
	ret_ft = ft_printf("14|%05X|\n", 0);
	ret_std = printf("14|%05X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	// 追加のテストケース
	ret_ft = ft_printf("15|% X|\n", 456);
	ret_std = printf("15|% X|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

    // ret_ft = ft_printf("16|%#X|\n", 456);
    // ret_std = printf("16|%#X|\n", 456);
    // printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

    // ret_ft = ft_printf("17|%#X|\n", 456);
    // ret_std = printf("17|%#X|\n", 456);
    // printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);
	ret_ft = ft_printf("18|%-10X|\n", 456);
	ret_std = printf("18|%-10X|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("19|%010X|\n", 456);
	ret_std = printf("19|%010X|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("20|%.0X|\n", 0);
	ret_std = printf("20|%.0X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("21|%10.5X|\n", -456);
	ret_std = printf("21|%10.5X|\n", -456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("22|%.0X|\n", 456);
	ret_std = printf("22|%.0X|\n", 456);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("23|%.X|\n", 0);
	ret_std = printf("23|%.X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("24|%.2X|\n", 0);
	ret_std = printf("24|%.2X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("25|%1.X|\n", 0);
	ret_std = printf("25|%1.X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("26|%5.X|\n", -0);
	ret_std = printf("26|%5.X|\n", -0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("27|%5X|\n", 0);
	ret_std = printf("27|%5X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("28|%#X|\n", 10);
	ret_std = printf("28|%#X|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("29|%#5X|\n", 10);
	ret_std = printf("29|%#5X|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("30|%+#5X|\n", 10);
	ret_std = printf("30|%+#5X|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("31|%-#5X|\n", 10);
	ret_std = printf("31|%-#5X|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("32|% #5X|\n", 10);
	ret_std = printf("32|% #5X|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("33|%0#5X|\n", 10);
	ret_std = printf("33|%0#5X|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("34|%#.X|\n", 10);
	ret_std = printf("34|%#.X|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("35|%#.5X|\n", 10);
	ret_std = printf("35|%#.5X|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("36|%#8.5X|\n", 10);
	ret_std = printf("36|%#8.5X|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("37|%#5.8X|\n", 10);
	ret_std = printf("37|%#5.8X|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("38|%#-8.5X|\n", 10);
	ret_std = printf("38|%#-8.5X|\n", 10);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("39|%#X|\n", 0);
	ret_std = printf("39|%#X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("40|%#5X|\n", 0);
	ret_std = printf("40|%#5X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("41|%+#5X|\n", 0);
	ret_std = printf("41|%+#5X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("42|%-#5X|\n", 0);
	ret_std = printf("42|%-#5X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("43|% #5X|\n", 0);
	ret_std = printf("43|% #5X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("44|%0#5X|\n", 0);
	ret_std = printf("44|%0#5X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("45|%#.X|\n", 0);
	ret_std = printf("45|%#.X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("46|%#.5X|\n", 0);
	ret_std = printf("46|%#.5X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("47|%#8.5X|\n", 0);
	ret_std = printf("47|%#8.5X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("48|%#5.8X|\n", 0);
	ret_std = printf("48|%#5.8X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("49|%#-8.5X|\n", 0);
	ret_std = printf("49|%#-8.5X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);

	ret_ft = ft_printf("50|%#-4.X|\n", 0);
	ret_std = printf("50|%#-4.X|\n", 0);
	printf("ft_printf return: %d, printf return: %d\n\n", ret_ft, ret_std);
}

int main() {
	test_x_printf();
	test_X_printf();
	return 0;
}
