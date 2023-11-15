/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:01:08 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/15 20:31:14 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	interpret_substring(t_substring *substring, va_list args)
{
	size_t	i;
	char	*str;

	if (substring->format[0] == '%')
	{
		i = 0;
		while (substring->format[i])
			i++;
		if (i > 1 && substring->format[i - 1] == CONVERSION_CHAR_STRING)
		{
			str = va_arg(args, char *);
			if (str)
				substring->result = ft_strdup(str);
			else
				substring->result = ft_strdup("(null)");
			if (!substring->result)
				return (-1);
		}
		else if (i > 1 && (
			substring->format[i - 1] == CONVERSION_CHAR_CHARACTER
			|| substring->format[i - 1] == CONVERSION_CHAR_PERCENT))
		{
			str = (char *)malloc(2 * sizeof(char));
			if (!str)
				return (-1);
			if (substring->format[i - 1] == CONVERSION_CHAR_CHARACTER)
				str[0] = va_arg(args, int);
			else
				str[0] = '%';
			str[1] = '\0';
			substring->result = str;
			substring->result_length = 1;
			return (1);
		}
		else if (i > 1 && substring->format[i - 1] == CONVERSION_CHAR_POINTER)
		{
			// TODO POINTER
			str = (char *)malloc(2 * sizeof(char));
			if (!str)
				return (-1);
			str[0] = '?';
			str[1] = '\0';
			substring->result = str;
		}
		else if (i > 1 && (
				substring->format[i - 1] == CONVERSION_CHAR_DECIMAL
				|| substring->format[i - 1] == CONVERSION_CHAR_INTEGER
				|| substring->format[i - 1] == CONVERSION_CHAR_UNSIGNED_DECIMAL))
		{
			// TODO INT
			str = (char *)malloc(2 * sizeof(char));
			if (!str)
				return (-1);
			str[0] = '?';
			str[1] = '\0';
			substring->result = str;
		}
		else if (i > 1 && (
				substring->format[i - 1] == CONVERSION_CHAR_HEX_LOWERCASE
				|| substring->format[i - 1] == CONVERSION_CHAR_HEX_UPPERCASE))
		{
			// TODO Hexadecimal
			str = (char *)malloc(2 * sizeof(char));
			if (!str)
				return (-1);
			str[0] = '?';
			str[1] = '\0';
			substring->result = str;
		}
		else
		{
			substring->result = ft_strdup("");
			if (!substring->result)
				return (-1);
		}
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

int	is_conversion_identifier(const char c)
{
	if (c == CONVERSION_CHAR_CHARACTER
		|| c == CONVERSION_CHAR_STRING
		|| c == CONVERSION_CHAR_POINTER
		|| c == CONVERSION_CHAR_DECIMAL
		|| c == CONVERSION_CHAR_INTEGER
		|| c == CONVERSION_CHAR_UNSIGNED_DECIMAL
		|| c == CONVERSION_CHAR_HEX_LOWERCASE
		|| c == CONVERSION_CHAR_HEX_UPPERCASE
		|| c == CONVERSION_CHAR_PERCENT)
		return (1);
	return (0);
}

t_substring	*parse_substring(const char **format, va_list args)
{
	t_substring	*substring;
	size_t		len;
	char		*substring_format;

	len = 0;
	if ((*format)[len++] == '%')
	{
		while ((*format)[len])
			if (is_conversion_identifier((*format)[(++len) - 1]))
				break ;
	}
	else
		while ((*format)[len] && (*format)[len] != '%')
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

int	get_len_substrings(t_list *lst)
{
	int len;
	
	len = 0;
	while (lst)
	{
		len += ((t_substring *)lst->content)->result_length;
		lst = lst->next;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	t_list	*substring_list;
	size_t	len;
	va_list	args;

	va_start(args, format);
	substring_list = parse_format(format, args);
	if (!substring_list)
		return (-1);
	va_end(args);
	ft_lstiter(substring_list, (void *)put_substring_result);
	len = get_len_substrings(substring_list);
	ft_lstclear(&substring_list, (void *)free_substring);
	return (len);
}

