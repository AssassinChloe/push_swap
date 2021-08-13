/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:23:08 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/13 01:44:40 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_pile *a)
{
	if (a->pile[0] > a->pile[1] && a->pile[0] < a->pile[2]
			&& a->pile[1] < a->pile[2])
		ft_sa(a);
	else if (a->pile[0] > a->pile[1] && a->pile[0] > a->pile[2]
			&& a->pile[1] > a->pile[2])
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (a->pile[0] > a->pile[1] && a->pile[0] > a->pile[2]
			&& a->pile[1] < a->pile[2])
		ft_ra(a);
	else if (a->pile[0] < a->pile[1] && a->pile[0] < a->pile[2]
			&& a->pile[1] > a->pile[2])
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (a->pile[0] < a->pile[1] && a->pile[0] > a->pile[2]
			&& a->pile[1] > a->pile[2])
		ft_rra(a);
	return ;
}

void	ft_sort(t_pile *a)
{
	t_pile	b;

	b.pile = NULL;
	b.size = 0;
	b.sub = malloc(sizeof(int) * (a->size * 2));
	b.i = 0;
	if (a->size == 2)
	{
		ft_sa(a);
		return ;
	}
	else if (a->size == 3)
		ft_sort_3(a);
	else if (a->size > 3 && a->size <= 5)
		ft_newsort5(a, &b);
	else
		init_quick_sort(a, &b);
	if (a->pile)
		free(a->pile);
	free(a->sub);
	if (b.pile)
		free(b.pile);
	free(b.sub);
	return ;
}
