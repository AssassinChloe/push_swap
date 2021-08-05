/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:23:08 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/05 17:32:32 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort(t_pile *a, t_pile *b)
{
	int	pivot;
	int	size_init;
	int	i;

	if (b->size > 1 && ft_checkifreversesorted(b) == 0)
	{
		printf("yoh B\n");
		i = 0;
		size_init = b->size;
		printf("yoh sizeB %d\n", size_init);
		pivot = b->pile[b->size - 1];
		printf("yoh pivotB %d\n", pivot);
		while (i < size_init)
		{
			if (b->pile[0] >= pivot)
			{
		printf("yoh Bpile0 %d\n", b->pile[0]);
				if (ft_pa(a, b) < 0)
				{
					printf("error pa\n");
					return ;
				}
			}
			else
				ft_rb(b);
			i++;
		printf("yoh iB %d\n", i);
		}
	}
	else if (a->size > 1 && ft_checkifsorted(a) == 0)
	{
		printf("yoh A\n");
		i = 0;
		size_init = a->size;
		pivot = a->pile[a->size - 1];
		while (i < size_init)
		{
			if (a->pile[0] <= pivot)
				ft_pb(a, b);
			else
				ft_ra(a);
			i++;
		}
	}
	else
	{
		printf("yoh else\n");
		return ;
	}
	printf("\nA : ");
	i = 0;
	while (i < a->size)
		printf("%d ", a->pile[i++]);
	i = 0;
	printf("\nB : ");
	while (i < b->size)
		printf("%d ", b->pile[i++]);
	printf("\n");
	ft_quick_sort(a, b);
}

void	ft_sort_3(t_pile *a)
{
	if (a->pile[0] > a->pile[1] && a->pile[0] < a->pile[2]
		&& a->pile[1] < a->pile[2])
		ft_sa(a);
	else if (a->pile[0] > a->pile[1] && a->pile[0] > a->pile[2]
		&& a->pile[1] > a->pile[2])
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (a->pile[0] > a->pile[1] && a->pile[0] > a->pile[2]
		&& a->pile[1] < a->pile[2])
		ft_ra(a);
	else if (a->pile[0] < a->pile[1] && a->pile[0] < a->pile[2]
		&& a->pile[1] > a->pile[2])
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (a->pile[0] < a->pile[1] && a->pile[0] > a->pile[2]
		&& a->pile[1] > a->pile[2])
		ft_rra(a);
	return ;
}

void	ft_sort_5(t_pile *a)
{
	if (a->size_max == 4)
		printf("plop\n");
	else
		printf("plop\n");
}

void	ft_sort(t_pile *a)
{
	t_pile	b;

	b.pile = NULL;
	b.size = 0;
	b.size_max = a->size_max;
	if (a->size_max == 2)
	{
		ft_sa(a);
		return ;
	}
	else if (a->size_max == 3)
		ft_sort_3(a);
	//    else if (a->size_max > 3 && a->size_max <= 5)
	//       ft_sort_5(a);
	else
		ft_quick_sort(a, &b);
	return ;
}
