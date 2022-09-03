NAME			= libftprintf.a

CFLAGS			= -Wall -Wextra -Werror -c

CC				= gcc

SRCS			= ft_printf.c ft_putnbr_base.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c libft/ft_strlen.c

SRCS			= ft_printf_bonus/ft_printf_bonus.c ft_printf_bonus/ft_putnbr_base.c ft_printf_bonus/ft_printf_flags.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c libft/ft_strlen.c libft/ft_atoi.c

OBJS			= $(SRCS:.c=.o)



all:			$(NAME)

$(NAME):		$(OBJS)
	ar crs $@ $(OBJS)

%.o:			%.c
	$(CC) $(CFLAGS) $< -o $@

bonus:			$(NAME)

clean:
	rm -rf $(OBJS) libft/$(OBJS)

fclean:			clean
	rm -f $(NAME)

re:				fclean all