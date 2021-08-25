/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:25:05 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/25 15:43:05 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_pile *a)
{
	ft_swap_two(a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_pile *b)
{
	ft_swap_two(b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_pile *a, t_pile *b)
{
	ft_swap_two(a);
	ft_swap_two(b);
	write(1, "ss\n", 3);
}

void	ft_swap_two(t_pile *the)
{
	int	 swp;

	swp = the->pile[0];
	the->pile[0] = the->pile[1];
	the->pile[1] = swp;
}
