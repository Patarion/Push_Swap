/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move_stack-a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:49:12 by jgagnon           #+#    #+#             */
/*   Updated: 2022/07/18 14:25:27 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	p_a(t_lst *stack_a, t_lst *stack_b)
{
	t_pile	*tmp;

	if (!stack_b)
		return ;
	if (stack_b->prem == stack_b->der)
	{
		push_a_init(stack_a, stack_b);
		return ;
	}
	tmp = stack_b->prem;
	stack_b->prem = stack_b->prem->suiv;
	stack_b->prem->prec = NULL;
	if (stack_a->prem == NULL)
		stack_a_init(stack_a, tmp);
	else if (stack_a->prem != NULL)
	{
		stack_a->prem->prec = tmp;
		tmp->suiv = stack_a->prem;
		stack_a->prem = tmp;
		tmp->prec = NULL;
	}
	write(1, "pa\n", 3);
}

void	r_a(t_lst *lst)
{
	t_pile	*prem;
	t_pile	*deux;

	prem = lst->prem;
	deux = lst->prem->suiv;
	prem->suiv = NULL;
	deux->prec = NULL;
	prem->prec = lst->der;
	lst->der->suiv = prem;
	lst->der = prem;
	lst->prem = deux;
	write(1, "ra\n", 3);
}

void	r_r_a(t_lst *lst)
{
	t_pile	*der;
	t_pile	*a_der;

	der = lst->der;
	a_der = der->prec;
	a_der->suiv = NULL;
	lst->prem->prec = der;
	der->suiv = lst->prem;
	lst->prem = der;
	lst->der = a_der;
	write(1, "rra\n", 4);
}

void	s_a(t_lst *lst)
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
	write(1, "sa\n", 3);
}
