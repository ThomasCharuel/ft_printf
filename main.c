#include <stdio.h>
#include <assert.h>
#include "libftprintf.h"

void test(int (*printf_func)(const char *, ...))
{
	int res;
	
	res = printf_func("");
	printf("\n%d\n", res);
	res = printf_func("hello");
	printf("\n%d\n", res);
	res = printf_func("hello%");
	printf("\n%d\n", res);
	res = printf_func("hello%s", " Thomas");
	printf("\n%d\n", res);
	res = printf_func("hello%s", NULL);
	printf("\n%d\n", res);
}

int main(void)
{
	test(printf);
	printf("********************\n");
	test(ft_printf);
	return (0);
}