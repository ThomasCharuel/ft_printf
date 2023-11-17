/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:01:08 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/17 21:17:05 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/**
 * @brief 
 * Each conversion specification is introduced by the character %
 * and ends with a conversion specifier.
 * In between there may be (in this order):
 * - zero or more flag
 * - An optional minimum field width
 * - An optional precision
 * - And optional length modifier
 *
 * The overall syntax of a conversion specification is:
 * -->	%[flags][width][.precision]conversion
 * 
 * Flags are:
 * '0': Field is padded left with 0's instead of blank.
 * '-': Justify left.
 * '#': Change output format.
 * ' ': A blank should be left before a positive number
 * 		produced by signed conversion.
 * '+': A sign should always be placed before a number 
 * 		produced by a signed conversion.
 * 
 * Precision:
 * '.{x}': Print at most {x} characters of a string.
 * 			This gives the minimum number of digits to appear for numbers
 * 			When 0 is printed with an explicit precision 0, the output is empty.
 * 
 * @param lst: The address of a pointer to the first link of
 * a list.
 * @param new: The address of a pointer to the node to be
 * added to the list.
 * 
 * @return The number of bytes written to STDOUT
 * @retval -1 in case of error.
 */
int	ft_printf(const char *format, ...)
{
	t_list	*substring_list;
	size_t	len;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	substring_list = parse_format(format, args);
	if (!substring_list)
		return (-1);
	va_end(args);
	ft_lstiter(substring_list, (void *)put_substring_result);
	len = get_len_substrings(substring_list);
	ft_lstclear(&substring_list, (void *)free_substring);
	return (len);
}
