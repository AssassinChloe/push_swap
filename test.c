#include "push_swap.h"

void init_quick_sort(t_pile *a, t_pile *b)
{
    int i;
    int j;
    t_subarray *sub_a;
    t_subarray *sub_b;

    sub_a = malloc(sizeof(t_subarray) * (a->size_max / 3));
    sub_b = malloc(sizeof(t_subarray) * (a->size_max / 3));

    j = 0;
    sub_a[j].size = a->size;
	sub_a[j].pivot = a->pile[(a->size - 1)];
	while (i < sub_a[j].size)
	{
		if (a->pile[0] <= sub_a[j].pivot)
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
    i = 0;
    sub_b[i].size = b->size;
    ft_quick_sort(a, b, sub_a, sub_b, &i, &j);
}

void	ft_quick_sort(t_pile *a, t_pile *b, t_subarray *sub_a, t_subarray *sub_b, int *nb_a, int *nb_b)
{
    int size_init;
    int i;
    
    while (sub_b[*nb_b].size > 3 && ft_checkifreversesorted(b) == 0)
	{
        i = 0;
        sub_b[*nb_b].rotation = 0;
        sub_b[*nb_b].pivot = b->pile[(sub_b[*nb_b].size - 1)];
        sub_a[*nb_a].size = 0;
        size_init = sub_b[*nb_b].size;
		while (i < size_init)
		{
			if (b->pile[0] >= sub_b[*nb_b].pivot)
			{
				if (ft_pa(a, b) < 0)
				{
                    printf("error pa\n");
					return ;
				}
                sub_a[*nb_a].size++;
			}
			else
            {
				ft_rb(b);
                sub_b[*nb_b].rotation++;
            }
			i++;
		}
        while (sub_b[*nb_b].rotation > 0)
        {
            ft_rrb(b);
            sub_b[*nb_b].rotation--;
        }
        *nb_a++;
	}
    if (sub_b[*nb_b].size <= 3 && ft_checkifreversesorted(b) == 0)
    {
        i = 0;
        ft_sort_3b(b);
        while (i < sub_b[*nb_b].size)
        {
            ft_pa(a, b);
            i++;
        }
        *nb_b--;
    }
    while (sub_a[*nb_a].size > 3 && ft_checkifsorted(a) == 0)
    {
		i = 0;
		size_init = sub_a[*nb_a].size;
        sub_a[*nb_a].rotation = 0;
        sub_b[*nb_b].size = 0;
		sub_a[*nb_a].pivot = a->pile[(sub_a[*nb_a].size - 1)];
		while (i < size_init)
		{
			if (a->pile[0] <= sub_a[*nb_a].pivot)
			{
				if (ft_pb(a, b) < 0)
				{
					printf("error pb\n");
					return ;
				}
                sub_b[*nb_b].size++;
			}
			else
            {
				ft_ra(a);
                sub_a[*nb_a].rotation++;
            }
			i++;
		}
        while (sub_a[*nb_a].rotation > 0)
        {
            ft_rra(a);
            sub_a[*nb_a].rotation--;
        }
        *nb_b++;
	}
	if (ft_checkifsorted(a) == 1 && ft_checkifreversesorted(b) == 1)
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
    if (sub_b[*nb_b].size <= 3 && ft_checkifreversesorted == 0)
    {
        i = 0;
        ft_sort_3b(b);
        while (i < sub_b[*nb_b].size)
        {
            ft_pa(a, b);
            i++;
        }
        *nb_b--;
    }
    if (sub_a[*nb_a].size <= 3 && ft_checkifsorted == 0)
    {
        i = 0;
        ft_sort_3(a);
        while (i < sub_a[*nb_a].size)
        {
            ft_pb(a, b);
            i++;
        }
        *nb_a--;
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
ft_quick_sort(a, b, sub_a, sub_b, nb_a, nb_b);
}