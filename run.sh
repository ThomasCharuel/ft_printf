make
cc -g3 -Wall -Wextra -Werror main.c libftprintf.a
valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./a.out

# ./a.out