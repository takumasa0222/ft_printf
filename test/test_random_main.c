
#include <stdio.h>
#include <stdlib.h>
#include "../ft_printf.h"
#include <limits.h>

void test_printf(void) {
	char c = 'A';
	char *s = "hello";
	void *p = (void*)0x12345678;
	int d = 123;
	int i = -456;
	unsigned int u = 789;
	int x = 0xabc;
	int X = 0xDEF;
	char *null_str = NULL;
	void *null_ptr = NULL;
	int std_ret, ft_ret;

	// 基本的なフォーマット指定子のテストケース
	std_ret = printf("Hello, %s!\n", s);
	ft_ret = ft_printf("Hello, %s!\n", s);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Character: %c\n", c);
	ft_ret = ft_printf("Character: %c\n", c);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Pointer: %p\n", p);
	ft_ret = ft_printf("Pointer: %p\n", p);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Decimal: %d\n", d);
	ft_ret = ft_printf("Decimal: %d\n", d);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Integer: %i\n", i);
	ft_ret = ft_printf("Integer: %i\n", i);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Unsigned: %u\n", u);
	ft_ret = ft_printf("Unsigned: %u\n", u);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Hex (lowercase): %x\n", x);
	ft_ret = ft_printf("Hex (lowercase): %x\n", x);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Hex (uppercase): %X\n", X);
	ft_ret = ft_printf("Hex (uppercase): %X\n", X);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Percent sign: %%\n");
	ft_ret = ft_printf("Percent sign: %%\n");
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	// 幅と精度のテストケース
	std_ret = printf("Width and precision: %10.5d\n", d);
	ft_ret = ft_printf("Width and precision: %10.5d\n", d);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Width and precision: %.5d\n", d);
	ft_ret = ft_printf("Width and precision: %.5d\n", d);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Width and precision: %10.5s\n", s);
	ft_ret = ft_printf("Width and precision: %10.5s\n", s);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Width and precision: %.3s\n", s);
	ft_ret = ft_printf("Width and precision: %.3s\n", s);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	// フラグのテストケース
	std_ret = printf("Flags: %+d %+d % d\n", d, i, d);
	ft_ret = ft_printf("Flags: %+d %+d % d\n", d, i, d);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Left-aligned: %-10s\n", s);
	ft_ret = ft_printf("Left-aligned: %-10s\n", s);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Zero padding: %010d\n", d);
	ft_ret = ft_printf("Zero padding: %010d\n", d);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Hash flag: %#x %#X\n", x, X);
	ft_ret = ft_printf("Hash flag: %#x %#X\n", x, X);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Combination: %-10.5d\n", d);
	ft_ret = ft_printf("Combination: %-10.5d\n", d);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Combination: %010.5d\n", d);
	ft_ret = ft_printf("Combination: %010.5d\n", d);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Combination: %#010x\n", x);
	ft_ret = ft_printf("Combination: %#010x\n", x);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	// 符号付き、符号なし整数の境界値テストケース
	std_ret = printf("Signed int max: %d\n", 2147483647);
	ft_ret = ft_printf("Signed int max: %d\n", 2147483647);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Signed int min: %d\n", -2147483648);
	ft_ret = ft_printf("Signed int min: %d\n", -2147483648);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Unsigned int max: %u\n", 4294967295u);
	ft_ret = ft_printf("Unsigned int max: %u\n", 4294967295u);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Hex int max: %x\n", 0xffffffff);
	ft_ret = ft_printf("Hex int max: %x\n", 0xffffffff);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Hex int min: %x\n", 0x0);
	ft_ret = ft_printf("Hex int min: %x\n", 0x0);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Hex int max upper: %X\n", 0xffffffff);
	ft_ret = ft_printf("Hex int max upper: %X\n", 0xffffffff);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Hex int min upper: %X\n", 0x0);
	ft_ret = ft_printf("Hex int min upper: %X\n", 0x0);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	// 追加のフォーマット指定子テストケース
	std_ret = printf("String with width: %10s\n", "test");
	ft_ret = ft_printf("String with width: %10s\n", "test");
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Char with width: %5c\n", 'A');
	ft_ret = ft_printf("Char with width: %5c\n", 'A');
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Pointer with width: %20p\n", p);
	ft_ret = ft_printf("Pointer with width: %20p\n", p);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Negative width: %-10d\n", -123);
	ft_ret = ft_printf("Negative width: %-10d\n", -123);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Precision only: %.5d\n", 123);
	ft_ret = ft_printf("Precision only: %.5d\n", 123);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Width and zero padding: %010d\n", 123);
	ft_ret = ft_printf("Width and zero padding: %010d\n", 123);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Width, zero padding and precision: %010.5d\n", 123);
	ft_ret = ft_printf("Width, zero padding and precision: %010.5d\n", 123);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	// 特殊ケースのテストケース
	std_ret = printf("Null string: %s\n", null_str);
	ft_ret = ft_printf("Null string: %s\n", null_str);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Null pointer: %p\n", null_ptr);
	ft_ret = ft_printf("Null pointer: %p\n", null_ptr);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Empty string: %s\n", "");
	ft_ret = ft_printf("Empty string: %s\n", "");
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Empty format: \n");
	ft_ret = ft_printf("Empty format: \n");
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Multiple percent signs: %%%%\n");
	ft_ret = ft_printf("Multiple percent signs: %%%%\n");
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Escape percent: %s %% %d\n", "test", 123);
	ft_ret = ft_printf("Escape percent: %s %% %d\n", "test", 123);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("String with multiple format specifiers: %s %d %x\n", "test", 123, 0xabc);
	ft_ret = ft_printf("String with multiple format specifiers: %s %d %x\n", "test", 123, 0xabc);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Nested format: %s\n", "this is a test");
	ft_ret = ft_printf("Nested format: %s\n", "this is a test");
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	// 幅と精度の組み合わせテストケース
	std_ret = printf("Width and precision: %10.3d\n", 12345);
	ft_ret = ft_printf("Width and precision: %10.3d\n", 12345);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Width and precision: %10.3s\n", "hello");
	ft_ret = ft_printf("Width and precision: %10.3s\n", "hello");
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Width and precision: %10.3x\n", 0xabcdef);
	ft_ret = ft_printf("Width and precision: %10.3x\n", 0xabcdef);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Width and precision: %10.3X\n", 0xABCDEF);
	ft_ret = ft_printf("Width and precision: %10.3X\n", 0xABCDEF);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Width and precision: %10.3u\n", 12345);
	ft_ret = ft_printf("Width and precision: %10.3u\n", 12345);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Width and precision: %10.3i\n", -12345);
	ft_ret = ft_printf("Width and precision: %10.3i\n", -12345);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	// 幅、精度、フラグの組み合わせテストケース
	std_ret = printf("All combined: %-+10.5d\n", 123);
	ft_ret = ft_printf("All combined: %-+10.5d\n", 123);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("All combined: %0#10.5x\n", 0xabc);
	ft_ret = ft_printf("All combined: %0#10.5x\n", 0xabc);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("All combined: %+10.5d\n", 123);
	ft_ret = ft_printf("All combined: %+10.5d\n", 123);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("All combined: %#10.5X\n", 0xDEF);
	ft_ret = ft_printf("All combined: %#10.5X\n", 0xDEF);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("All combined: % 10.5u\n", 789);
	ft_ret = ft_printf("All combined: % 10.5u\n", 789);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	// より複雑なケース
	std_ret = printf("Complex case: %0-#10.5X\n", 0xabc);
	ft_ret = ft_printf("Complex case: %0-#10.5X\n", 0xabc);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Complex case: %0-#10.5x\n", 0xabc);
	ft_ret = ft_printf("Complex case: %0-#10.5x\n", 0xabc);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Complex case: %0-#10.5d\n", 12345);
	ft_ret = ft_printf("Complex case: %0-#10.5d\n", 12345);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Complex case: %0-#10.5i\n", -12345);
	ft_ret = ft_printf("Complex case: %0-#10.5i\n", -12345);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Complex case: %0-#10.5u\n", 12345);
	ft_ret = ft_printf("Complex case: %0-#10.5u\n", 12345);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Complex case: %0-#10.5s\n", "hello");
	ft_ret = ft_printf("Complex case: %0-#10.5s\n", "hello");
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}
}

