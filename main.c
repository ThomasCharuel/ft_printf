#include <stdio.h>
#include <assert.h>
#include "ft_printf.h"

void test1(int (*printf_func)(const char *, ...))
{
	int res;
	
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

	res = printf_func(" %c %c %c P\n", '2', '1', 0);
	printf("\n%d\n", res);
}

void test2(int (*printf_func)(const char *, ...))
{
	int res;

	res = printf_func(" %p %p\n", '2', '1', 0);
	printf("\n%d\n", res);
}

int main(void)
{
	char *hello = "hello";
	int a = 2;

	test1(ft_printf);
	printf("\n********************\n");
	test1(printf);

	printf("%p - %p\n", hello, &a);
	ft_printf("%p - %p\n", hello, &a);

	return (0);
}