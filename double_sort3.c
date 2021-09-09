/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_sort3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:28:14 by cassassi          #+#    #+#             */
/*   Updated: 2021/09/09 16:22:54 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sort_3d2(t_pile *a, int *tab[2])
{
	if (a->size == 3 && a->pile[0] < a->pile[1]
		&& a->pile[0] < a->pile[2] && a->pile[1] > a->pile[2])
	{
		tab[0][0] = 2;
		tab[0][1] = 3;
		return (2);
	}
	else if (a->size == 3 && a->pile[0] < a->pile[1]
		&& a->pile[0] > a->pile[2] && a->pile[1] > a->pile[2])
	{
		tab[0][0] = 4;
		return (1);
	}
	return (0);
}

int	ft_sort_3d(t_pile *a, int *tab[2])
{
	if ((a->size == 2 && ft_checkifallsorted(a) == 0)
		|| (a->size == 3 && a->pile[0] > a->pile[1]
			&& a->pile[0] < a->pile[2] && a->pile[1] < a->pile[2]))
	{
		tab[0][0] = 2;
		return (1);
	}
	else if (a->size == 3 && a->pile[0] > a->pile[1]
		&& a->pile[0] > a->pile[2] && a->pile[1] > a->pile[2])
	{
		tab[0][0] = 2;
		tab[0][1] = 4;
		return (2);
	}
	else if (a->size == 3 && a->pile[0] > a->pile[1]
		&& a->pile[0] > a->pile[2] && a->pile[1] < a->pile[2])
	{
		tab[0][0] = 3;
		return (1);
	}
	return (ft_sort_3d2(a, tab));
}

static int	ft_sort_3bd2(t_pile *b, int *tab[2])
{
	if (b->size == 3 && b->pile[0] > b->pile[1]
		&& b->pile[0] > b->pile[2] && b->pile[1] < b->pile[2])
	{
		tab[1][0] = 2;
		tab[1][1] = 3;
		return (2);
	}
	else if (b->size == 3 && b->pile[0] > b->pile[1]
		&& b->pile[0] < b->pile[2] && b->pile[1] < b->pile[2])
	{
		tab[1][0] = 4;
		return (1);
	}
	return (0);
}

int	ft_sort_3bd(t_pile *b, int *tab[2])
{
	if ((b->size == 2 && ft_checkifreversesorted(b) == 0)
		|| (b->size == 3 && b->pile[0] < b->pile[1]
			&& b->pile[0] > b->pile[2] && b->pile[1] > b->pile[2]))
	{
		tab[1][0] = 2;
		return (1);
	}
	else if (b->size == 3 && b->pile[0] < b->pile[1]
		&& b->pile[0] < b->pile[2] && b->pile[1] < b->pile[2])
	{
		tab[1][0] = 2;
		tab[1][1] = 4;
		return (2);
	}
	else if (b->size == 3 && b->pile[0] < b->pile[1]
		&& b->pile[0] < b->pile[2] && b->pile[1] > b->pile[2])
	{
		tab[1][0] = 3;
		return (1);
	}
	return (ft_sort_3bd2(b, tab));
}
