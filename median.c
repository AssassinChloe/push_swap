/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:15:40 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/24 10:55:40 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_findmed(t_pile *the, int *small, int *big, int *count)
{
	int	i;

	i = 1;
	while (i <= the->sub[the->i] && (*count) > 1)
	{
		if (the->ignore[i - 1] == 0 && (*small) >= 0
			&& ft_small(the, the->pile[the->sub[the->i] - i]) == 1)
		{
			the->ignore[(i - 1)] = 1;
			(*count)--;
			(*small)--;
		}
		if (the->ignore[i - 1] == 0 && (*big) >= 0
			&& ft_big(the, the->pile[the->sub[the->i] - i]) == 1)
		{
			the->ignore[(i - 1)] = 1;
			(*count)--;
			(*big)--;
		}
		i++;
	}
}

void	ft_findmedstack(t_pile *the)
{
	int	i;
	int	j;
	int	small;
	int	count;
	int	big;

	printf("med %d i %d\n", the->sub[the->i], the->i);	
	count = the->sub[the->i];
	big = (the->sub[the->i] / 2) - 1;
	small = (the->sub[the->i] / 2) - 1;
	ft_ignorezero(the);
	if ((the->sub[the->i] % 2) == 0)
		j = (the->sub[the->i] / 2) - 1;
	else
		j = the->sub[the->i] / 2;
	while (j > 0)
	{
		ft_findmed(the, &small, &big, &count);
		j--;
	}
	i = 0;
	while (the->ignore[i] == 1)
		i++;
	ft_ignorezero(the);
	the->pivot = the->pile[the->sub[the->i] - (i + 1)];
	printf("pivot %d\n", the->pivot);
}

void	ft_ignorezero(t_pile *the)
{
	int	i;

	i = 0;
	while (i < the->size)
		the->ignore[i++] = 0;
}

int	ft_small(t_pile *the, int pivot)
{
	int	i;
	int	j;

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

int	ft_big(t_pile *the, int pivot)
{
	int	i;
	int	j;

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
