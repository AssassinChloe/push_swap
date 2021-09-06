/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:16:41 by cassassi          #+#    #+#             */
/*   Updated: 2021/09/06 12:27:07 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_free_tab(char ***tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		if (tab[i] != NULL)
		{
			while (tab[i][j] != NULL)
			{
				free(tab[i][j]);
				tab[i][j] = NULL;
				j++;
			}
			free(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	free(tab);
	tab = NULL;
}

int	ft_free(t_pile *a, t_pile *b)
{
	ft_endfree(a);
	ft_endfree(b);
	exit(EXIT_SUCCESS);
}

int	ft_error(t_pile *a, t_pile *b)
{
	write(2, "Error\n", 6);
	ft_endfree(a);
	ft_endfree(b);
	exit(EXIT_FAILURE);
}

void	ft_endfree(t_pile *the)
{
	if (the->pile != NULL)
	{
		free(the->pile);
		the->pile = NULL;
	}
	if (the->sub != NULL)
	{
		free(the->sub);
		the->sub = NULL;
	}
	if (the->ignore != NULL)
	{
		free(the->ignore);
		the->ignore = NULL;
	}
}
