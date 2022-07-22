/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:29:13 by jgagnon           #+#    #+#             */
/*   Updated: 2022/07/19 18:16:31 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct position
{
	int	val;
	int	pos;
}	t_pos;

typedef struct pile
{
	int			val;
	int			pos;
	struct pile	*prec;
	struct pile	*suiv;
}	t_pile;

typedef struct lst_double
{
	t_pile	*prem;
	t_pile	*der;
}	t_lst;

void			lst_init(t_lst *lst);
int				lst_pop_Back(t_lst *lst);
int				lst_popFront(t_lst *lst);
void			lst_print(t_lst lst);
void			lst_clear(t_lst *lst);
void			lst_pushBack(t_lst *lst, int val);
void			lst_pushFront(t_lst *lst, int val);
void			lst_bringFront(t_lst *lst);
int				ft_isdigit(int c);
int				str_to_int(char *arg);
long long int	str_to_lli(char *arg);
int				check_dup(t_lst *stack);
int				is_valid(char *arg);
int				find_pos(t_lst *stack, int val);
void			lst_tri(t_lst *stack_a);
int				nb_elem(t_lst *stack);
void			lst_push_front(t_lst *lst, int val);
void			r_a(t_lst *lst);
void			r_r_a(t_lst *lst);
void			r_b(t_lst *lst);
void			r_r_b(t_lst *lst);
void			p_a(t_lst *stack_a, t_lst *stack_b);
void			p_b(t_lst *stack_a, t_lst *stack_b);
void			s_a(t_lst *lst);
void			s_b(t_lst *lst);
void			three_elem_tri(t_lst *stack);
void			lst_index(t_lst *stack);
void			two_elem_sort(t_lst *stack);
int				lst_is_sorted(t_lst *stack_a, t_lst *stack_b);
void			small_sort(t_lst *stack_a);
void			lst_copy(t_lst *lst, t_pile *elem);
void			medium_sort(t_lst *stack_a);
int				near_min(t_lst *stack, int range, int base);
void			rev_small_sort(t_lst *stack_b, t_lst *stack_a);
void			rev_three_elem_tri(t_lst *stack);
void			stack_a_init(t_lst *stack_a, t_pile *tmp);
void			push_a_init(t_lst *stack_a, t_lst *stack_b);
void			stack_b_init(t_lst *stack_b, t_pile *tmp);
void			push_b_init(t_lst *stack_a, t_lst *stack_b);
void			lst_tri_dispatch(t_lst *stack);
int				find_max(t_lst *stack);
int				find_min(t_lst *stack);
void			align_move(t_lst *stack, int max);
void			get_min(t_lst *stack_a, t_lst *stack_b, int range, int base);
int				ft_nbwords(char	const *s);
int				ft_wordlengh(char const *s, int i);
char			*ft_writeword(char const *s, int i);
char			**ft_split(char const *s);
int				ft_isspace(int c);
int				ft_strlen(char *str);
void			tab_clear(char **tab);
void			mini_dispatch(t_lst *stack);
void			rev_mini_dispatch(t_lst *stack);
void			rev_two_elem_sort(t_lst *stack);
void			lst_tri(t_lst *mapile);
int				rev_lst_is_sorted(t_lst *stack_b);
void			big_sort(t_lst *stack_a);

#endif
