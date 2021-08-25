/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:24:17 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/25 15:40:03 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_pile *a, t_pile *b)
{
	if (ft_addonetop(a, b->pile[0]) < 0)
		ft_error(a, b);
	if (ft_removeonetop(b) < 0)
		ft_error(a, b);
	write(1, "pa\n", 3);
}

void	ft_pb(t_pile *a, t_pile *b)
{
	if (ft_addonetop(b, a->pile[0]) < 0)
		ft_error(a, b);
	if (ft_removeonetop(a) < 0)
		ft_error(a, b);
	write(1, "pb\n", 3);
}

int	ft_anypaleft(t_pile *b)
{
	int	i;

	i = 0;
	while (i < b->sub[b->i])
	{
		if (b->pile[i] >= b->pivot)
			return (1);
		i++;
	}
	return (0);
}

int	ft_anypbleft(t_pile *a)
{
	int	i;

	i = 0;
	while (i < a->sub[a->i])
	{
		if (a->pile[i] <= a->pivot)
			return (1);
		i++;
	}
	return (0);
}
