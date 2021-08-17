/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:23:47 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/17 15:04:37 by cassassi         ###   ########.fr       */
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
	int		j;
	t_pile	a;

	i = 1;
	j = 0;
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
				a.pile[j] = ft_atoll(av[i]);
				if (a.pile[j] < INT_MIN || a.pile[j] > INT_MAX)
				{
					printf("Error overflow\n");
					return (0);
				}
				j++;
				i++;
			}
			else
			{
				printf("Error not nb\n");
				return (0);
			}
		}
		a.size = j;
		a.i = 0;
		a.sub = malloc(sizeof(int) * a.size);
		a.sub[a.i] = a.size;
	}
	if (ft_checkdouble(&a) == 1)
	{
		printf("Error double\n");
		return (0);
	}
	if (ft_checkifsorted(&a) == 1)
		return (0);
	ft_sort(&a);
	return (0);
}

void	ft_free(t_pile *a, t_pile *b)
{
	if (a->pile)
		free(a->pile);
	if (a->sub)
		free(a->sub);
	if (b->sub)
		free(b->sub);
	if (b->pile)
		free(b->pile);
	if (a->ignore)
		free(a->ignore);
	if (b->ignore)
		free(b->ignore);
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
