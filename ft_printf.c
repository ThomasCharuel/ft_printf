/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:01:08 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/15 16:24:55 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	interpret_substring(t_substring *substring, va_list args)
{
	size_t	i;
	char	*str;

	if (substring->format[0] == '%')
	{
		i = 0;
		// Handle formaters
		while (substring->format[i])
			i++;
		if (i > 1 && substring->format[i - 1] == 's')
		{
			str = va_arg(args, char *);
			if (str)
				substring->result = ft_strdup(str);
			else
				substring->result = ft_strdup("(null)");
			if (!substring->result)
				return (-1);
		}
		else
		{
			substring->result = ft_strdup("");
			if (!substring->result)
				return (-1);
		}
		(void)args;
	}
	else
	{
		substring->result = ft_strdup(substring->format);
		if (!substring->result)
			return (-1);
	}
	substring->result_length = ft_strlen(substring->result);
	return (1);
}

t_substring	*parse_substring(const char **format, va_list args)
{
	t_substring	*substring;
	size_t		len;
	char		*substring_format;

	len = 0;
	while ((*format)[len] && ((*format)[len] != '%' || !len))
		len++;
	substring_format = ft_strndup(*format, len);
	if (!substring_format)
		return (NULL);
	substring = create_substring(substring_format, len);
	if (!substring)
		return (NULL);
	*format += len;
	if (interpret_substring(substring, args) < 0)
	{
		free_substring(substring);
		return (NULL);
	}
	return (substring);
}

t_list	*parse_format(const char *format, va_list args)
{
	t_list		*lst;
	t_list		*new_node;
	t_substring	*substring;
	int			is_first_run;

	lst = NULL;
	is_first_run = 1;
	while (is_first_run || *format)
	{
		if (is_first_run)
			is_first_run = 0;
		substring = parse_substring(&format, args);
		if (substring)
			new_node = ft_lstnew(substring);
		if (!substring || !new_node)
		{
			if (substring)
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
