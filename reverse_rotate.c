/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:24:56 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/25 15:42:11 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_pile *a)
{
	ft_bottotop(a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_pile *b)
{
	ft_bottotop(b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_pile *a, t_pile *b)
{
	ft_bottotop(a);
	ft_bottotop(b);
	write(1, "rrr\n", 4);
}

void	ft_bottotop(t_pile *the)
{
	int	tmp;
	int	i;
	int	j;

	i = the->size - 2;
	j = the->size - 1;
	tmp = the->pile[j];
	while (i >= 0)
	{
		the->pile[j] = the->pile[i];
		i--;
		j--;
	}
	the->pile[j] = tmp;
}
