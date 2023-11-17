#include <stdio.h>
#include <assert.h>
#include "ft_printf.h"

#define LONG_MIN (-__LONG_MAX__ -1L)
#define LONG_MAX __LONG_MAX__


void test1(int (*printf_func)(const char *, ...))
{
	int res;

	res = printf_func(NULL);
	printf("\n%d\n", res);
	
	res = printf_func("");
	printf("\n%d\n", res);
	res = printf_func("hello");
	printf("\n%d\n", res);
	res = printf_func("hel%^lo");
	printf("\n%d\n", res);
	res = printf_func("hello%");
	printf("\n%d\n", res);
	res = printf_func("hello%s et %s", " Thomas", "Made");
	printf("\n%d\n", res);
	res = printf_func("hello%s", NULL);
	printf("\n%d\n", res);
	res = printf_func("hello %c et %c.", NULL, 'D');
	printf("\n%d\n", res);

	res = printf_func("Precision: %10.4d", 999);
	printf("\n%d\n", res);
}

int main(void)
{
	test1(ft_printf);
	printf("\n********************\n");
	test1(printf);

	return (0);
}
