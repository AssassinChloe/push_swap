/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_qs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 15:18:01 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/21 00:35:51 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fiveunder_a(t_pile *a, t_pile *b)
{
	if (a->sub[a->i] == 2 && ft_checkifsorted(a) == 0)
		ft_sa(a);
	else if (a->sub[a->i] == 3 && ft_checkifsorted(a) == 0)
		ft_sort3sub_a(a);
	else if (a->sub[a->i] > 3 && ft_checkifsorted(a) == 0)
		ft_sort5_a(a, b);
	a->i++;
	a->sub[a->i] = 0;
}

void	ft_fiveunder_b(t_pile *a, t_pile *b)
{
	if (b->sub[b->i] == 2 && ft_checkifreversesorted(b) == 0)
		ft_sb(b);
	else if (b->sub[b->i] == 3 && ft_checkifreversesorted(b) == 0)
		ft_sort3sub_b(b);
	else if (b->sub[b->i] > 3 && ft_checkifreversesorted(b) == 0)
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

void	ft_divide_a(t_pile *a, t_pile *b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (a->pile[0] < a->pivot)
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
			if (a->sub[a->i] > 1 && ft_anypbleft(a) == 1)
			{
				ft_ra(a);
				a->rot++;
			}
		}
		i++;
	}
}

void	ft_divide_b(t_pile *a, t_pile *b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (b->pile[0] > b->pivot)
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
			if (b->sub[b->i] > 1 && ft_anypaleft(b) == 1)
			{
				ft_rb(b);
				b->rot++;
			}
		}
		i++;
	}
}