void test_boundary_cases(void) {
	int std_ret, ft_ret;

	// 符号付き整数の境界値テストケース
	std_ret = printf("Signed int max: %d\n", 2147483647);
	ft_ret = ft_printf("Signed int max: %d\n", 2147483647);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Signed int min: %d\n", -2147483648);
	ft_ret = ft_printf("Signed int min: %d\n", -2147483648);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	// 符号なし整数の境界値テストケース
	std_ret = printf("Unsigned int max: %u\n", 4294967295u);
	ft_ret = ft_printf("Unsigned int max: %u\n", 4294967295u);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	// 境界を超えるテストケース
	long long ll_max = 9223372036854775807LL;
	long long ll_min = -9223372036854775807LL - 1;

	std_ret = printf("Long long max: %d\n", ll_max);
	ft_ret = ft_printf("Long long max: %d\n", ll_max);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Long long min: %d\n", ll_min);
	ft_ret = ft_printf("Long long min: %d\n", ll_min);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	unsigned long long ull_max = 18446744073709551615ULL;

	std_ret = printf("Unsigned long long max: %u\n", ull_max);
	ft_ret = ft_printf("Unsigned long long max: %u\n", ull_max);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	// 他の境界値テストケース
	std_ret = printf("Hex int max: %x\n", 0xffffffff);
	ft_ret = ft_printf("Hex int max: %x\n", 0xffffffff);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Hex int min: %x\n", 0x0);
	ft_ret = ft_printf("Hex int min: %x\n", 0x0);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Hex int max upper: %X\n", 0xffffffff);
	ft_ret = ft_printf("Hex int max upper: %X\n", 0xffffffff);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("Hex int min upper: %X\n", 0x0);
	ft_ret = ft_printf("Hex int min upper: %X\n", 0x0);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("long max: |%x|\n", LONG_MAX);
	ft_ret = ft_printf("long max: |%x|\n", LONG_MAX);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("long min: |%x| \n", LONG_MIN);
	ft_ret = ft_printf("long min: |%x| \n", LONG_MIN);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("ulong_max: |%x|\n", ULONG_MAX);
	ft_ret = ft_printf("ulong max: |%x|\n", ULONG_MAX);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("long long max: %x \n", 9223372036854775807LL);
	ft_ret = ft_printf("long long max: %x \n", 9223372036854775807LL);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("randomtest:\x01\x02\a\v\b\f\r\n");
	ft_ret = ft_printf("randomtest:\x01\x02\a\v\b\f\r\n");
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("long min: |%x| \n", LONG_MIN);
	ft_ret = ft_printf("long min: |%x| \n", LONG_MIN);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("ulong_max: |%x|\n", ULONG_MAX);
	ft_ret = ft_printf("ulong max: |%x|\n", ULONG_MAX);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("long long max: %x \n", 9223372036854775807LL);
	ft_ret = ft_printf("long long max: %x \n", 9223372036854775807LL);
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}
	std_ret = printf("invalid case1: %%%%%\n");
	ft_ret = ft_printf("invalid case1: %%%%%\n");
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}

	std_ret = printf("invalid case2: %qabos\n");
	ft_ret = ft_printf("invalid case2: %qabos\n");
	if (std_ret != ft_ret) {
		printf("\033[1;31m");
		printf("Return value: printf = %d, ft_printf = %d\n", std_ret, ft_ret);
		printf("\033[0m");
	}
}

verify_printf()
{
	char *str = NULL;
	printf("Null pointer: |%10.2p|\n", NULL);
	printf("Null pointer: %#10p\n", 0);
	printf("Null pointer: |%.2s|\n", str);

}

test_percent()
{
	printf("test|%%|\n");
	printf("test|%5%|\n");
	printf("test|%-5%|\n");
	printf("test|%05%|\n");
	printf("test|%+5%|\n");
	printf("test|%0 5%|\n");
	printf("test|%.5%|\n");
	printf("test|%8.5%|\n");
}

int main() {
	test_printf();
	test_boundary_cases();
	// verify_printf();

//	test_percent();
	return 0;
}
