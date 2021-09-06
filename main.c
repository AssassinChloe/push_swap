/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:23:47 by cassassi          #+#    #+#             */
/*   Updated: 2021/09/06 16:10:01 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pile	a;
	t_pile	b;
	char	***tab;
	int		i;

	ft_check_arg(ac, av);
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
	ft_check_pile(&a, &b, tab, i);
	ft_sort(&a, &b);
	return (0);
}
