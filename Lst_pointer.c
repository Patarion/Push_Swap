/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lst_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:10:28 by jgagnon           #+#    #+#             */
/*   Updated: 2022/07/18 15:11:25 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	push_a_init(t_lst *stack_a, t_lst *stack_b)
{
	lst_copy(stack_a, stack_b->prem);
	lst_init(stack_b);
	write(1, "pa\n", 3);
}

void	stack_a_init(t_lst *stack_a, t_pile *tmp)
{
	stack_a->prem = tmp;
	stack_a->der = tmp;
	stack_a->prem->suiv = NULL;
	stack_a->prem->prec = NULL;
}

void	push_b_init(t_lst *stack_a, t_lst *stack_b)
{
	lst_copy(stack_b, stack_a->prem);
	lst_init(stack_a);
	write(1, "pb\n", 3);
}

void	stack_b_init(t_lst *stack_b, t_pile *tmp)
{
	stack_b->prem = tmp;
	stack_b->der = tmp;
	stack_b->prem->suiv = NULL;
	stack_b->prem->prec = NULL;
}
