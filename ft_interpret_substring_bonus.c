/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret_substring_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:33:21 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/19 10:45:06 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_conversion_result(t_conversion *conversion, va_list args)
{
	char	*result;

	if (conversion->type == CONVERSION_CHAR_STRING)
		result = get_string_format(conversion, args);
	else if (conversion->type == CONVERSION_CHAR_CHARACTER)
		result = get_char_format(args);
	else if (conversion->type == CONVERSION_CHAR_PERCENT)
		result = get_percent_format();
	else if (conversion->type == CONVERSION_CHAR_POINTER)
		result = get_pointer_format(args);
	else if (conversion->type == CONVERSION_CHAR_HEX_UPPERCASE)
		result = get_hex_uppercase_format(conversion, args);
	else if (conversion->type == CONVERSION_CHAR_HEX_LOWERCASE)
		result = get_hex_lowercase_format(conversion, args);
	else if (conversion->type == CONVERSION_CHAR_DECIMAL
		|| conversion->type == CONVERSION_CHAR_INTEGER)
		result = get_decimal_format(conversion, args);
	else if (conversion->type == CONVERSION_CHAR_UNSIGNED_DECIMAL)
		result = get_unsigned_decimal_format(conversion, args);
	else
		result = ft_strdup("");
	return (get_result_with_padding(conversion, result));
}

void	set_result_length(t_substring *substring, t_conversion *conversion)
{
	if (conversion && conversion->type == CONVERSION_CHAR_CHARACTER)
	{
		if (conversion->width)
			substring->result_length = conversion->width;
		else
			substring->result_length = 1;
	}
	else
		substring->result_length = ft_strlen(substring->result);
}

int	interpret_substring(t_substring *substring, va_list args)
{
	t_conversion	*conversion;

	conversion = NULL;
	if (substring->format_length > 1 && substring->format[0] == '%')
	{
		conversion = get_conversion_params(substring);
		if (!conversion)
			return (-1);
		substring->result = get_conversion_result(conversion, args);
		if (!substring->result)
		{
			free(conversion);
			return (-1);
		}
	}
	else
	{
		substring->result = ft_strdup(substring->format);
		if (!substring->result)
			return (-1);
	}
	set_result_length(substring, conversion);
	free(conversion);
	return (1);
}
