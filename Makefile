NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = ft_printf.c ft_chrstr_helper.c ft_int_helper.c ft_hexptr_helper.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re