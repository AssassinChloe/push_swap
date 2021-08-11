#include "push_swap.h"

void init_quick_sort(t_pile *a, t_pile *b)
{
	int i;
	int j;
	int *sub_a;
	int *sub_b;
	int pivot;

	sub_a = malloc(sizeof(int) * (a->size_max));
	sub_b = malloc(sizeof(int) * (a->size_max));

	i = 0;
	pivot = a->pile[(a->size - 1)];
	sub_a[0] = a->size;
	while (i < sub_a[0])
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
	sub_a[0] = a->size;
	sub_b[0] = b->size;
	i = 1;
	j = 0;
	sub_a[1] = 0;
	ft_quick_sort(a, b, sub_a, sub_b, &i, &j);
}

void	ft_quick_sort(t_pile *a, t_pile *b, int *sub_a, int *sub_b, int *nb_a, int *nb_b)
{
	int size_init;
	int i;
	int pivot;
	int rotation;

	while (sub_b[*nb_b] > 3 && ft_checkifreversesorted(b) == 0)
	{
		i = 0;
		rotation = 0;
		pivot = b->pile[(sub_b[*nb_b] - 1)];
		if (ft_issmallest(b, sub_b[*nb_b], pivot) == 1)
			pivot = b->pile[sub_b[*nb_b] - 2];
		size_init = sub_b[*nb_b];
		while (i < size_init)
		{
			if (b->pile[0] >= pivot)
			{
				if (ft_pa(a, b) < 0)
				{
					printf("error pa\n");
					return ;
				}
				sub_a[*nb_a]++;
				sub_b[*nb_b]--;
			}
			else
			{
				if (sub_b[*nb_b] > 1)
				{
					ft_rb(b);
					rotation++;
				}
			}
			i++;
		}
		while (*nb_b > 0 && rotation > 0)
		{
			ft_rrb(b);
			rotation--;
		}
		if (sub_b[*nb_b] > 3)
		{
			*nb_a = *nb_a + 1;
			sub_a[*nb_a] = 0;
		}
	}
	if (sub_b[*nb_b] <= 3)
	{
		if (sub_b[*nb_b] == 2 && ft_checkifreversesorted(b) == 0)
			ft_sb(b);
		else if (sub_b[*nb_b] == 3 && ft_checkifreversesorted(b) == 0)
			ft_sort3sub_b(b);
		*nb_b = *nb_b + 1;
		sub_b[*nb_b] = 0;
	}
	if (sub_a[*nb_a] <= 3)
	{
		if (sub_a[*nb_a] == 2 && ft_checkifsorted(a) == 0)
			ft_sa(a);
		else if (sub_a[*nb_a] == 3 && ft_checkifsorted(a) == 0)
			ft_sort3sub_a(a);
		while (sub_a[*nb_a] > 0)
		{
			ft_pb(a, b);
			sub_b[*nb_b]++;
			sub_a[*nb_a]--;
		}
		*nb_a = *nb_a - 1;
		if (*nb_a < 0)
			*nb_a = 0;
	}
	else
	{
		i = 0;
		size_init = sub_a[*nb_a];
		rotation = 0;
		pivot = a->pile[(sub_a[*nb_a] - 1)];
		if (ft_isbigest(a, sub_a[*nb_a], pivot) == 1)
			pivot = a->pile[sub_a[*nb_a] - 2];
		while (i < size_init)
		{
			if (a->pile[0] <= pivot)
			{
				if (ft_pb(a, b) < 0)
				{
					printf("error pb\n");
					return ;
				}
				sub_b[*nb_b]++;
				sub_a[*nb_a]--;
			}
			else
			{
				if (sub_a[*nb_a] > 1)
				{
					ft_ra(a);
					rotation++;
				}
			}
			i++;
		}
		while (*nb_a > 0 && rotation > 0)
		{
			ft_rra(a);
			rotation--;
		}
	}
	if (ft_checkifsorted(a) == 1 && ft_checkifreversesorted(b) == 1)
	{
		while (b->size > 0)
			ft_pa(a, b);	
/*		
		printf("\nA : ");
		i = 0;
		while (i < a->size)
			printf("%d ", a->pile[i++]);
		i = 0;
		printf("\nB : ");
		while (i < b->size)
			printf("%d ", b->pile[i++]);
		printf("\n");
*/
		free(b->pile);
		free(a->pile);
		free(sub_a);
		free(sub_b);
		return ;
	}
/*	
	printf("\nA : %d - ", *nb_a);
	i = 0;
	while (i < a->size)
		printf("%d ", a->pile[i++]);
	i = 0;
	printf("\nB : %d - ", *nb_b);
	while (i < b->size)
		printf("%d ", b->pile[i++]);
	printf("\n");
*/	
	ft_quick_sort(a, b, sub_a, sub_b, nb_a, nb_b);
}
