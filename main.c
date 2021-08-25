/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:23:47 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/25 16:40:16 by cassassi         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_pile	a;
	t_pile	b;

	if (ft_init(&a, (ac - 1)) < 0 || ft_init(&b, (ac - 1)) < 0)
		ft_error(&a, &b);
	if (ac <= 2)
		ft_error(&a, &b);
	if (ft_buildpile(&a, ac, av) < 0 )
		ft_error(&a, &b);
	if (ft_checkdouble(&a) == 1)
		ft_error(&a, &b);
	if (ft_checkifallsorted(&a) == 1)
		ft_free(&a, &b);
	ft_sort(&a, &b);
	return (0);
}

int	ft_init(t_pile *the, int size)
{
	the->i = 0;
	the->size = 0;
	the->pile = malloc(sizeof(int) * size);
	if (!the->pile)
		return (-1);
	the->sub = malloc(sizeof(int) * size);
	if (!the->sub)
		return (-1);
	the->sub[the->i] = 0;
	the->ignore = malloc(sizeof(int) * size);
	if (!the->ignore)
		return (-1);
	return (0);
}

int	ft_checkdouble(t_pile *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size - 1)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->pile[i] == a->pile[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
