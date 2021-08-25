/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:24:02 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/25 15:40:58 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_pile *a)
{
	ft_toptobot(a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_pile *b)
{
	ft_toptobot(b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_pile *a, t_pile *b)
{
	ft_toptobot(a);
	ft_toptobot(b);
	write(1, "rr\n", 3);
}

void	ft_toptobot(t_pile *the)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	j = 1;
	tmp = the->pile[i];
	while (j < the->size)
	{
		the->pile[i] = the->pile[j];
		i++;
		j++;
	}
	the->pile[i] = tmp;
}
