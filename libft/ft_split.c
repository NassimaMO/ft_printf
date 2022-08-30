/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmouslim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:04:08 by nmouslim          #+#    #+#             */
/*   Updated: 2022/05/04 14:16:26 by nmouslim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	ft_ft(char *s, char const *s1, int j)
{
	int	x;

	x = 0;
	while (x != j)
	{
		s[x] = s1[x];
		x++;
	}
	s[x] = '\0';
}

void	ft_fill1(char const *s, char c, char **temp)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (s[i])
	{
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (j != i)
		{
			temp[x] = malloc(sizeof(char) * ((i - j) + 1));
			ft_ft(temp[x], s + j, i - j);
			x++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**temp;
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 0;
	while (s[i])
	{
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (j != i)
			x++;
		while (s[i] && s[i] == c)
			i++;
	}
	temp = malloc(sizeof(char *) * (x + 1));
	if (!temp)
		return (NULL);
	temp[x] = NULL;
	ft_fill1(s, c, temp);
	return (temp);
}
/*void	ft_ft(char *s, char const *s1, int j)
{
	int	x;

	x = 0;
	while (x != j)
	{
		s[x] = s1[x];
		x++;
	}
	s[x] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**temp;
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 0;
	while (s[i])
	{
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (j != i)
			x++;
		while (s[i] && s[i] == c)
			i++;
	}
	temp = malloc(sizeof(char *) * (x + 1));
	if (!temp)
		return (NULL);
	temp[x] = NULL;
	i = 0;
	j = 0;
	x = 0;
	while (s[i])
	{
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (j != i)
		{
			temp[x] = malloc(sizeof(char) * ((i - j) + 1));
			ft_ft(temp[x], s + j, i - j);
			x++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (temp);
}
*/