#include <stdio.h>
#include <assert.h>
#include "libftprintf.h"

void test(int (*printf_func)(const char *, ...))
{
	int res;
	const char *tests[] = {"hello", "", NULL};
	int	i;

	i = 0;
	while (tests[i])
	{
		res = printf_func(tests[i]);
		printf("\n%d\n", res);
		i++;
	}
}

int main(void)
{
	test(printf);
	printf("********************\n");
	test(ft_printf);
	return (0);
}