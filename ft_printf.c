/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:01:08 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/15 14:18:30 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_substring *parse_substring(const char **format, va_list args)
{
	t_substring	*substring;
	size_t		len;
	char		*substring_format;

	len = 0;
	while ((*format)[len])
		len++;
	substring_format = ft_strndup(*format, len);
	if (!substring_format)
		return (NULL);
	substring = create_substring(substring_format);
	if (!substring)
		return (NULL);
	*format += len;
	substring->result = ft_strdup(substring->format);
	substring->result_length = ft_strlen(substring->result);
	(void)args;
	return (substring);
}

t_list	*parse_format(const char *format, va_list args)
{
	t_list		*lst;
	t_list		*new_node;
	t_substring	*substring;

	lst = NULL;
	while (*format)
	{
		substring = parse_substring(&format, args);
		if (!substring)
			return (NULL);
		new_node = ft_lstnew(substring);
		if (!new_node)
		{
			free_substring(substring);
			ft_lstclear(&lst, (void *)free_substring);
			return (NULL);
		}
		ft_lstadd_back(&lst, new_node);
	}
	return (lst);
}

int	ft_printf(const char *format, ...)
{
	char	*result;
	t_list	*substring_list;
	size_t	len;
	va_list	args;

	va_start(args, format);
	substring_list = parse_format(format, args);
	if (!substring_list)
		return (-1);
	va_end(args);
	result = get_result(substring_list);
	ft_lstclear(&substring_list, (void *)free_substring);
	if (!result)
		return (-1);
	len = ft_strlen(result);
	ft_print_result(result, len);
	free(result);
	return (len);
}
