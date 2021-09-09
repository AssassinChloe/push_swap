/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:38:37 by cassassi          #+#    #+#             */
/*   Updated: 2021/09/09 16:42:10 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_nb_mv(t_pile *a, t_pile *b, t_move *mv, int *tab[2])
{
	if ((a->i == 0 || a->size <= 3) || (b->i == 0 || b->size <= 3))
	{
		if (a->i == 0 || a->size <= 3)
			mv->a = ft_sort_3d(a, tab);
		else
			mv->a = ft_sort3sub_ad(a, tab);
		if (b->i == 0 || b->size <= 3)
			mv->b = ft_sort_3bd(b, tab);
		else
			mv->b = ft_sort3sub_bd(b, tab);
	}
	else
	{
		mv->a = ft_sort3sub_ad(a, tab);
		mv->b = ft_sort3sub_bd(b, tab);
	}
}

static void	ft_make_mv2(t_pile *a, t_pile *b, t_move *mv, int *tab[2])
{
	if (mv->i < mv->a)
		ft_acton_a(a, tab, &mv->i);
	if (mv->j < mv->b)
		ft_acton_b(b, tab, &mv->j);
}

static void	ft_make_mv(t_pile *a, t_pile *b, t_move *mv, int *tab[2])
{
	while (mv->i < mv->a && mv->j < mv->b)
	{
		if (tab[0][mv->i] == tab[1][mv->j])
		{
			if (tab[0][mv->i] == 2)
				ft_ss(a, b);
			else if (tab[0][mv->i] == 3)
				ft_rr(a, b);
			else
				ft_rrr(a, b);
			mv->i++;
			mv->j++;
		}
		else
		{
			if (mv->a > mv->b)
				ft_acton_a(a, tab, &mv->i);
			else if (mv->b > mv->a)
				ft_acton_b(b, tab, &mv->j);
			else
				ft_make_mv2(a, b, mv, tab);
		}
	}
	while (mv->i < mv->a || mv->j < mv->b)
		ft_make_mv2(a, b, mv, tab);
}

void	ft_double_sort(t_pile *a, t_pile *b)
{
	int		*tab[2];
	t_move	mv;

	mv.i = 0;
	mv.j = 0;
	tab[0] = NULL;
	tab[0] = malloc(sizeof(int) * 5);
	tab[1] = NULL;
	tab[1] = malloc(sizeof(int) * 5);
	if (!tab[0] || !tab[1])
	{
		free(tab[0]);
		tab[0] = NULL;
		free(tab[1]);
		tab[1] = NULL;
		ft_error(a, b);
	}
	ft_nb_mv(a, b, &mv, tab);
	ft_make_mv(a, b, &mv, tab);
	free(tab[0]);
	tab[0] = NULL;
	free(tab[1]);
	tab[1] = NULL;
}
