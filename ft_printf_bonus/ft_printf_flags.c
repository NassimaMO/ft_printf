#include <stdarg.h>
#include <stdio.h>
#include "ft_printf_bonus.h"

void	ft_print_char(char c, int num, int *count)
{
	int	i;

	i = 0;
	while (i < num)
	{
		ft_putchar_fd(c, 1);
		(*count)++;
		i++;
	}
}

int	ft_find_num(int number)
{
	int	i;

	i = 0;
	if (number <= 0)
	{
		number *= -1;
		i++;
	}
	while (number > 0)
	{
		i++;
		number /= 10;
	}
	return (i);
}

char	find_arg(char *str, int *i, int x)
{
	int	tmp;

	tmp = *i;
	while (str[tmp])
	{
		if (str[tmp] == 'c' ||\
			str[tmp] == 's' ||\
			str[tmp] == 'p' ||\
			str[tmp] == 'd' ||\
			str[tmp] == 'i' ||\
			str[tmp] == 'u' ||\
			str[tmp] == 'x' ||\
			str[tmp] == 'X')
			break ;
		tmp++;
	}
	if (x)
		(*i) = tmp;
	return (str[tmp]);
}


void    print_flags_int(int d, char *str, int *i, int *count)
{
	int lel;

	lel = ft_find_num(d);
	if (str[*i] == '-')
	{
		ft_putnbr_fd(d, 1, count);
		if (str[*i + 1] >= '0' && str[*i + 1] <= '9')
		{
			if (lel < ft_atoi(str + (*i + 1)))
				ft_print_char(' ', ft_atoi(str + (*i + 1)) - lel, count);
		}
	}
	else if (str[*i] == '0' && str[*i + 1] != '.')
	{
		if (str[*i + 1] >= '0' && str[*i + 1] <= '9')
		{
			if (lel < ft_atoi(str + (*i + 1)))
				ft_print_char('0', ft_atoi(str + (*i + 1)) - lel, count);
		}
		ft_putnbr_fd(d, 1, count);
	}
	else if ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '.')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
		{
			if (str[*i + 2] >= '0' && str[*i + 2] <= '9')
			{
				if (lel < ft_atoi(str + (*i + 2)))
				{
					ft_print_char('0', ft_atoi(str + (*i + 2)) - lel, count);
					if (ft_atoi(str + (*i + 2)) < ft_atoi(str + *i))
						ft_print_char(' ', ft_atoi(str + *i) - ft_atoi(str + (*i + 2)), count);
				}
			}
			else
			{
				if (lel < ft_atoi(str + *i))
					ft_print_char(' ', ft_atoi(str + *i) - lel, count);
			}
		}
		else if (str[*i] == '.')
		{
			if (str[*i + 1] >= '0' && str[*i + 1] <= '9')
			{
				if (lel < ft_atoi(str + (*i + 1)))
					ft_print_char(' ', ft_atoi(str + (*i + 1)) - lel, count);
			}
		}
		ft_putnbr_fd(d, 1, count);
	}
	find_arg(str, i, 1);
}

void	ft_find_flags(char *str, int *i, int *count, va_list args)
{
	if (find_arg(str, i, 0) == 'd')
		print_flags_int(va_arg(args, int), str, i, count);
}
