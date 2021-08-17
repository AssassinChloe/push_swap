/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:16:40 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/17 15:13:20 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkifsorted(t_pile *a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < a->sub[a->i])
	{
		if (a->pile[i] > a->pile[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	ft_checkifreversesorted(t_pile *b)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < b->sub[b->i])
	{
		if (b->pile[i] < b->pile[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}
