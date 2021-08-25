/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:06:38 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/25 16:41:21 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_buildpile(t_pile *a, int size, char **av)
{
	int			i;
	long long	ret;

	i = 1;
	while (i < size)
	{
		if (ft_isnb(av[i]) > 0)
		{
			ret = ft_atoll(av[i]);
			if (ret < INT_MIN || ret > INT_MAX)
				return (-1);
			a->pile[a->size] = ret;
			a->size++;
			a->sub[a->i]++;
			i++;
		}
		else
			return (-1);
	}
	return (0);
}
