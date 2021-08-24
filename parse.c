/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:06:38 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/24 17:07:15 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_buildpile(t_pile *a, int size, char **av)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (ft_isnb(av[i]) > 0)
		{
			a->pile[a->size] = ft_atoll(av[i]);
			if (a->pile[a->size] < INT_MIN || a->pile[a->size] > INT_MAX)
			{
				write(2, "Error\n", 6);
				return (-1);
			}
			a->size++;
			a->sub[a->i]++;
			i++;
		}
		else
		{
			write(2, ("Error\n"), 6);
			return (-1);
		}
	}
	return (0);
}
