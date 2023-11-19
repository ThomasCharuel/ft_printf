/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:24:59 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/19 11:12:10 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	is_number_conversion(char c)
{
	if (c == CONVERSION_CHAR_DECIMAL
		|| c == CONVERSION_CHAR_INTEGER
		|| c == CONVERSION_CHAR_UNSIGNED_DECIMAL
		|| c == CONVERSION_CHAR_HEX_LOWERCASE
		|| c == CONVERSION_CHAR_HEX_UPPERCASE)
		return (1);
	return (0);
}

void	handle_neg_and_hexa(t_conversion *conversion, char *result,
	char *number_str, size_t i)
{
	if (conversion->has_flag_0 && number_str[0] == '-'
		&& (conversion->type == CONVERSION_CHAR_DECIMAL
			|| conversion->type == CONVERSION_CHAR_INTEGER))
	{
		result[i] = '0';
		result[0] = '-';
	}
	else if (conversion->has_flag_0 && conversion->has_flag_hash
		&& (conversion->type == CONVERSION_CHAR_HEX_LOWERCASE
			|| conversion->type == CONVERSION_CHAR_HEX_UPPERCASE))
	{
		result[i] = '0';
		result[i + 1] = '0';
		result[0] = '0';
		if (conversion->type == CONVERSION_CHAR_HEX_LOWERCASE)
			result[1] = 'x';
		else
			result[1] = 'X';
	}
}

void	get_str_with_padding_0(t_conversion *conversion, char *result,
	char *number_str, size_t padding_nb)
{
	size_t	i;

	i = 0;
	while (i < padding_nb)
	{
		if (conversion->has_flag_0 && is_number_conversion(conversion->type))
			result[i] = '0';
		else
			result[i] = ' ';
		i++;
	}
	result[i] = '\0';
	ft_strcat(result, number_str);
	handle_neg_and_hexa(conversion, result, number_str, i);
}

char	*get_str_with_padding(t_conversion *conversion, char *str)
{
	char	*res;
	size_t	str_length;
	size_t	padding_nb;
	size_t	i;

	if (conversion->type == CONVERSION_CHAR_CHARACTER && str[0] == '\0')
		str_length = 1;
	else
		str_length = ft_strlen(str);
	res = (char *)malloc((conversion->width + 1) * sizeof(char));
	if (!res)
		return (NULL);
	padding_nb = conversion->width - str_length;
	if (conversion->has_flag_minus)
	{
		res[0] = '\0';
		ft_strcat(res, str);
		i = str_length;
		while (i < conversion->width)
			res[i++] = ' ';
		res[i] = '\0';
	}
	else
		get_str_with_padding_0(conversion, res, str, padding_nb);
	return (res);
}

char	*add_padding_to_result(t_conversion *conversion, char *result)
{
	char	*result_with_padding;

	if (result && conversion->width > ft_strlen(result))
	{
		result_with_padding = get_str_with_padding(conversion, result);
		free(result);
		return (result_with_padding);
	}
	return (result);
}
