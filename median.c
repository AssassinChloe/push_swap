/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:15:40 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/16 19:07:35 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_findmed(t_pile *the)
{
	int	i;
	int	ignore[5];
	int	med[3];
	int	j;
		
	i = 0;
	j = 0;
	while (i < 5)
		ignore[i++] = 0;
	i = 0;
	while (i < the->sub[the->i])
	{
		if (ft_issmallest(the, the->pile[i]) == 1 || ft_isbigest(the, the->pile[i]) == 1)
			ignore[i] = 1;
		i++;
	}
	i = 0;
	while (i < the->sub[the->i])
	{
		if (ignore[i] == 0)
			med[j++] = ignore[i];
		i++;
	}
	if ((med[0] > med[1] && med[0] < med[2]) || (med[0] < med[1] && med[0] > med[2]))
		return (med[0]);
	else if ((med[0] < med[1] && med[1] < med[2]) || (med[0] > med[1] && med[1] > med[2]))
		return (med[1]);
	else
		return (med[2]);
}
