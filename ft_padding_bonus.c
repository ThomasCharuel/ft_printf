/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:24:59 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/18 15:45:57 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
	{
		i = 0;
		while (i < padding_nb)
		{
			if (conversion->has_flag_0)
				res[i] = '0';
			else
				res[i] = ' ';
			i++;
		}
		res[i] = '\0';
		ft_strcat(res, str);
		if (conversion->has_flag_0 && str[0] == '-'
			&& (conversion->type == CONVERSION_CHAR_DECIMAL
				|| conversion->type == CONVERSION_CHAR_INTEGER))
		{
			res[i] = '0';
			res[0] = '-';
		}
	}
	return (res);
}
