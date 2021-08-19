/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:38:54 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/19 14:39:48 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort5_b(t_pile *a, t_pile *b)
{
	int	i;
	int	pivot;
	int	rotation;
	int	size;

	rotation = 0;
	size = b->sub[b->i];
	pivot = ft_findmedstack(b);
	i = 0;
	while (i < size)
	{
		if (b->pile[0] > pivot)
		{
			ft_pa(a, b);
			b->sub[b->i]--;
			a->sub[a->i]++;
		}
		else
		{
			if (b->sub[b->i] > 1 && ft_anypaleft(b, pivot) == 1)
			{
				ft_rb(b);
				rotation++;
			}
		}
		i++;
	}
	while (b->i > 0 && rotation > 0)
	{
		ft_rrb(b);
		rotation--;
	}
	if (a->i == 0 || a->size <= 3)
		ft_sort_3(a);
	else
		ft_sort3sub_a(a);
	if (b->i == 0 || b->size <= 3)
		ft_sort_3b(b);
	else
		ft_sort3sub_b(b);
}

void ft_sort5_a(t_pile *a, t_pile *b)
{
	int i;
	int pivot;
	int rotation;
	int size;

	i = 0;
	rotation = 0;
	b->i++;
	b->sub[b->i] = 0;
	size = a->sub[a->i];
	pivot = ft_findmedstack(a);
	while (i < size)
	{
		if (a->pile[0] < pivot)
		{
			ft_pb(a, b);
			b->sub[b->i]++;
			a->sub[a->i]--;
		}
		else
		{
			if (a->sub[a->i] > 1 && ft_anypbleft(a, pivot) == 1)
			{
				ft_ra(a);
				rotation++;
			}
		}
		i++;
	}
	i = 0;
	while (a->i > 0 && rotation > 0)
	{
		ft_rra(a);
		rotation--;
	}
	if (a->i == 0 || a->size <= 3)
		ft_sort_3(a);
	else
		ft_sort3sub_a(a);
	if (b->i == 0 || b->size <= 3)
		ft_sort_3b(b);
	else
		ft_sort3sub_b(b);
	while (b->sub[b->i] > 0)
	{
			ft_pa(a, b);
			b->sub[b->i]--;
			a->sub[a->i]++;
	}
	b->i--;
}

