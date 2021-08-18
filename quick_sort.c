/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:48:31 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/18 13:54:33 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issmallest(t_pile *the, int pivot)
{
	int i;
	int j;

	i = 0;
	j = the->sub[the->i] - 1;
	while (i < the->sub[the->i])
	{
		if (the->ignore[i] == 1)
			i++;
		else if (pivot > the->pile[j - i])
			return (0);
		else
			i++;
	}
	return (1);
}

int	ft_isbigest(t_pile *the, int pivot)
{
	int i;
	int j;

	i = 0;
	j = the->sub[the->i] - 1;
	while (i < the->sub[the->i])
	{
		if (the->ignore[i] == 1)
			i++;
		else if (pivot < the->pile[j - i])
			return (0);
		else
			i++;
	}
	return (1);
}
