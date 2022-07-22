/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:07:41 by jgagnon           #+#    #+#             */
/*   Updated: 2022/07/19 18:19:27 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	lst_tri(t_lst *mapile)
{
	lst_index(mapile);
	lst_tri_dispatch(mapile);
	if (mapile->prem != NULL && mapile->der != NULL)
		lst_clear(mapile);
}

void	single_arg(char **argv, t_lst *mapile)
{
	char	**tab;
	int		j;

	j = 0;
	tab = ft_split(argv[1]);
	while (tab[j] != NULL && is_valid(tab[j]) == 0)
		j++;
	if (tab[j] != NULL)
	{
		write(2, "Error\n", 6);
		tab_clear(tab);
		exit(EXIT_FAILURE);
	}
	while (--j >= 0)
		lst_push_front(mapile, str_to_int(tab[j]));
	tab_clear(tab);
	if (check_dup(mapile) == 2)
	{
		lst_clear(mapile);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	lst_tri(mapile);
}

void	mult_arg(int argc, char **argv, t_lst *mapile)
{
	int	i;

	i = 1;
	while (++i <= argc && is_valid(argv[i - 1]) == 0)
		;
	if ((i - 1) != argc)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	while (--i >= 2)
		lst_push_front(mapile, str_to_int(argv[i - 1]));
	if (check_dup(mapile) == 2)
	{
		lst_clear(mapile);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	lst_tri(mapile);
}

int	main(int argc, char **argv)
{
	t_lst	mapile;

	if (argc < 2 || ft_strlen(argv[1]) == 0)
		return (0);
	lst_init(&mapile);
	if (argc > 2)
		mult_arg(argc, argv, &mapile);
	else if (argc == 2)
		single_arg(argv, &mapile);
}
