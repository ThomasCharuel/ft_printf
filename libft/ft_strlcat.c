/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:36:51 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/08 17:47:04 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*dest_terminator_ptr;
	size_t	dest_len;
	size_t	i;

	if (!size)
		return (ft_strlen(src));
	dest_len = ft_strlen(dst);
	if (size <= dest_len)
		return (size + ft_strlen(src));
	i = 0;
	dest_terminator_ptr = dst + dest_len;
	while (src[i] != '\0')
	{
		if (dest_len + i < size - 1)
		{
			dst[dest_len + i] = src[i];
			dest_terminator_ptr++;
		}
		i++;
	}
	*dest_terminator_ptr = '\0';
	return (dest_len + i);
}
