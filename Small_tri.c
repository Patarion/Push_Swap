/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Small_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:18:17 by jgagnon           #+#    #+#             */
/*   Updated: 2022/07/18 18:09:13 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	rev_two_elem_sort(t_lst *stack)
{
	t_pile	*prem;
	t_pile	*deux;

	prem = stack->prem;
	deux = prem->suiv;
	if (prem->pos < deux->pos)
		s_b(stack);
}

void	two_elem_sort(t_lst *stack)
{
	t_pile	*prem;
	t_pile	*deux;

	prem = stack->prem;
	deux = prem->suiv;
	if (prem->pos > deux->pos)
		s_a(stack);
}

void	three_elem_tri(t_lst *stack)
{
	t_pile	*pr;
	t_pile	*dx;
	t_pile	*tr;

	pr = stack->prem;
	dx = pr->suiv;
	tr = dx->suiv;
	if (pr->pos > dx->pos && dx->pos < tr->pos && tr->pos > pr->pos)
		s_a(stack);
	else if (pr->pos > dx->pos && dx->pos > tr->pos && tr->pos < pr->pos)
	{
		s_a(stack);
		r_r_a(stack);
	}
	else if (pr->pos > dx->pos && dx->pos < tr->pos && tr->pos < pr->pos)
		r_a(stack);
	else if (pr->pos < dx->pos && dx->pos > tr->pos && tr->pos > pr->pos)
	{
		s_a(stack);
		r_a(stack);
	}
	else if (pr->pos < dx->pos && dx->pos > tr->pos && tr->pos < pr->pos)
		r_r_a(stack);
}

void	small_sort(t_lst *stack_a)
{
	int		med;
	int		i;
	t_lst	stack_b;

	lst_init(&stack_b);
	while (lst_is_sorted(stack_a, &stack_b) != 0)
	{
		while (nb_elem(stack_a) > 3)
		{
			med = nb_elem(stack_a) / 2;
			i = find_min(stack_a);
			if (i >= med)
				while (i++ < nb_elem(stack_a))
					r_r_a(stack_a);
			else if (i < med)
				while (i-- > 0)
					r_a(stack_a);
			p_b(stack_a, &stack_b);
		}
		mini_dispatch(stack_a);
		while (stack_b.prem != NULL && stack_b.der != NULL)
			p_a(stack_a, &stack_b);
	}
}

void	rev_small_sort(t_lst *stack_b, t_lst *stack_a)
{
	int	med;
	int	i;
	int	init;

	init = nb_elem(stack_b);
	while (rev_lst_is_sorted(stack_b) != 0)
	{
		while (nb_elem(stack_b) > 3)
		{
			med = nb_elem(stack_b) / 2;
			i = find_max(stack_b);
			if (i >= med)
				while (i++ < nb_elem(stack_b))
					r_r_b(stack_b);
			else if (i < med)
				while (i-- > 0)
					r_b(stack_b);
			p_a(stack_a, stack_b);
		}
		rev_mini_dispatch(stack_b);
	}
	while (stack_b->prem != NULL && stack_b->der != NULL)
		p_a(stack_a, stack_b);
}
