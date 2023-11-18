/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret_substring_format_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:11:49 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/18 11:26:48 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_string_format(va_list args)
{
	char	*str_arg;
	char	*result;

	str_arg = va_arg(args, char *);
	if (str_arg)
		result = ft_strdup(str_arg);
	else
		result = ft_strdup("(null)");
	return (result);
}

char	*get_char_format(va_list args)
{
	char	*result;

	result = (char *)malloc(2 * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = va_arg(args, int);
	result[1] = '\0';
	return (result);
}

char	*get_percent_format(void)
{
	char	*result;

	result = (char *)malloc(2 * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '%';
	result[1] = '\0';
	return (result);
}

char	*get_pointer_format(va_list args)
{
	uintptr_t	ptr;
	char		*hex_string;
	char		*result;

	ptr = va_arg(args, uintptr_t);
	if (ptr)
	{
		hex_string = ft_lutoa(ptr, BASE_HEX_LOWERCASE);
		if (!hex_string)
			return (NULL);
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
	}
	else
		result = ft_strdup("(nil)");
	return (result);
}

char	*get_hex_uppercase_format(t_conversion *conversion, va_list args)
{
	char	*hex_string;
	char	*result;

	hex_string = ft_ltoa((unsigned int)va_arg(args, int), BASE_HEX_UPPERCASE);
	if (!hex_string)
		return (NULL);
	if (!conversion->has_flag_hash || hex_string[0] == '0')
		return (hex_string);
	result = (char *)malloc((ft_strlen(hex_string) + 3) * sizeof(char));
	if (!result)
	{
		free(hex_string);
		return (NULL);
	}
	result[0] = '0';
	result[1] = 'X';
	result[2] = '\0';
	ft_strcat(result, hex_string);
	free(hex_string);
	return (result);
}

char	*get_hex_lowercase_format(t_conversion *conversion, va_list args)
{
	char	*hex_string;
	char	*result;

	hex_string = ft_ltoa((unsigned int)va_arg(args, int), BASE_HEX_LOWERCASE);
	if (!hex_string)
		return (NULL);
	if (!conversion->has_flag_hash || hex_string[0] == '0')
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
