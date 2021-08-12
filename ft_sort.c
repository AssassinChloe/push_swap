/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:23:08 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/11 23:43:38 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_quick_sort(t_pile *a, t_pile *b)
  {
  int	pivot;
  int	size_init;
  int	i;

  if (b->size > 1 && ft_checkifreversesorted(b) == 0)
  {
  i = 0;
  while (ft_issmallest(b, b->pile[b->size - 1]) == 1)
  {
  ft_rrb(b);
  ft_pa(a, b);
  }
  size_init = b->size;
  pivot = b->pile[(b->size - 1)];
  while (i < size_init)
  {
  if (b->pile[0] >= pivot)
  {
  if (ft_pa(a, b) < 0)
  {
  printf("error pa\n");
  return ;
  }
  }
  else
  ft_rb(b);
  i++;
  }
  }
  else if (a->size > 1 && ft_checkifsorted(a) == 0)
  {
  i = 0;
  while (ft_isbigest(a, a->pile[a->size - 1]) == 1)
  {
  ft_rra(a);
  ft_pb(a, b);
  }
  size_init = a->size;
  pivot = a->pile[(a->size - 1)];
  while (i < size_init)
  {
  if (a->pile[0] <= pivot)
  {
  if (ft_pb(a, b) < 0)
  {
  printf("error pb\n");
  return ;
  }
  }
  else
  ft_ra(a);
  i++;
  }
  }
  else
  {
  while (b->size > 0)
  ft_pa(a, b);	
  free(b->pile);
  printf("\nA : ");
  i = 0;
  while (i < a->size)
  printf("%d ", a->pile[i++]);
  i = 0;
  printf("\nB : ");
  while (i < b->size)
  printf("%d ", b->pile[i++]);
  printf("\n");

free(a->pile);
return ;
}
printf("\nA : ");
i = 0;
while (i < a->size)
	printf("%d ", a->pile[i++]);
	i = 0;
	printf("\nB : ");
while (i < b->size)
	printf("%d ", b->pile[i++]);
	printf("\n");

	ft_quick_sort(a, b);
	}*/

void	ft_sort_3(t_pile *a)
{
	if (a->pile[0] > a->pile[1] && a->pile[0] < a->pile[2]
			&& a->pile[1] < a->pile[2])
		ft_sa(a);
	else if (a->pile[0] > a->pile[1] && a->pile[0] > a->pile[2]
			&& a->pile[1] > a->pile[2])
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (a->pile[0] > a->pile[1] && a->pile[0] > a->pile[2]
			&& a->pile[1] < a->pile[2])
		ft_ra(a);
	else if (a->pile[0] < a->pile[1] && a->pile[0] < a->pile[2]
			&& a->pile[1] > a->pile[2])
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (a->pile[0] < a->pile[1] && a->pile[0] > a->pile[2]
			&& a->pile[1] > a->pile[2])
		ft_rra(a);
	return ;
}

void	ft_sort_5(t_pile *a, t_pile *b)
{
	while (a->size > 3)
		ft_pb(a, b);
	ft_sort_3(a);
	while (b->size > 0)
	{
		ft_pa(a, b);
		if (ft_isbigest(a, a->size, a->pile[0]) == 1)
			ft_ra(a);
		else if (ft_issmallest(a, a->size, a->pile[0]) == 1 && b->size == 0)
			return ;
		else if (a->pile[0] > a->pile[1] && a->pile[0] < a->pile[2])
			ft_sa(a);
		else if (a->pile[0] < a->pile[a->size - 1] && a->pile[0] > a->pile[a->size - 2])
		{
			ft_rra(a);
			ft_sa(a);
			ft_ra(a);
			ft_ra(a);
		}
		else
		{
			ft_sa(a);
			ft_ra(a);
			ft_sa(a);
			ft_rra(a);
		}

	}
}

void	ft_sort(t_pile *a)
{
	t_pile	b;

	b.pile = NULL;
	b.size = 0;
	b.size_max = a->size_max;
	if (a->size_max == 2)
	{
		ft_sa(a);
		return ;
	}
	else if (a->size_max == 3)
		ft_sort_3(a);
	else if (a->size_max > 3 && a->size_max <= 5)
		ft_newsort5(a, &b);
	else
		init_quick_sort(a, &b);
	return ;
}
