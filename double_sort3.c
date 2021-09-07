/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_sort3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:28:14 by cassassi          #+#    #+#             */
/*   Updated: 2021/09/07 08:20:48 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_acton_a (t_pile *a, int *tab[2], int *i)
{
	if (tab[0][*i] == 2)
		ft_sa(a);
	else if (tab[0][*i] == 3)
		ft_ra(a);
	else
		ft_rra(a);
	(*i)++;
}
void	ft_acton_b (t_pile *b, int *tab[2], int *j)
{
	if (tab[1][*j] == 2)
		ft_sb(b);
	else if (tab[1][*j] == 3)
		ft_rb(b);
	else
		ft_rrb(b);
	(*j)++;
}
void	ft_double_sort(t_pile *a, t_pile *b)
{
	int *tab[2];
	int	i;
	int j;
	int mva;
	int	mvb;

	i = 0;
	j = 0;
	tab[0] = NULL;
	tab[1] = NULL;
	if ((a->i == 0 || a->size <= 3) && (b->i == 0 || b->size <= 3))
	{
		mva = ft_sort_3d(a, tab);
		mvb = ft_sort_3bd(b, tab);
	}
	else
	{
		mva = ft_sort_3subd(a, tab);
		mvb = ft_sort_3subbd(b, tab);
	}
/*	while (i < mva)
		printf("%d", tab[0][i++]);
	printf("\n");
	while (j < mvb)
		printf("%d", tab[1][j++]);
	printf("\n");
	i = 0;
	j = 0;
	*/
	while (i < mva && j < mvb)
	{
		if (tab[0][i] == tab[1][j])
		{
			if (tab[0][i] == 2)
				ft_ss(a, b);
			else if (tab[0][i] == 3)
				ft_rr(a, b);
			else
				ft_rrr(a, b);
			i++;
			j++;
		}
		else
		{
			if (mva > mvb)
				ft_acton_a(a, tab, &i);
			else if (mvb > mva)
				ft_acton_b(b, tab, &j);
			else
			{
				if (i < mva)
					ft_acton_a(a, tab, &i);
				if (j < mvb)
					ft_acton_b(b, tab, &j);
			}
		}
	}
	while (i < mva || j < mvb)
	{
	if (i < mva)
		ft_acton_a(a, tab, &i);
	if (j < mvb)
		ft_acton_b(b, tab, &j);
	}
	free(tab[0]);
	free(tab[1]);
	tab[0] = NULL;
	tab[1] = NULL;
}

int	ft_sort_3d(t_pile *a, int *tab[2])
{
	if (a->size == 2 && ft_checkifallsorted(a) == 0)
	{
		tab[0] = malloc(sizeof(int) * 1);
		tab[0][0] = 2;
		return (1);
	}
	else if (a->size == 3 && a->pile[0] > a->pile[1]
			&& a->pile[0] < a->pile[2] && a->pile[1] < a->pile[2])
	{
		tab[0] = malloc(sizeof(int) * 1);
		tab[0][0] = 2;
		return (1);
	}
	else if (a->size == 3 && a->pile[0] > a->pile[1]
			&& a->pile[0] > a->pile[2] && a->pile[1] > a->pile[2])
	{
		tab[0] = malloc(sizeof(int) * 2);
		tab[0][0] = 2;
		tab[0][1] = 4;
		return (2);
	}
	else if (a->size == 3 && a->pile[0] > a->pile[1]
			&& a->pile[0] > a->pile[2] && a->pile[1] < a->pile[2])
	{
		tab[0] = malloc(sizeof(int) * 1);
		tab[0][0] = 3;
		return (1);
	}
	else if (a->size == 3 && a->pile[0] < a->pile[1]
			&& a->pile[0] < a->pile[2] && a->pile[1] > a->pile[2])
	{
		tab[0] = malloc(sizeof(int) * 2);
		tab[0][0] = 2;
		tab[0][1] = 3;
		return (2);
	}
	else if (a->size == 3 && a->pile[0] < a->pile[1]
			&& a->pile[0] > a->pile[2] && a->pile[1] > a->pile[2])
	{
		tab[0] = malloc(sizeof(int) * 1);
		tab[0][0] = 4;
		return (1);
	}
	return (0);
}

int	ft_sort_3bd(t_pile *b, int *tab[2])
{
	if (b->size == 2 && ft_checkifreversesorted(b) == 0)
	{
		tab[1] = malloc(sizeof(int) * 1);
		tab[1][0] = 2;
		return (1);
	}
	else if (b->size == 3 && b->pile[0] < b->pile[1]
			&& b->pile[0] > b->pile[2] && b->pile[1] > b->pile[2])
	{
		tab[1] = malloc(sizeof(int) * 1);
		tab[1][0] = 2;
		return (1);
	}
	else if (b->size == 3 && b->pile[0] < b->pile[1]
			&& b->pile[0] < b->pile[2] && b->pile[1] < b->pile[2])
	{
		tab[1] = malloc(sizeof(int) * 2);
		tab[1][0] = 2;
		tab[1][1] = 4;
		return (2);
	}
	else if (b->size == 3 && b->pile[0] < b->pile[1]
			&& b->pile[0] < b->pile[2] && b->pile[1] > b->pile[2])
	{
		tab[1] = malloc(sizeof(int) * 1);
		tab[1][0] = 3;
		return (1);
	}
	else if (b->size == 3 && b->pile[0] > b->pile[1]
			&& b->pile[0] > b->pile[2] && b->pile[1] < b->pile[2])
	{
		tab[1] = malloc(sizeof(int) * 2);
		tab[1][0] = 2;
		tab[1][1] = 3;
		return (2);
	}
	else if (b->size == 3 && b->pile[0] > b->pile[1]
			&& b->pile[0] < b->pile[2] && b->pile[1] < b->pile[2])
	{
		tab[1] = malloc(sizeof(int) * 1);
		tab[1][0] = 4;
		return (1);
	}
	return (0);
}
