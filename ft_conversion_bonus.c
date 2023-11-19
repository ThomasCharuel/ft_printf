/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:04:51 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/19 10:39:09 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_conversion	*create_conversion(char type)
{
	t_conversion	*conversion;

	conversion = (t_conversion *)malloc(sizeof(t_conversion));
	if (!conversion)
		return (NULL);
	conversion->type = type;
	conversion->has_flag_minus = 0;
	conversion->has_flag_0 = 0;
	conversion->has_flag_hash = 0;
	conversion->has_flag_blank = 0;
	conversion->has_flag_plus = 0;
	conversion->has_flag_precision = 0;
	conversion->width = 0;
	conversion->precision = 0;
	return (conversion);
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

int	is_flag(char c)
{
	while (c == FLAG_MINUS || c == FLAG_0 || c == FLAG_HASH
		|| c == FLAG_BLANK || c == FLAG_PLUS)
	{
		return (1);
	}
	return (0);
}

t_conversion	*get_conversion_params(t_substring *substring)
{
	t_conversion	*conversion;
	size_t			i;

	conversion = create_conversion(substring->format[substring->format_length
			- 1]);
	if (!conversion)
		return (NULL);
	i = 1;
	while (is_flag(substring->format[i]))
		set_flag(substring->format[i++], conversion);
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
