/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:28:14 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/20 15:57:10 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_pile *a)
{
	if (a->size == 2 && ft_checkifallsorted(a) == 0)
		ft_sa(a);
	else if (a->size == 3 && a->pile[0] > a->pile[1]
		&& a->pile[0] < a->pile[2] && a->pile[1] < a->pile[2])
		ft_sa(a);
	else if (a->size == 3 && a->pile[0] > a->pile[1]
		&& a->pile[0] > a->pile[2] && a->pile[1] > a->pile[2])
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (a->size == 3 && a->pile[0] > a->pile[1]
		&& a->pile[0] > a->pile[2] && a->pile[1] < a->pile[2])
		ft_ra(a);
	else if (a->size == 3 && a->pile[0] < a->pile[1]
		&& a->pile[0] < a->pile[2] && a->pile[1] > a->pile[2])
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (a->size == 3 && a->pile[0] < a->pile[1]
		&& a->pile[0] > a->pile[2] && a->pile[1] > a->pile[2])
		ft_rra(a);
	return ;
}

void	ft_sort_3b(t_pile *b)
{
	if (b->size == 2 && ft_checkifreversesorted(b) == 0)
		ft_sb(b);
	else if (b->size == 3 && b->pile[0] < b->pile[1]
		&& b->pile[0] > b->pile[2] && b->pile[1] > b->pile[2])
		ft_sb(b);
	else if (b->size == 3 && b->pile[0] < b->pile[1]
		&& b->pile[0] < b->pile[2] && b->pile[1] < b->pile[2])
	{
		ft_sb(b);
		ft_rrb(b);
	}
	else if (b->size == 3 && b->pile[0] < b->pile[1]
		&& b->pile[0] < b->pile[2] && b->pile[1] > b->pile[2])
		ft_rb(b);
	else if (b->size == 3 && b->pile[0] > b->pile[1]
		&& b->pile[0] > b->pile[2] && b->pile[1] < b->pile[2])
	{
		ft_sb(b);
		ft_rb(b);
	}
	else if (b->size == 3 && b->pile[0] > b->pile[1]
		&& b->pile[0] < b->pile[2] && b->pile[1] < b->pile[2])
		ft_rrb(b);
	return ;
}
