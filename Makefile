FILES = ft_hextoa.c ft_is_placeholder.c ft_itoa.c ft_iutoa.c ft_printf.c ft_putchar_len.c ft_putstr_len.c ft_str_rev.c ft_strlen.c ft_putptr.c
OBJECTS = $(FILES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(B_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
