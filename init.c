/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:58:07 by cassassi          #+#    #+#             */
/*   Updated: 2021/09/06 16:13:30 by cassassi         ###   ########.fr       */
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

void	ft_check_arg(int ac, char **av)
{
	int		i;

	if (ac == 1)
		ft_quit();
	i = 1;
	while (i < ac)
	{
		if (ft_isnb(av[i++]) < 0)
			ft_quit();
	}
}

void	ft_check_pile(t_pile *a, t_pile *b, char ***tab, int i)
{
	int	size;

	size = ft_count(tab, i);
	if (ft_init(a, size) < 0 || ft_init(b, size) < 0)
	{
		ft_free_tab(tab, i);
		ft_error(a, b);
	}
	if (ft_buildpile(a, i, tab) < 0)
	{
		ft_free_tab(tab, i);
		ft_error(a, b);
	}
	if (ft_checkdouble(a) == 1)
		ft_error(a, b);
	if (ft_checkifallsorted(a) == 1)
		ft_free(a, b);
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
