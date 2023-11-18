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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSION_CHAR_CHARACTER 'c'
# define CONVERSION_CHAR_STRING 's'
# define CONVERSION_CHAR_POINTER 'p'
# define CONVERSION_CHAR_DECIMAL 'd'
# define CONVERSION_CHAR_INTEGER 'i'
# define CONVERSION_CHAR_UNSIGNED_DECIMAL 'u'
# define CONVERSION_CHAR_HEX_LOWERCASE 'x'
# define CONVERSION_CHAR_HEX_UPPERCASE 'X'
# define CONVERSION_CHAR_PERCENT '%'

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_substring
{
	char	*format;
	size_t	format_length;
	char	*result;
	size_t	result_length;
}			t_substring;

int			ft_printf(const char *format, ...);

int			is_conversion_identifier(const char c);
t_list		*parse_format(const char *format, va_list args);
t_substring	*parse_substring(const char **format, va_list args);

t_substring	*create_substring(char *format, size_t format_length);
void		free_substring(t_substring *substring);
void		put_substring_result(t_substring *substring);
int			get_len_substrings(t_list *lst);

int			interpret_substring(t_substring *substring, va_list args);

char		*get_string_format(va_list args);
char		*get_char_format(va_list args);
char		*get_percent_format(void);
char		*get_pointer_format(va_list args);

#endif
