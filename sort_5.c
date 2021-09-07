/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:38:54 by cassassi          #+#    #+#             */
/*   Updated: 2021/09/07 08:12:45 by cassassi         ###   ########.fr       */
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
//	if (a->i == 0 || a->size <= 3)
//		ft_sort_3(a);
//	if ((a->i == 0 || a->size <= 3) && (b->i == 0 || b->size <= 3))
//		{
			ft_double_sort(a, b);	
//		}
//	else
//		ft_sort3sub_a(a);
//	if (b->i == 0 || b->size <= 3)
//		ft_sort_3b(b);
//	else
//		ft_sort3sub_b(b);
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
	if ((a->i == 0 || a->size <= 3) && (b->i == 0 || b->size <= 3))
		{
			ft_double_sort(a, b);	
		}
	//if (a->i == 0 || a->size <= 3)
	//	ft_sort_3(a);
	else
		ft_sort3sub_a(a);
	//if (b->i == 0 || b->size <= 3)
	//	ft_sort_3b(b);
	//else
		ft_sort3sub_b(b);
}
