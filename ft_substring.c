/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:04:51 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/15 15:53:56 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_substring *create_substring(char *format, size_t format_length)
{
	t_substring *substring;

	substring = (t_substring *)malloc(sizeof(t_substring));
	if (!substring)
		return (NULL);
	substring->format = format;
	substring->format_length = format_length;
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
