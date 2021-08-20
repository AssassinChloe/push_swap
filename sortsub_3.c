/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortsub_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:51:38 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/20 15:59:56 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sub_b_2(t_pile *b)
{
	if (b->sub[b->i] == 3 && b->pile[0] > b->pile[1]
		&& b->pile[0] > b->pile[2] && b->pile[1] < b->pile[2])
	{
		ft_rb(b);
		ft_sb(b);
		ft_rrb(b);
	}
	else if (b->sub[b->i] == 3 && b->pile[0] > b->pile[1]
		&& b->pile[0] < b->pile[2] && b->pile[1] < b->pile[2])
	{
		ft_rb(b);
		ft_sb(b);
		ft_rrb(b);
		ft_sb(b);
	}
	return ;
}

void	ft_sort3sub_b(t_pile *b)
{
	if (b->sub[b->i] == 2 && ft_checkifreversesorted(b) == 0)
		ft_sb(b);
	else if (b->sub[b->i] == 3 && b->pile[0] < b->pile[1]
		&& b->pile[0] > b->pile[2] && b->pile[1] > b->pile[2])
		ft_sb(b);
	else if (b->sub[b->i] == 3 && b->pile[0] < b->pile[1]
		&& b->pile[0] < b->pile[2] && b->pile[1] < b->pile[2])
	{
		ft_sb(b);
		ft_rb(b);
		ft_sb(b);
		ft_rrb(b);
		ft_sb(b);
	}
	else if (b->sub[b->i] == 3 && b->pile[0] < b->pile[1]
		&& b->pile[0] < b->pile[2] && b->pile[1] > b->pile[2])
	{
		ft_sb(b);
		ft_rb(b);
		ft_sb(b);
		ft_rrb(b);
	}
	else
		ft_sub_b_2(b);
	return ;
}

static void	ft_sub_a_2(t_pile *a)
{
	if (a->sub[a->i] == 3 && a->pile[0] < a->pile[1]
		&& a->pile[0] < a->pile[2] && a->pile[1] > a->pile[2])
	{
		ft_ra(a);
		ft_sa(a);
		ft_rra(a);
	}
	else if (a->sub[a->i] == 3 && a->pile[0] < a->pile[1]
		&& a->pile[0] > a->pile[2] && a->pile[1] > a->pile[2])
	{
		ft_ra(a);
		ft_sa(a);
		ft_rra(a);
		ft_sa(a);
	}
	return ;
}

void	ft_sort3sub_a(t_pile *a)
{
	if (a->sub[a->i] == 2 && ft_checkifsorted(a) == 0)
		ft_sa(a);
	else if (a->sub[a->i] == 3 && a->pile[0] > a->pile[1]
		&& a->pile[0] < a->pile[2] && a->pile[1] < a->pile[2])
		ft_sa(a);
	else if (a->sub[a->i] == 3 && a->pile[0] > a->pile[1]
		&& a->pile[0] > a->pile[2] && a->pile[1] > a->pile[2])
	{
		ft_sa(a);
		ft_ra(a);
		ft_sa(a);
		ft_rra(a);
		ft_sa(a);
	}
	else if (a->sub[a->i] == 3 && a->pile[0] > a->pile[1]
		&& a->pile[0] > a->pile[2] && a->pile[1] < a->pile[2])
	{
		ft_sa(a);
		ft_ra(a);
		ft_sa(a);
		ft_rra(a);
	}
	else
		ft_sub_a_2(a);
	return ;
}
