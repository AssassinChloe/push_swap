/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:23:08 by cassassi          #+#    #+#             */
/*   Updated: 2021/09/07 07:54:33 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_pile *a, t_pile *b)
{
	if (a->size == 2)
		ft_sa(a);
	else if (a->size == 3)
		ft_sort_3(a);
	else if (a->size > 3 && a->size <= 5)
	{
		ft_sort5_a(a, b);
		while (b->sub[b->i] > 0)
		{
			ft_pa(a, b);
			b->sub[b->i]--;
			a->sub[a->i]++;
		}
		b->i--;
	}
	else
		init_quick_sort(a, b);
	/*int i = 0;
	while (i < a->size)
		printf("%d ", a->pile[i++]);
	printf("\n");*/
	ft_free(a, b);
	return ;
}
