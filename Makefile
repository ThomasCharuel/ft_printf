# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 13:33:40 by tcharuel          #+#    #+#              #
#    Updated: 2023/11/17 20:21:29 by tcharuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c \
	ft_parse_format.c \
	ft_interpret_substring.c \
	ft_interpret_substring_format.c \
	ft_substring.c

SOURCES_BONUS = ft_printf.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f
LIBFT_DIR = libft/
LIBFT = libft.a


all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus: $(LIBFT) $(OBJECTS_BONUS)
	ar rcs $(NAME) $(OBJECTS_BONUS)

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)$(LIBFT) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I. -Ilibft -c $< -o ${<:.c=.o}

clean:
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: $(NAME) bonus all clean fclean re
