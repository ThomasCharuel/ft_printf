/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:16:55 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/15 16:06:41 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_result(t_list *lst)
{
	size_t	length;
	char	*result;
	t_list	*node;

	length = 0;
	node = lst;
	while (node)
	{
		length += (((t_substring *)node->content)->result_length);
		node = node->next;
	}
	result = (char *)malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '\0';
	node = lst;
	while (node)
	{
		ft_strcat(result, ((t_substring *)node->content)->result);
		node = node->next;
	}
	return (result);
}