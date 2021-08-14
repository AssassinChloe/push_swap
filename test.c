#include "push_swap.h"

void ft_sort5_b(t_pile *a, t_pile *b)
{
	int i;
	int pivot;
	int rotation;
	int	size;

	rotation = 0;
	size = b->sub[b->i];
	if (b->sub[b->i] == 4)
	{
		i = 1;
		while (i < 4 && ft_isbigest(b, b->sub[b->i], b->pile[b->sub[b->i - i]]) == 0)
			i++;
	}
	else
	{
		i = 1;
		while (i < 3 && (ft_isbigest(b, b->sub[b->i], b->pile[b->sub[b->i] - i]) == 1 || ft_issmallest(b, b->sub[b->i], b->pile[b->sub[b->i] - i]) == 1))
		i++;
	}
	pivot = b->pile[b->sub[b->i] - i];
	i = 0;
	while (i < size || a->sub[a->i])
	{
		if (b->pile[0] >= pivot)
		{
			ft_pa(a, b);
			b->sub[b->i]--;
			a->sub[a->i]++;
		}
		else
		{
			if (b->sub[b->i] > 1)
			{
				ft_rb(b);
				rotation++;
			}
		}
		i++;
	}
	while (b->i > 0 && rotation > 0)
	{
		ft_rrb(b);
		rotation--;
	}
	ft_sort3sub_a(a);
	ft_sort3sub_b(b);
	while (a->sub[a->i] > 0)
	{
		ft_pb(a, b);
		b->sub[b->i]++;
		a->sub[a->i]--;
	}
}

void ft_newsort5(t_pile *a, t_pile *b)
{
	int i;
	int pivot;
	int rotation;
	int size;
	
	i = 0;
	rotation = 0;
	size = a->sub[a->i];
	if (a->sub[a->i] == 4)
	{
		i = 1;
		while (ft_issmallest(a, a->sub[a->i], a->pile[a->sub[a->i] - i]) == 0)
			i++;
	}
	else
	{
		i = 1;
		while (ft_isbigest(a, a->sub[a->i], a->pile[a->sub[a->i] - i]) == 1 || ft_issmallest(a, a->sub[a->i], a->pile[a->sub[a->i] - i]) == 1)
		i++;
	}
	pivot = a->pile[a->sub[a->i] - i];
	i = 0;
	while (i < size || b->sub[b->i] < 3)
	{
		if (a->pile[0] <= pivot)
		{
			ft_pb(a, b);
			b->sub[b->i]++;
			a->sub[a->i]--;
		}
		else
		{
			if (a->sub[a->i] > 1)
			{
				ft_ra(a);
				rotation++;
			}
		}
		i++;
	}
	while (a->i > 0 && rotation > 0)
	{
		ft_rra(a);
		rotation--;
	}
	ft_sort3sub_a(a);
	ft_sort3sub_b(b);
	while (b->sub[b->i] > 0)
	{
		ft_pa(a, b);
		b->sub[b->i]--;
		a->sub[a->i]++;
	}
}

void init_quick_sort(t_pile *a, t_pile *b)
{
	int pivot;
	int i;

	i = 0;
	pivot = a->pile[(a->size - 1)];
	if (ft_isbigest(a, a->size, pivot) == 1)
		pivot = a->pile[a->size - 2];
	a->sub[0] = a->size;
	while (i < a->sub[0])
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
	a->sub[0] = a->size;
	b->sub[0] = b->size;
	b->i = 1;
	b->sub[1] = 0;
	ft_quick_sort(a, b);
}

void	ft_quick_sort(t_pile *a, t_pile *b)
{
	int size_init;
	int i;
	int pivot;
	int rotation;

	while (a->sub[a->i] > 5 && ft_checkifsorted(a) == 0)
	{
		i = 0;
		rotation = 0;
		pivot = a->pile[(a->sub[a->i] - 1)];
		if (ft_isbigest(a, a->sub[a->i], pivot) == 1)
			pivot = a->pile[a->sub[a->i] - 2];
		size_init = a->sub[a->i];
		while (i < size_init)
		{
			if (a->pile[0] <= pivot)
			{
				if (ft_pb(a, b) < 0)
				{
					printf("error pb\n");
					return ;
				}
				b->sub[b->i]++;
				a->sub[a->i]--;
			}
			else
			{
				if (a->sub[a->i] > 1)
				{
					ft_ra(a);
					rotation++;
				}
			}
			i++;
		}
		while (a->i > 0 && rotation > 0)
		{
			ft_rra(a);
			rotation--;
		}
		if (a->sub[a->i] > 5)
		{
			b->i++;
			b->sub[b->i] = 0;
		}
	}
	if (a->sub[a->i] <= 5)
	{
		if (a->sub[a->i] == 2 && ft_checkifsorted(a) == 0)
			ft_sa(a);
		else if (a->sub[a->i] == 3 && ft_checkifsorted(a) == 0)
			ft_sort3sub_b(b);
		else if(a->sub[a->i] > 3 && ft_checkifsorted(a) == 0)
			ft_newsort5(a, b);
		a->i++;
		a->sub[a->i] = 0;
	}	
	if (b->sub[b->i] <= 5)
	{
		if (b->sub[b->i] == 2 && ft_checkifreversesorted(b) == 0)
			ft_sb(b);
		else if (b->sub[b->i] == 3 && ft_checkifreversesorted(b) == 0)
			ft_sort3sub_b(a);
		else if(b->sub[b->i] > 3 && ft_checkifreversesorted(b) == 0)
			ft_sort5_b(a, b);
		while (b->sub[b->i] > 0)
		{
			ft_pa(a, b);
			a->sub[a->i]++;
			b->sub[b->i]--;
		}
		b->i--;
		if (b->i < 0)
		b->i = 0;
	}
	else
	{
		i = 0;
		size_init = a->sub[b->i];
		rotation = 0;
		pivot = b->pile[(b->sub[b->i] - 1)];
		if (ft_issmallest(b, b->sub[b->i], pivot) == 1)
			pivot = b->pile[b->sub[b->i] - 2];
		while (i < size_init)
		{
			if (b->pile[0] <= pivot)
			{
				if (ft_pa(a, b) < 0)
				{
					printf("error pa\n");
					return ;
				}
				a->sub[a->i]++;
				b->sub[b->i]--;
			}
			else
			{
				if (b->sub[b->i] > 1)
				{
					ft_rb(b);
					rotation++;
				}
			}
			i++;
		}
		while (b->i > 0 && rotation > 0)
		{
			ft_rrb(b);
			rotation--;
		}
	}
	if (ft_checkifsorted(a) == 1 && ft_checkifreversesorted(b) == 1)
	{
		while (b->size > 0)
			ft_pa(a, b);	
		return ;
	}
		/*
		i = 0;
		while (i < a->size)
			printf("%d", a->pile[i++]);
		printf("\n");
		i = 0;
		while (i < b->size)
			printf("%d ", b->pile[i++]);
		printf("\n");
		*/
	ft_quick_sort(a, b);
}
