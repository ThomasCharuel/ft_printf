/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:47:39 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/19 11:15:04 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_number_with_precision(t_conversion *conversion, char *result,
	size_t result_length)
{
	char	*result_with_precision;
	size_t	i;

	result_with_precision = (char *)malloc((conversion->precision + 1)
			* sizeof(char));
	if (!result_with_precision)
	{
		free(result);
		return (NULL);
	}
	i = 0;
	while (i < conversion->precision - result_length)
		result_with_precision[i++] = '0';
	result_with_precision[i] = '\0';
	ft_strcat(result_with_precision, result);
	free(result);
	if (result_with_precision && result_with_precision[i] == '-')
	{
		result_with_precision[i] = '0';
		result_with_precision[0] = '-';
	}
	return (result_with_precision);
}

char	*add_precision_to_result(t_conversion *conversion, char *result)
{
	size_t	result_length;

	result_length = ft_strlen(result);
	if (conversion->has_flag_precision && result_length == 1
		&& result[0] == '0')
	{
		result[0] = '\0';
		result_length = 0;
	}
	if (result[0] == '-')
		conversion->precision++;
	if (conversion->precision <= result_length)
		return (result);
	return (get_number_with_precision(conversion, result, result_length));
}
