/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:23:47 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/27 15:58:04 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pile	a;
	t_pile	b;
	char	**tab[(ac-1)];
	int	i;
	
	i = 0;
	if (ft_init(&a, (ac - 1)) < 0 || ft_init(&b, (ac - 1)) < 0)
		ft_error(&a, &b);
	if (ac < 2)
		ft_error(&a, &b);
	while (i < (ac - 1))
	{
		tab[i] = ft_split(av[(i + 1)], " ");
		i++;
	}
	if (ft_buildpile(&a, i, tab) < 0)
		ft_error(&a, &b);
	if (ft_checkdouble(&a) == 1)
	{
		printf("plop\n");
		ft_error(&a, &b);
	}
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
	while (i < (a->size - 1))
	{
		j = i + 1;
		while (j < a->size)
		{
			printf("i %d j %d\n", a->pile[i], a->pile[j]);
			if (a->pile[i] == a->pile[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
