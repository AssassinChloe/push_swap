/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:48:31 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/24 10:56:11 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_pile_a(t_pile *a, t_pile *b)
{
	a->rot = 0;
	ft_findmedstack(a);
	ft_divide_a(a, b, a->sub[a->i]);
	while (a->i > 0 && a->rot > 0)
	{
		ft_rra(a);
		a->rot--;
	}
}

static void	handle_pile_b(t_pile *a, t_pile *b)
{
	b->rot = 0;
	ft_findmedstack(b);
	ft_divide_b(a, b, b->sub[b->i]);
	while (b->i > 0 && b->rot > 0)
	{
		ft_rrb(b);
		b->rot--;
	}
}

void	init_quick_sort(t_pile *a, t_pile *b)
{
	a->rot = 0;
	b->rot = 0;
	a->sub[0] = a->size;
	ft_findmedstack(a);
	ft_divide_a(a, b, a->size);
	ft_quick_sort(a, b);
}

void	ft_quick_sort(t_pile *a, t_pile *b)
{
	int i = 0;
	if (ft_checkifsorted(a) == 1 && b->size == 0)
		return ;
	while (a->sub[a->i] > 5 && ft_checkifsorted(a) == 0)
	{
		handle_pile_a(a, b);
		if (a->sub[a->i] > 5 && ft_checkifsorted(a) == 1)
		{
			b->i++;
			b->sub[b->i] = 0;
		}
	}
	if (a->sub[a->i] <= 5 && a->sub[a->i] > 0)
		ft_fiveunder_a(a, b);
	if (b->sub[b->i] <= 5 && b->sub[b->i] > 0)
		ft_fiveunder_b(a, b);
	else
	{
		printf("plop\n");
		handle_pile_b(a, b);
	}
	if (ft_checkifallsorted(a) == 1
			&& ft_checkifallreversesorted(b) == 1)
	{

		i = 0;
		printf("endA :");
		while (i < a->size)
			printf("%d ", a->pile[i++]);
		i = 0;
		printf("\nendB : ");
		while (i < b->size)
			printf("%d ", b->pile[i++]);
		printf("\n");

		while (b->size > 0)
			ft_pa(a, b);
		return ;
	}

	i = 0;
	printf("bqA %d - size %d :", a->i, a->sub[a->i]);
	while (i < a->size)
		printf("%d ", a->pile[i++]);
	i = 0;
	printf("\nbqB %d - size %d : ", b->i, b->sub[b->i]);
	while (i < b->size)
		printf("%d ", b->pile[i++]);
	printf("\n");
	while (a->i < 3)
	ft_quick_sort(a, b);
}
