/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:23:47 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/19 15:17:02 by cassassi         ###   ########.fr       */
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
	int		i;
	t_pile	a;
	t_pile	b;

	i = 1;
	a.size = 0;
	if (ac < 3)
	{
		printf("Error nb argument\n");
		return (0);
	}
	else
	{
		a.pile = malloc(sizeof(int) * (ac - 1));
		if (!(a.pile))
			return (printf("error malloc\n"));
		while (i < ac)
		{
			if (ft_isnb(av[i]) > 0)
			{
				a.pile[a.size] = ft_atoll(av[i]);
				if (a.pile[a.size] < INT_MIN || a.pile[a.size] > INT_MAX)
				{
					printf("Error overflow\n");
					free(a.pile);
					return (0);
				}
				a.size++;
				i++;
			}
			else
			{
				printf("Error not nb\n");
				free(a.pile);
				return (0);
			}
		}
		if (ft_checkdouble(&a) == 1)
		{
			printf("Error double\n");
			free(a.pile);
			return (0);
		}
		if (ft_checkifallsorted(&a) == 1)
		{
			free(a.pile);
			return (0);
		}
	}
	if (ft_init(&a, &b) < 0)
	{
		printf("Error\n");
		ft_free(&a, &b);
	}
	ft_sort(&a, &b);
	return (0);
}

int	ft_init(t_pile *a, t_pile *b)
{
	a->i = 0;
	a->sub = malloc(sizeof(int) * a->size);
	if (!a->sub)
		return (-1)
	a->sub[a->i] = a->size;
	b->pile = malloc(sizeof(int) * a->size);
	if (!b->pile)
		return (-1);
	b->size = 0;
	b->sub = malloc(sizeof(int) * a->size);
	if (!b->sub)
		return (-1);
	b->i = 0;
	b->sub[b->i] = 0;
	a->ignore = malloc(sizeof(int) * a->size);
	if (!a->ignore)
		return (-1);
	ft_ignorezero(a);
	b->ignore = malloc(sizeof(int) * a->size);
	if (!b->ignore)
		return (-1);
	ft_ignorezero(b);
	return (0);
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
