/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret_substring_format_bonus_2.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:11:49 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/19 11:00:23 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_hex_lowercase_format(t_conversion *conversion, va_list args)
{
	char	*hex_string;
	char	*result;

	hex_string = ft_ltoa((unsigned int)va_arg(args, int), BASE_HEX_LOWERCASE);
	if (!hex_string)
		return (NULL);
	hex_string = add_precision_to_result(conversion, hex_string);
	if (!hex_string)
		return (NULL);
	if (!conversion->has_flag_hash || (hex_string[ft_strlen(hex_string)
				- 1] == '0' && hex_string[0] == '0'))
		return (hex_string);
	result = (char *)malloc((ft_strlen(hex_string) + 3) * sizeof(char));
	if (!result)
	{
		free(hex_string);
		return (NULL);
	}
	result[0] = '0';
	result[1] = 'x';
	result[2] = '\0';
	ft_strcat(result, hex_string);
	free(hex_string);
	return (result);
}

char	*handle_flag_decimal(t_conversion *conversion, char *decimal_str)
{
	char	*result;

	result = (char *)malloc((ft_strlen(decimal_str) + 2) * sizeof(char));
	if (!result)
	{
		free(decimal_str);
		return (NULL);
	}
	if (conversion->has_flag_plus)
		result[0] = '+';
	else
		result[0] = ' ';
	result[1] = '\0';
	ft_strcat(result, decimal_str);
	free(decimal_str);
	return (result);
}

char	*get_decimal_format(t_conversion *conversion, va_list args)
{
	int		decimal_arg;
	char	*decimal_string;

	decimal_arg = va_arg(args, int);
	decimal_string = ft_itoa(decimal_arg);
	if (!decimal_string)
		return (NULL);
	decimal_string = add_precision_to_result(conversion, decimal_string);
	if (!decimal_string)
		return (NULL);
	if (decimal_string[0] == '-' || (!conversion->has_flag_blank
			&& !conversion->has_flag_plus))
		return (decimal_string);
	return (handle_flag_decimal(conversion, decimal_string));
}

char	*get_unsigned_decimal_format(t_conversion *conversion, va_list args)
{
	char	*result;

	result = ft_ltoa(va_arg(args, unsigned int), BASE_DECIMAL);
	if (!result)
		return (NULL);
	return (add_precision_to_result(conversion, result));
}
