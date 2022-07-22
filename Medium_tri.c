/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Medium_tri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:45:32 by jgagnon           #+#    #+#             */
/*   Updated: 2022/07/18 17:50:52 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	align_stack(t_lst *stack, int range, int base)
{
	t_pile	*elem;
	int		i;
	int		min;
	int		max;

	i = -1;
	min = 0;
	max = 0;
	elem = stack->prem;
	while (elem != NULL && ++i < INT_MAX)
	{
		if (elem->pos == (range - base))
			max = i;
		else if (elem->pos == 1)
			min = i;
		elem = elem->suiv;
	}
	if (max < min)
		align_move(stack, max);
}

int	rev_lst_is_sorted(t_lst *stack_b)
{
	int		min;
	int		max;
	t_pile	*elem;

	elem = stack_b->prem;
	min = elem->pos;
	max = stack_b->der->pos;
	while (elem != NULL)
	{
		if (min != elem->pos)
			return (-1);
		min--;
		elem = elem->suiv;
	}
	if (min + 1 != max)
		return (-1);
	return (0);
}

void	rev_three_elem_tri(t_lst *stack)
{
	t_pile	*pr;
	t_pile	*dx;
	t_pile	*tr;

	pr = stack->prem;
	dx = pr->suiv;
	tr = dx->suiv;
	if (pr->pos > dx->pos && dx->pos < tr->pos && tr->pos > pr->pos)
		r_r_b(stack);
	else if (pr->pos > dx->pos && dx->pos < tr->pos && tr->pos < pr->pos)
	{
		s_b(stack);
		r_b(stack);
	}
	else if (pr->pos < dx->pos && dx->pos > tr->pos && tr->pos > pr->pos)
		r_b(stack);
	else if (pr->pos < dx->pos && dx->pos > tr->pos && tr->pos < pr->pos)
		s_b(stack);
	else if (pr->pos < dx->pos && dx->pos < tr->pos && tr->pos > pr->pos)
	{
		s_b(stack);
		r_r_b(stack);
	}
}

void	medium_sort(t_lst *stack_a)
{
	int		range;
	int		base;
	t_lst	stack_b;

	lst_init(&stack_b);
	range = nb_elem(stack_a) / 6 + 10;
	base = range;
	while (lst_is_sorted(stack_a, &stack_b) != 0)
	{
		while (near_min(stack_a, range, base) >= 0)
			get_min(stack_a, &stack_b, range, base);
		align_stack(stack_a, range, base);
		range += base;
		rev_small_sort(&stack_b, stack_a);
		if (range >= (nb_elem(stack_a) + base))
			while (stack_a->prem->pos != 1)
				r_a(stack_a);
	}
}

void	big_sort(t_lst *stack_a)
{
	int		range;
	int		base;
	t_lst	stack_b;

	lst_init(&stack_b);
	range = nb_elem(stack_a) / 10;
	base = range;
	while (lst_is_sorted(stack_a, &stack_b) != 0)
	{
		while (near_min(stack_a, range, base) >= 0)
			get_min(stack_a, &stack_b, range, base);
		align_stack(stack_a, range, base);
		range += base;
		rev_small_sort(&stack_b, stack_a);
		if (range >= (nb_elem(stack_a) + base))
			while (stack_a->prem->pos != 1)
				r_a(stack_a);
	}
}
