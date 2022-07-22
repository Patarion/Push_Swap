/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:21:39 by jgagnon           #+#    #+#             */
/*   Updated: 2022/07/18 17:30:26 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	find_max(t_lst *stack)
{
	int		i;
	t_pos	max;
	t_pile	*elem;

	i = nb_elem(stack);
	max.pos = i;
	max.val = INT_MIN;
	elem = stack->der;
	while (elem != NULL)
	{
		if (max.val < elem->val)
		{
			max.pos = i;
			max.val = elem->val;
		}
		i--;
		elem = elem->prec;
	}
	return (max.pos - 1);
}

int	find_min(t_lst *stack)
{
	int		i;
	t_pos	min;
	t_pile	*elem;

	i = nb_elem(stack);
	min.pos = i;
	min.val = INT_MAX;
	elem = stack->der;
	while (elem != NULL)
	{
		if (min.val > elem->val)
		{
			min.pos = i;
			min.val = elem->val;
		}
		i--;
		elem = elem->prec;
	}
	return (min.pos - 1);
}

void	lst_index(t_lst *stack)
{
	int		i;
	int		min;
	int		nbr_elem;
	t_pile	*elem;

	i = 1;
	elem = stack->prem;
	nbr_elem = nb_elem(stack);
	while (i <= nbr_elem)
	{
		min = INT_MAX;
		while (elem != NULL)
		{
			if (min > elem->val && elem->pos == -1)
				min = elem->val;
			elem = elem->suiv;
		}
		elem = stack->prem;
		while (elem != NULL && elem->val != min)
			elem = elem->suiv;
		elem->pos = i;
		i++;
		elem = stack->prem;
	}
}

int	lst_is_sorted(t_lst *stack_a, t_lst *stack_b)
{
	int		min;
	int		max;
	t_pile	*elem;

	elem = stack_a->prem;
	min = elem->pos;
	max = stack_a->der->pos;
	if (nb_elem(stack_b) != 0)
		return (-1);
	while (elem != NULL)
	{
		if (min != elem->pos)
			return (-1);
		min++;
		elem = elem->suiv;
	}
	if (min - 1 != max)
		return (-1);
	return (0);
}
