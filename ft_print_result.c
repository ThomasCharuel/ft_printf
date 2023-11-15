/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:16:40 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/15 13:08:38 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_print_result(const char *str, size_t len)
{
	while (len > BUFFER_SIZE)
	{
		write(0, str, BUFFER_SIZE);
		len -= BUFFER_SIZE;
		str += BUFFER_SIZE;
	}
	write(0, str, len);
}
