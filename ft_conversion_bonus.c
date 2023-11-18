/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:04:51 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/18 16:37:21 by tcharuel         ###   ########.fr       */
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
