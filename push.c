/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:24:17 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/05 16:49:36 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa(t_pile *a, t_pile *b)
{
	if (ft_addonetop(a, b->pile[0]) < 0)
		return (-1);
	if (ft_removeonetop(b) < 0)
		return (-1);
	printf("pa\n");
	return (0);
}

int	ft_pb(t_pile *a, t_pile *b)
{
	if (ft_addonetop(b, a->pile[0]) < 0)
		return (-1);
	if (ft_removeonetop(a) < 0)
		return (-1);
	printf("pb\n");
	return (0);
}
