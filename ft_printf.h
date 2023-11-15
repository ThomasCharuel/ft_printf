/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:01:58 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/15 17:10:54 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define BUFFER_SIZE 2

# define CONVERSION_CHAR_CHARACTER 'c'
# define CONVERSION_CHAR_STRING 's'
# define CONVERSION_CHAR_POINTER 'p'
# define CONVERSION_CHAR_DECIMAL 'd'
# define CONVERSION_CHAR_INTEGER 'i'
# define CONVERSION_CHAR_UNSIGNED_DECIMAL 'u'
# define CONVERSION_CHAR_HEX_LOWERCASE 'x'
# define CONVERSION_CHAR_HEX_UPPERCASE 'X'
# define CONVERSION_CHAR_PERCENT '%'

# include <stdio.h>

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_substring
{
	char	*format;
	size_t	format_length;
	char	*result;
	size_t	result_length;
}	t_substring;

int			ft_printf(const char *format, ...);

t_substring *create_substring(char *format, size_t format_length);
void		free_substring(t_substring *substring);
void		put_substring_result(t_substring *substring);

#endif