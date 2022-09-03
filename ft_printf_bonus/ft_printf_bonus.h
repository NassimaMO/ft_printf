/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:42:03 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/30 14:42:06 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
#define FT_PRINTF_BONUS_H

#include "../libft/libft.h"

void    ft_find_flags(char *str, int *i, int *count, va_list args);
int ft_putnbr_base(long int nbr, char *base, int n, int *i);
int ft_printf(const char *str, ...);

#endif
