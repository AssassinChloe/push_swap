/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:25:15 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/05 17:28:07 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pilecopy(t_pile *the, int **tab)
{
	int	i;

	i = 0;
	while (i < the->size)
	{
		(*tab)[i] = the->pile[i];
		i++;
	}
}

int	ft_addonetop(t_pile *the, int add)
{
	int	*tab;
	int	i;
	int	j;
	
	printf("add : %d\n", add);
	tab = malloc(sizeof(int) * the->size);
	if (!tab)
		return (-1);
	if (the->size > 0)
	{
		ft_pilecopy(the, &tab);
		free(the->pile);
	}
	else
		tab[0] = add;
	the->size++;
	the->pile = malloc(sizeof(int) * the->size);
	if (!the->pile)
		return (-1);
	i = 1;
	j = 0;
	the->pile[0] = add;
	while (j < the->size)
		the->pile[i++] = tab[j++];
	free(tab);
	tab = NULL;
	return (0);
}

int	ft_freepile(t_pile *the)
{
	free(the->pile);
	the->pile = NULL;
	the->size = 0;
	return (0);
}

int	ft_removeonetop(t_pile *the)
{
	int	*tab;
	int	i;
	int	j;

	if (the->size == 1)
		return (ft_freepile(the));
	i = 0;
	j = 1;
	tab = malloc(sizeof(int) * the->size);
	if (!tab)
		return (-1);
	ft_pilecopy(the, &tab);
	free(the->pile);
	the->size--;
	the->pile = malloc(sizeof(int) * (the->size));
	if (!the->pile)
		return (-1);
	while (i < the->size)
		the->pile[i++] = tab[j++];
	free(tab);
	tab = NULL;
	return (0);
}
