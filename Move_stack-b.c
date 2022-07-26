/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move_stack-b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:29:03 by jgagnon           #+#    #+#             */
/*   Updated: 2022/07/18 14:32:55 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	r_r_b(t_lst *lst)
{
	t_pile	*der;
	t_pile	*a_der;

	if (lst->prem == lst->der)
		return ;
	der = lst->der;
	a_der = der->prec;
	a_der->suiv = NULL;
	lst->prem->prec = der;
	der->suiv = lst->prem;
	lst->prem = der;
	lst->der = a_der;
	write(1, "rrb\n", 4);
}

void	r_b(t_lst *lst)
{
	t_pile	*prem;
	t_pile	*deux;

	if (lst->prem == lst->der)
		return ;
	prem = lst->prem;
	deux = lst->prem->suiv;
	prem->suiv = NULL;
	deux->prec = NULL;
	prem->prec = lst->der;
	lst->der->suiv = prem;
	lst->der = prem;
	lst->prem = deux;
	write(1, "rb\n", 3);
}

void	p_b(t_lst *stack_a, t_lst *stack_b)
{
	t_pile	*tmp;

	if (stack_a == NULL)
		return ;
	if (stack_a->prem == stack_a->der)
	{
		push_b_init(stack_a, stack_b);
		return ;
	}
	tmp = stack_a->prem;
	stack_a->prem = stack_a->prem->suiv;
	stack_a->prem->prec = NULL;
	if (stack_b->prem == NULL)
		stack_b_init(stack_b, tmp);
	else if (stack_b->prem != NULL)
	{
		stack_b->prem->prec = tmp;
		tmp->suiv = stack_b->prem;
		stack_b->prem = tmp;
		tmp->prec = NULL;
	}
	write(1, "pb\n", 3);
}

void	s_b(t_lst *lst)
{
	t_pile	*prem;
	t_pile	*deux;

	if (nb_elem(lst) == 1)
		return ;
	prem = lst->prem;
	deux = prem->suiv;
	if (nb_elem(lst) >= 3)
	{
		deux->suiv->prec = prem;
		prem->suiv = deux->suiv;
		deux->suiv = prem;
		deux->prec = NULL;
	}
	else if (nb_elem(lst) == 2)
	{
		deux->suiv = prem;
		deux->prec = NULL;
		prem->suiv = NULL;
		lst->der = prem;
	}
	prem->prec = deux;
	lst->prem = deux;
	write(1, "sb\n", 3);
}
