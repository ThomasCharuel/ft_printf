# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 13:33:40 by tcharuel          #+#    #+#              #
#    Updated: 2023/11/15 14:24:00 by tcharuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c \
	ft_substring.c \
	get_result.c \
	ft_print_result.c

OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f
LIBFT_DIR = libft/
LIBFT = libft.a


all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS) 
	ar rcs $(NAME) $(OBJECTS)

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)$(LIBFT) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I. -Ilibft -c $< -o ${<:.c=.o}

clean:
	$(RM) $(OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
