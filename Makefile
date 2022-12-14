FILES = ft_printf.c ft_putnbr_hex.c
LIBFT = ./libft
LIB = ./libft/libft.a
OBJECTS = $(FILES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB)
	cp -f $(LIB) ./$(NAME)
	ar rcs $(NAME) $(OBJECTS)

$(LIB):
	cd $(LIBFT) && make

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(B_OBJECTS)
	cd $(LIBFT) && make clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)
	cd $(LIBFT) && make fclean

re: fclean all
