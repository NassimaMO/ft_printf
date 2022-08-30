/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:53:44 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/17 14:53:46 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

static void ft_print_args(char c, int *count, va_list args)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*count)++;
	}
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1, count);
	else if (c == 'p')
		ft_putnbr_base(va_arg(args, long int), "0123456789abcdefg", 1, count);
	else if (c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1, count);
	else if (c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, count);
	else if (c == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1, count);
	else if (c == 'x')
		ft_putnbr_base(va_arg(args, unsigned int),
					   "0123456789abcdefg", 0, count);
	else if (c == 'X')
		ft_putnbr_base(va_arg(args, unsigned int),
					   "0123456789ABCDEFG", 0, count);
}

static void ft_print_str(char *str, int *j, int *count)
{
	while (str[*j] && str[*j] != '%')
	{
		ft_putchar_fd(str[*j], 1);
		(*count)++;
		(*j)++;
	}
}

void ft_read_str(va_list args, char *str, int *no, int *count)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		ft_print_str(str, &i, count);
		i++;
		ft_print_args(str[i], count, args);
		if (str[i] == '%')
		{
			ft_putchar_fd('%', 1);
			(*count)++;
			if (str[i + 1] == '%')
				(*no)++;
		}
		i++;
	}
}

int ft_printf(const char *str, ...)
{
	va_list args;
	int no;
	int count;

	no = 0;
	count = 0;
	va_start(args, str);
	ft_read_str(args, (char *)str, &no, &count);
	if (no % 2 == 1 && no != 1)
		return (-1);
	return (count);
}