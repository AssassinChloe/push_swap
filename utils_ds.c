/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:39:16 by cassassi          #+#    #+#             */
/*   Updated: 2021/09/09 16:40:03 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_acton_a(t_pile *a, int *tab[2], int *i)
{
	if (tab[0][*i] == 2)
		ft_sa(a);
	else if (tab[0][*i] == 3)
		ft_ra(a);
	else
		ft_rra(a);
	(*i)++;
}

void	ft_acton_b(t_pile *b, int *tab[2], int *j)
{
	if (tab[1][*j] == 2)
		ft_sb(b);
	else if (tab[1][*j] == 3)
		ft_rb(b);
	else
		ft_rrb(b);
	(*j)++;
}
