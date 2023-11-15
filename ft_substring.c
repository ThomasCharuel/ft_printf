/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:04:51 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/15 13:57:08 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_substring *create_substring(char *format)
{
	t_substring *substring;

	substring = (t_substring *)malloc(sizeof(t_substring));
	if (!substring)
		return (NULL);
	substring->format = format;
	substring->result = NULL;
	substring->result_length = 0;
	return (substring);
}

void	free_substring(t_substring *substring)
{
	substring = (t_substring *)substring;
	if ((substring)->format)
		free((substring)->format);
	if ((substring)->result)
		free((substring)->result);
	if (substring)
		free(substring);
}
