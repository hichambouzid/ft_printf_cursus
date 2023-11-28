NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_util.c

OBJS = ft_printf.o ft_printf_util.o

all : $(NAME)

$(OBJS): $(SRCS)
	cc $(CFLAGS) -c $(SRCS)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
