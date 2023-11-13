/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:05:20 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/08 11:33:26 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_nb_digits(long nb)
{
	if (nb / 10 == 0)
		return (1);
	return (1 + get_nb_digits(nb / 10));
}

static size_t	get_str_length(long nb)
{
	size_t	len;

	if (nb < 0)
	{
		len = 1;
		nb *= -1;
	}
	else
		len = 0;
	len += get_nb_digits(nb);
	return (len);
}

static void	put_n_in_str(long nb, char *res, size_t len)
{
	res[len--] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		res[len] = 0 + '0';
	while (nb > 0)
	{
		res[len--] = nb % 10 + '0';
		nb /= 10;
	}
}

/**
 * @brief Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * Negative numbers must be handled.
 *
 * @param n The integer to convert.
 *
 * @return The string representing the integer.
 * @retval NULL if the allocation fails.
 */
char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;

	len = get_str_length(n);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	put_n_in_str(n, res, len);
	return (res);
}
