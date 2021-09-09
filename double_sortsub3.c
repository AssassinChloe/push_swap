/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_sortsub3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:51:38 by cassassi          #+#    #+#             */
/*   Updated: 2021/09/09 16:22:19 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_mv_324(int *tab[2], int i, int start)
{
	tab[i][start++] = 3;
	tab[i][start++] = 2;
	tab[i][start] = 4;
}

static int	ft_sub_b_2d(t_pile *b, int *tab[2])
{
	if (b->sub[b->i] == 3 && b->pile[0] > b->pile[1]
		&& b->pile[0] > b->pile[2] && b->pile[1] < b->pile[2])
	{
		ft_mv_324(tab, 1, 0);
		return (3);
	}
	else if (b->sub[b->i] == 3 && b->pile[0] < b->pile[1]
		&& b->pile[0] < b->pile[2] && b->pile[1] > b->pile[2])
	{
		tab[1][0] = 2;
		ft_mv_324(tab, 1, 1);
		return (4);
	}
	else if (b->sub[b->i] == 3 && b->pile[0] > b->pile[1]
		&& b->pile[0] < b->pile[2] && b->pile[1] < b->pile[2])
	{
		ft_mv_324(tab, 1, 0);
		tab[1][3] = 2;
		return (4);
	}
	return (0);
}

int	ft_sort3sub_bd(t_pile *b, int *tab[2])
{
	if ((b->sub[b->i] == 2 && ft_checkifreversesorted(b) == 0)
		|| (b->sub[b->i] == 3 && b->pile[0] < b->pile[1]
			&& b->pile[0] > b->pile[2] && b->pile[1] > b->pile[2]))
	{
		tab[1][0] = 2;
		return (1);
	}
	else if (b->sub[b->i] == 3 && b->pile[0] < b->pile[1]
		&& b->pile[0] < b->pile[2] && b->pile[1] < b->pile[2])
	{
		tab[1][0] = 2;
		ft_mv_324(tab, 1, 1);
		tab[1][4] = 2;
		return (5);
	}
	return (ft_sub_b_2d(b, tab));
}

static int	ft_sub_a_2d(t_pile *a, int *tab[2])
{
	if (a->sub[a->i] == 3 && a->pile[0] < a->pile[1]
		&& a->pile[0] < a->pile[2] && a->pile[1] > a->pile[2])
	{
		ft_mv_324(tab, 0, 0);
		return (3);
	}
	else if (a->sub[a->i] == 3 && a->pile[0] > a->pile[1]
		&& a->pile[0] > a->pile[2] && a->pile[1] < a->pile[2])
	{
		tab[0][0] = 2;
		ft_mv_324(tab, 0, 1);
		return (4);
	}
	else if (a->sub[a->i] == 3 && a->pile[0] < a->pile[1]
		&& a->pile[0] > a->pile[2] && a->pile[1] > a->pile[2])
	{
		ft_mv_324(tab, 0, 0);
		tab[0][3] = 2;
		return (4);
	}
	return (0);
}

int	ft_sort3sub_ad(t_pile *a, int *tab[2])
{
	if ((a->sub[a->i] == 2 && ft_checkifsorted(a) == 0)
		|| (a->sub[a->i] == 3 && a->pile[0] > a->pile[1]
			&& a->pile[0] < a->pile[2] && a->pile[1] < a->pile[2]))
	{
		tab[0][0] = 2;
		return (1);
	}
	else if (a->sub[a->i] == 3 && a->pile[0] > a->pile[1]
		&& a->pile[0] > a->pile[2] && a->pile[1] > a->pile[2])
	{
		tab[0][0] = 2;
		ft_mv_324(tab, 0, 1);
		tab[0][4] = 2;
		return (5);
	}
	return (ft_sub_a_2d(a, tab));
}
