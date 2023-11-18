/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:24:59 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/18 14:38:47 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*get_str_with_padding(t_conversion *conversion, char *str)
{
	char	*res;
	size_t	str_length;
	size_t	padding_nb;
	size_t	i;

	str_length = ft_strlen(str);
	res = (char *)malloc((conversion->width + 1) * sizeof(char));
	if (!res)
		return (NULL);
	padding_nb = conversion->width - str_length;
	i = 0;
	while (i < padding_nb)
	{
		if (conversion->has_flag_0)
			res[i++] = '0';
		else
			res[i++] = ' ';
	}
	res[i] = '\0';
	ft_strcat(res, str);
	return (res);
}
