/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Single_arg_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:12:00 by jgagnon           #+#    #+#             */
/*   Updated: 2022/07/19 18:12:46 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

char	**ft_split(char const *s)
{
	char	**tab;
	int		count;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s)
		return (0);
	count = ft_nbwords(s);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (0);
	while (count > 0)
	{
		while (ft_isspace(s[i]) == 0 && i < ft_strlen((char *)s))
			i++;
		tab[y] = ft_writeword(s, i);
		y++;
		count--;
		i = i + ft_wordlengh(s, i);
	}
	tab[y] = NULL;
	return (tab);
}

void	tab_clear(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i] != NULL)
		free(tab[i]);
	free(tab);
}
