/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:19:36 by jgagnon           #+#    #+#             */
/*   Updated: 2022/07/19 18:21:20 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	lst_tri_dispatch(t_lst *stack)
{
	int	i;

	i = nb_elem(stack);
	if (i == 2)
		two_elem_sort(stack);
	else if (i == 3)
		three_elem_tri(stack);
	else if (i > 3 && i < 10)
		small_sort(stack);
	else if (i >= 10 && i <= 200)
		medium_sort(stack);
	else if (i > 200 && i <= INT_MAX)
		big_sort(stack);
	return ;
}

void	rev_mini_dispatch(t_lst *stack)
{
	if (nb_elem(stack) == 3)
		rev_three_elem_tri(stack);
	else if (nb_elem(stack) == 2)
		rev_two_elem_sort(stack);
	return ;
}

void	mini_dispatch(t_lst *stack)
{
	if (nb_elem(stack) == 3)
		three_elem_tri(stack);
	else if (nb_elem(stack) == 2)
		two_elem_sort(stack);
	return ;
}
