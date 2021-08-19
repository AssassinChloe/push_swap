/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:48:31 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/19 14:42:40 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_quick_sort(t_pile *a, t_pile *b)
{
	int pivot;
	int i;

	i = 0;
	a->sub[0] = a->size;
	pivot = ft_findmedstack(a);
	while (i < a->sub[0])
	{
		if (a->pile[0] <= pivot)
		{
			if (ft_pb(a, b) < 0)
			{
				printf("error pb\n");
				return ;
			}
		}
		else
			if (ft_anypbleft(a, pivot) == 1)
				ft_ra(a);
		i++;
	}
	a->sub[0] = a->size;
	b->sub[0] = b->size;
	ft_quick_sort(a, b);
}

void	ft_quick_sort(t_pile *a, t_pile *b)
{
	int size_init;
	int i;
	int pivot;
	int rotation;

	if (ft_checkifsorted(a) == 1 && b->size == 0)
		return ;	
	while (a->sub[a->i] > 5 && ft_checkifsorted(a) == 0)
	{
		i = 0;
		b->i++;
		b->sub[b->i] = 0;
		rotation = 0;
		pivot = ft_findmedstack(a);
		size_init = a->sub[a->i];
		while (i < size_init)
		{
			if (a->pile[0] <= pivot)
			{
				if (ft_pb(a, b) < 0)
				{
					printf("error pb\n");
					return ;
				}
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
		while (a->i > 0 && rotation > 0)
		{
			ft_rra(a);
			rotation--;
		}
	}
	if (a->sub[a->i] > 5 && ft_checkifsorted(a) == 1)
	{
		a->i++;
		a->sub[a->i] = 0;
	}
	if (a->sub[a->i] <= 5 && a->sub[a->i] > 0)
	{
		if (a->sub[a->i] == 2 && ft_checkifsorted(a) == 0)
			ft_sa(a);
		else if (a->sub[a->i] == 3 && ft_checkifsorted(a) == 0)
			ft_sort3sub_a(a);
		else if(a->sub[a->i] > 3 && ft_checkifsorted(a) == 0)
			ft_sort5_a(a, b);
		a->i++;
		a->sub[a->i] = 0;
	}	
	if (b->sub[b->i] <= 5 && b->sub[b->i] > 0)
	{
		if (b->sub[b->i] == 2 && ft_checkifreversesorted(b) == 0)
			ft_sb(b);
		else if (b->sub[b->i] == 3 && ft_checkifreversesorted(b) == 0)
			ft_sort3sub_b(b);
		else if(b->sub[b->i] > 3 && ft_checkifreversesorted(b) == 0)
			ft_sort5_b(a, b);
		while (b->sub[b->i] > 0)
		{
			ft_pa(a, b);
			a->sub[a->i]++;
			b->sub[b->i]--;
		}
		b->i--;
		if (b->i < 0)
			b->i = 0;
		
	}
	else
	{
		i = 0;
		size_init = b->sub[b->i];
		rotation = 0;
		pivot = ft_findmedstack(b);
		while (i < size_init)
		{
			if (b->pile[0] >= pivot)
			{
				if (ft_pa(a, b) < 0)
				{
					printf("error pa\n");
					return ;
				}
				a->sub[a->i]++;
				b->sub[b->i]--;
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
	}
	if (ft_checkifallsorted(a) == 1 && ft_checkifallreversesorted(b) == 1)
	{
		while (b->size > 0)
			ft_pa(a, b);	
		return ;
	}
	ft_quick_sort(a, b);
}
