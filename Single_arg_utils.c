/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Single_arg_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:12:57 by jgagnon           #+#    #+#             */
/*   Updated: 2022/07/19 18:15:02 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_isspace(int c)
{
	if ((c >= 0x09 && c <= 0x0d) || c == 0x20)
		return (0);
	return (1);
}

int	ft_nbwords(char const *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < ft_strlen((char *)s))
	{
		while (ft_isspace((int)s[i]) == 0)
			i++;
		if (i < ft_strlen((char *)s))
			count++;
		while (ft_isspace(s[i]) != 0 && s[i] != '\0')
			i++;
	}
	return (count);
}

int	ft_wordlengh(char const *s, int i)
{
	int	lengh;

	lengh = 0;
	while (ft_isspace(s[i]) != 0 && i < ft_strlen((char *)s))
	{
		lengh++;
		i++;
	}
	return (lengh);
}

char	*ft_writeword(char const *s, int i)
{
	char	*word;
	int		x;

	word = (char *)malloc(sizeof(*word) * (ft_wordlengh(s, i) + 1));
	if (!word)
		return (0);
	x = 0;
	while (ft_isspace(s[i + x]) != 0 && (i + x) < ft_strlen((char *)s))
	{
		word[x] = s[i + x];
		x++;
	}
	word[x] = '\0';
	return (word);
}
