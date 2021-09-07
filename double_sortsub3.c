/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_sortsub3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:51:38 by cassassi          #+#    #+#             */
/*   Updated: 2021/09/07 08:20:45 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sub_b_2(t_pile *b)
{
	if (b->sub[b->i] == 3 && b->pile[0] > b->pile[1]
		&& b->pile[0] > b->pile[2] && b->pile[1] < b->pile[2])
	{
		tab[1] = malloc(sizeof(int) * 3);
		tab[1][0] = 3;
		tab[1][1] = 2;
		tab[1][2] = 4;
		return (3);
	}
	else if (b->sub[b->i] == 3 && b->pile[0] > b->pile[1]
		&& b->pile[0] < b->pile[2] && b->pile[1] < b->pile[2])
	{
		tab[1] = malloc(sizeof(int) * 4);
		tab[1][0] = 3;
		tab[1][1] = 2;
		tab[1][2] = 4;
		tab[1][3] = 2;
		return (4);
	}
	return (0);
}

void	ft_sort3sub_b(t_pile *b)
{
	if (b->sub[b->i] == 2 && ft_checkifreversesorted(b) == 0)
	{
		tab[1] = malloc(sizeof(int) * 1);
		tab[1][0] = 2;
		return (1);
	}
	else if (b->sub[b->i] == 3 && b->pile[0] < b->pile[1]
		&& b->pile[0] > b->pile[2] && b->pile[1] > b->pile[2])
	{
		tab[1] = malloc(sizeof(int) * 1);
		tab[1][0] = 2;
		return (1);
	}
	else if (b->sub[b->i] == 3 && b->pile[0] < b->pile[1]
		&& b->pile[0] < b->pile[2] && b->pile[1] < b->pile[2])
	{
		tab[1] = malloc(sizeof(int) * 5);
		tab[1][0] = 2;
		tab[1][1] = 3;
		tab[1][2] = 2;
		tab[1][3] = 4;
		tab[1][4] = 2;
		return (5);
	}
	else if (b->sub[b->i] == 3 && b->pile[0] < b->pile[1]
		&& b->pile[0] < b->pile[2] && b->pile[1] > b->pile[2])
	{
		tab[1] = malloc(sizeof(int) * 4);
		tab[1][0] = 2;
		tab[1][1] = 3;
		tab[1][2] = 2;
		tab[1][3] = 4;
		return (4);
	}
	else
		ft_sub_b_2(b);
	return (0);
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
