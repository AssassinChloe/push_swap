/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:15:40 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/19 12:52:04 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ignorezero(t_pile *the)
{
	int i;

	i = 0;
	while (i < the->size)
		the->ignore[i++] = 0;
}

int	ft_findmedstack(t_pile *the)
{
	int	i;
	int	j;
	int	count;
	int	big;
	int	small;

//	printf("sub %d, i %d\n", the->sub[the->i], the->i);	
	count = the->sub[the->i];
	big = (the->sub[the->i] / 2) - 1;
	small = (the->sub[the->i] / 2) - 1;
	if ((the->sub[the->i] % 2) == 0)
		j = (the->sub[the->i] / 2) - 1;
	else
		j = the->sub[the->i] / 2;
	while (j > 0)
	{
		i = 1;
		while (i <= the->sub[the->i] && count > 1)
		{
			if (the->ignore[i - 1] == 0 && small >= 0 && ft_issmallest(the, the->pile[the->sub[the->i] - i]) == 1) 
			{
				the->ignore[(i - 1)] = 1;
				count--;
				small--;
			}
			if (the->ignore[i - 1] == 0 && big >= 0 && ft_isbigest(the, the->pile[the->sub[the->i] - i]) == 1)
			{
				the->ignore[(i - 1)] = 1;
				count--;
				big--;
			}
			i++;
		}
		j--;
	}
	i = 0;
	while (the->ignore[i] == 1)
		i++;
	ft_ignorezero(the);
//	printf("pivot %d\n", the->pile[the->sub[the->i] - (i + 1)]);
	return (the->pile[the->sub[the->i] - (i + 1)]);
}

int	ft_anypaleft(t_pile *b, int pivot)
{
	int i;

	i = 0;
	while (i < b->sub[b->i])
	{
		if (b->pile[i] > pivot)
			return (1);
		i++;
	}
	return (0);
}

int	ft_anypbleft(t_pile *a, int pivot)
{
	int i;

	i = 0;
	while (i < a->sub[a->i])
	{
		if (a->pile[i] < pivot)
			return (1);
		i++;
	}
	return (0);
}

