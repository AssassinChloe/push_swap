/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:06:38 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/27 15:54:14 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || ft_isdigit(str[i]) == 1)
			i++;
		else
			return (-1);
	}
	return (1);
}

int	ft_buildpile(t_pile *a, int size, char ***tab)
{
	int			i;
	int			len;
	int			j;
	long long	ret;

	i = 0;
	while (i < size)
	{
		len = 0;
		j = 0;
		while (tab[i][len] != NULL)
			len++;
		while (j < len)
		{
			if (ft_isnb(tab[i][j]) > 0)
			{
				ret = ft_atoll(tab[i][j]);
				if (ret < INT_MIN || ret > INT_MAX)
					return (-1);
				a->pile[a->size] = ret;
				a->size++;
				a->sub[a->i]++;
				j++;
			}
			else
				return (-1);
		}
		i++;
	}
	ft_free_tab(tab, size);
	printf("%d\n", a->size);
	return (0);
}
