/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:15:40 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/18 14:36:41 by cassassi         ###   ########.fr       */
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
	
	count = the->sub[the->i];
	if ((the->sub[the->i] % 2) == 0)
		j = (the->sub[the->i] / 2) - 1;
	else
		j = the->sub[the->i] / 2;
	while (j > 0)
	{
		i = 1;
		while (i <= the->sub[the->i] && count > 2)
		{
			if (the->ignore[i - 1] == 0 && (ft_issmallest(the, the->pile[the->sub[the->i] - i]) == 1 || ft_isbigest(the, the->pile[the->sub[the->i] - i]) == 1))
			{
				the->ignore[(i - 1)] = 1;
				count --;
			}
			i++;
		}
		j--;
	}
	i = 0;
	while (the->ignore[i] == 1)
		i++;
	ft_ignorezero(the);
	printf("pivot %d\n", the->pile[the->sub[the->i] - (i + 1)]);
	return (the->pile[the->sub[the->i] - (i + 1)]);
}

int	ft_findmed(t_pile *the)
{
	int	i;
	int	ignore[5];
	int	med[3];
	int	j;

	i = 0;
	j = 0;
	while (i < 5)
		ignore[i++] = 0;
	i = 1;
	while (i <= 5)
	{
		if (ft_issmallest(the, the->pile[the->sub[the->i] - i]) == 1 || ft_isbigest(the, the->pile[the->sub[the->i] - i]) == 1)
			ignore[(i - 1)] = 1;
		i++;
	}
	i = 1;
	while (i <= 5)
	{
		if (ignore[(i - 1)] == 0)
			med[j++] = the->pile[the->sub[the->i] - i];
		i++;
	}
	if ((med[0] > med[1] && med[0] < med[2]) || (med[0] < med[1] && med[0] > med[2]))
		return (med[0]);
	else if ((med[0] < med[1] && med[1] < med[2]) || (med[0] > med[1] && med[1] > med[2]))
		return (med[1]);
	else
		return (med[2]);
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

