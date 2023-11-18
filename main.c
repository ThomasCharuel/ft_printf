#include "ft_printf_bonus.h"
#include <assert.h>
#include <stdio.h>

#define LONG_MIN (-__LONG_MAX__ - 1L)
#define LONG_MAX __LONG_MAX__

void	test1(int (*printf_func)(const char *, ...))
{
	int	res;

	// res = printf_func(NULL);
	// printf("\n%d\n", res);
	// res = printf_func("");
	// printf("\n%d\n", res);
	// res = printf_func("hello");
	// printf("\n%d\n", res);
	// res = printf_func("hel%^lo");
	// printf("\n%d\n", res);
	// res = printf_func("hello%");
	// printf("\n%d\n", res);
	// res = printf_func("hello%s et %s", " Thomas", "Made");
	// printf("\n%d\n", res);
	// res = printf_func("hello%s", NULL);
	// printf("\n%d\n", res);
	res = printf_func("hello %c et %c.", NULL, 'D');
	printf("\n%d\n", res);
	res = printf_func("Precision: %32768dYo", 999);
	printf("\n%d\n", res);
}

void	test_sharp(int (*printf_func)(const char *, ...))
{
	int	res;

	res = printf_func("hello %x et %#x.", 3, 3);
	printf("\n%d\n", res);
	// res = printf_func("hello %x et %#x.", 0, 0);
	// printf("\n%d\n", res);
	// res = printf_func("hello %x et %#x.", -3, -3);
	// printf("\n%d\n", res);
	// res = printf_func(" %#x ", -1);
	// printf("\n%d\n", res);
}

void	test_blank(int (*printf_func)(const char *, ...))
{
	int	res;

	res = printf_func("hello %d et % d.", 3, 3);
	printf("\n%d\n", res);
	res = printf_func("hello %d et % d.", 0, 0);
	printf("\n%d\n", res);
	res = printf_func("hello %d et % d.", -3, -3);
	printf("\n%d\n", res);
	res = printf_func("hello %u et % u.", 3, 3);
	printf("\n%d\n", res);
	res = printf_func("hello %u et % u.", 0, 0);
	printf("\n%d\n", res);
	res = printf_func("hello %u et % u.", -3, -3);
	printf("\n%d\n", res);
	res = printf_func(" % 1s", "");
	printf("\n%d\n", res);
}

void	test_plus(int (*printf_func)(const char *, ...))
{
	int	res;

	res = printf_func("hello %d et % d et % +d et %+d.", 3, 3, 3, 3);
	printf("\n%d\n", res);
	res = printf_func("hello %d et % d et % +d et %+d.", 0, 0, 0, 0);
	printf("\n%d\n", res);
	res = printf_func("hello %d et % d et % +d et %+d.", -3, -3, -3, -3);
	printf("\n%d\n", res);
	res = printf_func("hello %u et % u et % +u et %+u.", 3, 3, 3, 3);
	printf("\n%d\n", res);
	res = printf_func("hello %u et % u et % +u et %+u.", 0, 0, 0, 0);
	printf("\n%d\n", res);
	res = printf_func("hello %u et % u et % +u et %+u.", -3, -3, -3, -3);
	printf("\n%d\n", res);
}

void	test_width(int (*printf_func)(const char *, ...))
{
	int	res;

	res = printf_func(" %04d ;", -14);
	printf("\n%d\n", res);
	res = printf_func(" %4d ;", -14);
	printf("\n%d\n", res);
}
void	test_minus(int (*printf_func)(const char *, ...))
{
	int	res;

	res = printf_func("%-4chello\n", 0);
	printf("%d\n", res);
}

void	test_dot(int (*printf_func)(const char *, ...))
{
	int	res;

	res = printf_func("%.d", 0);
	printf_func("\n%d\n", res);
	res = printf_func("%.0d", 0);
	printf_func("\n%d\n", res);
	res = printf_func("%.5d", 2);
	printf_func("\n%d\n", res);
	res = printf_func("%.5u", 2);
	printf_func("\n%d\n", res);
	res = printf_func("%.5x", 2);
	printf_func("\n%d\n", res);
	res = printf_func("%.5X", 2);
	printf_func("\n%d\n", res);
	res = printf_func("%#.5X", 2);
	printf_func("\n%d\n", res);
	res = printf_func("%.5s", "he");
	printf_func("\n%d\n", res);
	res = printf_func("%.5s", "hellllllllo");
	printf_func("\n%d\n", res);
	res = printf_func("%.6s", NULL);
	printf_func("\n%d\n", res);
	res = printf_func(" %.1s", "");
	printf_func("\n%d\n", res);
	res = printf_func("%.1s ", "");
	printf_func("\n%d\n", res);
	res = printf_func(" %.s ", "");
	printf_func("\n%d\n", res);
	res = printf_func(" %.s ", "-");
	printf_func("\n%d\n", res);
	res = printf_func(" %.2s %.1s ", "", "-");
	printf_func("\n%d\n", res);
	res = printf_func(" %.3s %.2s ", " - ", "");
	printf_func("\n%d\n", res);
}

void	test_unworking(int (*printf_func)(const char *, ...))
{
	int	res;

	res = printf_func(" %.2d ", -1);
	printf_func("\n%d\n", res);
	res = printf_func(" %.3d ", -11);
	printf_func("\n%d\n", res);
	res = printf_func(" %.4d ", -14);
	printf_func("\n%d\n", res);
}

int	main(void)
{
	printf("**************\nPrintf:\n");
	test_unworking(printf);
	printf("**************\n");
	ft_printf("**************\nFT_Printf:\n");
	test_unworking(ft_printf);
	ft_printf("**************\n");
	return (0);
}
