/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:22:21 by jgagnon           #+#    #+#             */
/*   Updated: 2022/07/18 17:53:20 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	str_to_int(char *arg)
{
	int	nb;
	int	i;
	int	signe;

	i = -1;
	nb = 0;
	signe = 1;
	if (arg[0] == '-')
	{
		i++;
		signe = -1;
	}
	while (arg[++i] != '\0')
		nb = (nb * 10) + (arg[i] - 0x30);
	return (nb * signe);
}

long long int	str_to_lli(char *arg)
{
	long long int	nb;
	int				i;
	int				signe;

	i = -1;
	nb = 0;
	signe = 1;
	if (arg[0] == '-')
	{
		i++;
		signe = -1;
	}
	while (arg[++i] != '\0')
		nb = (nb * 10) + (arg[i] - 0x30);
	return (nb * signe);
}

int	check_dup(t_lst *stack)
{
	t_pile	*i;
	t_pile	*j;

	i = stack->prem;
	j = i->suiv;
	while (i != NULL)
	{
		while (j != NULL)
		{
			if (i->val == j->val)
				return (2);
			j = j->suiv;
		}
		i = i->suiv;
		if (i != NULL)
			j = i->suiv;
	}
	return (0);
}

int	is_valid(char *arg)
{
	int				i;
	long long int	nb;

	i = -1;
	if (arg[0] == '\0')
		return (1);
	if (arg[0] == '-')
		i++;
	if (arg[0] == '-' && arg[1] == '\0')
		return (1);
	while (arg[++i] != '\0')
	{
		if (ft_isdigit((int)arg[i]) == 0)
			return (1);
	}
	nb = str_to_lli(arg);
	if (nb > INT_MAX || nb < INT_MIN)
		return (1);
	return (0);
}
