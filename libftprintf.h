/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:01:58 by tcharuel          #+#    #+#             */
/*   Updated: 2023/11/15 15:53:53 by tcharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define BUFFER_SIZE 16

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

char		*get_result(t_list *lst);

void 		ft_print_result(const char *str, size_t len);

#endif