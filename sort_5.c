/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:38:54 by cassassi          #+#    #+#             */
/*   Updated: 2021/09/09 16:02:46 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort5_b(t_pile *a, t_pile *b)
{
	b->rot = 0;
	if (b->sub[b->i] > 3)
	{
		ft_findmedstack(b);
		ft_divide_b(a, b, b->sub[b->i]);
		while (b->i > 0 && b->rot > 0)
		{
			ft_rrb(b);
			b->rot--;
		}
	}
	ft_double_sort(a, b);
}

void	ft_sort5_a(t_pile *a, t_pile *b)
{
	a->rot = 0;
	b->i++;
	b->sub[b->i] = 0;
	if (a->sub[a->i] > 3)
	{
		ft_findmedstack(a);
		ft_divide_a(a, b, a->sub[a->i]);
		while (a->i > 0 && a->rot > 0)
		{
			ft_rra(a);
			a->rot--;
		}
	}
	ft_double_sort(a, b);
}
