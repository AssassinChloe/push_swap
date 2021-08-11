/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:48:31 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/06 16:44:52 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issmallest(t_pile *the, int size, int pivot)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (pivot > the->pile[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_isbigest(t_pile *the, int size, int pivot)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (pivot < the->pile[i])
			return (0);
		i++;
	}
	return (1);
}
