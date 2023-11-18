/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret_substring_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:33:21 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/18 11:18:13 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_conversion_result(t_conversion *conversion, va_list args)
{
	char	*result;

	if (conversion->type == CONVERSION_CHAR_STRING)
		result = get_string_format(args);
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
		result = ft_itoa(va_arg(args, int));
	else if (conversion->type == CONVERSION_CHAR_UNSIGNED_DECIMAL)
		result = ft_ltoa(va_arg(args, unsigned int), BASE_DECIMAL);
	else
		result = ft_strdup("");
	return (result);
}

void	set_flag(int flag, t_conversion *conversion)
{
	if (flag == FLAG_MINUS)
		conversion->has_flag_minus = 1;
	else if (flag == FLAG_0)
		conversion->has_flag_0 = 1;
	else if (flag == FLAG_HASH)
		conversion->has_flag_hash = 1;
	else if (flag == FLAG_BLANK)
		conversion->has_flag_blank = 1;
	else if (flag == FLAG_PLUS)
		conversion->has_flag_plus = 1;
}

t_conversion	*get_conversion_params(t_substring *substring)
{
	t_conversion	*conversion;
	size_t			i;

	conversion = (t_conversion *)malloc(sizeof(t_conversion));
	if (!conversion)
		return (NULL);
	conversion->type = substring->format[substring->format_length - 1];
	conversion->has_flag_minus = 0;
	conversion->has_flag_0 = 0;
	conversion->has_flag_hash = 0;
	conversion->has_flag_blank = 0;
	conversion->has_flag_plus = 0;
	conversion->has_flag_precision = 0;
	conversion->width = 0;
	conversion->precision = 0;
	i = 1;
	while (substring->format[i] == FLAG_MINUS || substring->format[i] == FLAG_0
		|| substring->format[i] == FLAG_HASH
		|| substring->format[i] == FLAG_BLANK
		|| substring->format[i] == FLAG_PLUS)
	{
		set_flag(substring->format[i], conversion);
		i++;
	}
	if (ft_isdigit(substring->format[i]))
	{
		conversion->width = ft_atoi(&(substring->format[i]));
		while (ft_isdigit(substring->format[i]))
			i++;
	}
	if (substring->format[i] == FLAG_PRECISION)
	{
		conversion->has_flag_precision = 1;
		i++;
	}
	if (ft_isdigit(substring->format[i]))
		conversion->precision = ft_atoi(&(substring->format[i]));
	return (conversion);
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
	}
	else
		substring->result = ft_strdup(substring->format);
	if (!substring->result)
		return (-1);
	if (conversion && conversion->type == CONVERSION_CHAR_CHARACTER
		&& substring->result[0] == '\0')
		substring->result_length = 1;
	else
		substring->result_length = ft_strlen(substring->result);
	return (1);
}
