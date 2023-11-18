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
	res = printf_func("hello %x et %#x.", 0, 0);
	printf("\n%d\n", res);
	res = printf_func("hello %x et %#x.", -3, -3);
	printf("\n%d\n", res);
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
}

int	main(void)
{
	test_blank(printf);
	printf("\n********************\n");
	test_blank(ft_printf);
	return (0);
}
