/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:23:47 by cassassi          #+#    #+#             */
/*   Updated: 2021/09/06 12:27:45 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count(char ***tab, int len)
{
	int	i;
	int	j;
	int	size;

	size = 0;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (tab[i][j])
		{
			j++;
			size++;
		}
		i++;
	}
	return (size);
}

int	main(int ac, char **av)
{
	t_pile	a;
	t_pile	b;
	char	***tab;
	int		i;
	int		size;

	if (ac == 1)
		ft_quit();
	i = 1;
	while (i < ac)
	{
		if (ft_isnb(av[i++]) < 0)
			ft_quit();
	}
	tab = malloc(sizeof(char **) * ac - 1);
	if (!tab)
		ft_quit();
	i = 0;
	while (i < (ac - 1))
	{
		tab[i] = ft_split(av[(i + 1)], " ");
		if (tab[i][0] == NULL)
		{
			ft_free_tab(tab, i);
			ft_quit();
		}
		i++;
	}
	size = ft_count(tab, i);
	if (ft_init(&a, size) < 0 || ft_init(&b, size) < 0)
		ft_error(&a, &b);
	if (ft_buildpile(&a, i, tab) < 0)
	{
		ft_free_tab(tab, i);
		ft_error(&a, &b);
	}
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
	while (i < (a->size - 1))
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
