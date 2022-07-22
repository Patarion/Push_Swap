/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lst_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:26:48 by jgagnon           #+#    #+#             */
/*   Updated: 2022/07/18 17:31:44 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	lst_copy(t_lst *lst, t_pile *elem)
{
	t_pile	*nouv;

	nouv = malloc(sizeof(t_pile));
	if (!nouv)
		exit(EXIT_FAILURE);
	nouv->val = elem->val;
	nouv->pos = elem->pos;
	nouv->suiv = lst->prem;
	nouv->prec = NULL;
	if (lst->prem)
		lst->prem->prec = nouv;
	else
		lst->der = nouv;
	lst->prem = nouv;
	free(elem);
}

int	near_min(t_lst *stack, int range, int base)
{
	int		i;
	int		j;
	t_pile	*fin;
	t_pile	*deb;

	i = nb_elem(stack) - 1;
	j = 0;
	fin = stack->der;
	deb = stack->prem;
	while (fin != NULL && deb != NULL)
	{
		if (deb->pos <= range && deb->pos > (range - base))
			return (j);
		if (fin->pos <= range && fin->pos > (range - base))
			return (i);
		i--;
		j++;
		fin = fin->prec;
		deb = deb->suiv;
	}
	return (-1);
}

void	align_move(t_lst *stack, int max)
{
	if (max < nb_elem(stack) / 2)
		while (stack->prem->pos != 1)
			r_a(stack);
	else if (max > nb_elem(stack) / 2)
		while (stack->prem->pos != 1)
			r_r_a(stack);
}

void	get_min(t_lst *stack_a, t_lst *stack_b, int range, int base)
{
	int	i;
	int	med;

	med = nb_elem(stack_a) / 2;
	i = near_min(stack_a, range, base);
	if (i >= med)
		while (i++ < nb_elem(stack_a))
			r_r_a(stack_a);
	else if (i < med)
		while (i-- > 0)
			r_a(stack_a);
	p_b(stack_a, stack_b);
}
