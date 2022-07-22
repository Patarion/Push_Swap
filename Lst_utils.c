/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:11:47 by jgagnon           #+#    #+#             */
/*   Updated: 2022/07/18 15:14:52 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	lst_init(t_lst *lst)
{
	lst->prem = NULL;
	lst->der = NULL;
}

void	lst_clear(t_lst *lst)
{
	t_pile	*elem;
	t_pile	*tmp;

	elem = lst->prem;
	while (elem)
	{
		tmp = elem;
		elem = elem->suiv;
		free(tmp);
	}
	lst->prem = NULL;
	lst->der = NULL;
}

void	lst_push_front(t_lst *lst, int val)
{
	t_pile	*nouv;

	nouv = malloc(sizeof(t_pile));
	if (!nouv)
		exit(EXIT_FAILURE);
	nouv->val = val;
	nouv->suiv = lst->prem;
	nouv->prec = NULL;
	nouv->pos = -1;
	if (lst->prem)
		lst->prem->prec = nouv;
	else
		lst->der = nouv;
	lst->prem = nouv;
}

int	nb_elem(t_lst *stack)
{
	int		i;
	t_pile	*elem;

	i = 0;
	elem = stack->prem;
	if (elem == NULL)
		return (0);
	while (elem != NULL)
	{
		elem = elem->suiv;
		i++;
	}
	return (i);
}
