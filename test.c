#include "push_swap.h"

void init_quick_sort(t_pile *a, t_pile *b)
{
    int i;
    int j;
    t_subarray *sub_a;
    t_subarray *sub_b;

    sub_a = malloc(sizeof(t_subarray) * (a->size_max / 3));
    sub_b = malloc(sizeof(t_subarray) * (a->size_max / 3));

    i = 0;
	sub_a[0].pivot = a->pile[(a->size - 1)];
    sub_a[0].size = a->size;
	while (i < sub_a[0].size)
	{
		if (a->pile[0] <= sub_a[0].pivot)
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
    sub_a[0].size = a->size;
    sub_b[0].size = b->size;
    i = 1;
    j = 0;
    sub_a[i].size = 0;
    ft_quick_sort(a, b, &sub_a, &sub_b, &i, &j);
}

void	ft_quick_sort(t_pile *a, t_pile *b, t_subarray **sub_a, t_subarray **sub_b, int *nb_a, int *nb_b)
{
    int size_init;
    int i;
    
    while (sub_b[*nb_b]->size > 3 && ft_checkifreversesorted(b) == 0)
	{
        i = 0;
        sub_b[*nb_b]->rotation = 0;
        sub_b[*nb_b]->pivot = b->pile[(sub_b[*nb_b]->size - 1)];
        if (ft_issmallest(b, sub_b[*nb_b]->size, sub_b[*nb_b]->pivot) == 1)
            sub_b[*nb_b]->pivot = b->pile[sub_b[*nb_b]->size - 2];
        size_init = sub_b[*nb_b]->size;
		while (i < size_init)
		{
			if (b->pile[0] >= sub_b[*nb_b]->pivot)
			{
				if (ft_pa(a, b) < 0)
				{
                    printf("error pa\n");
					return ;
				}
                printf("a : %d - %d\n", *nb_a, sub_a[*nb_a]->size);
                sub_a[*nb_a]->size++;
                printf("b : %d - %d\n", *nb_b, sub_b[*nb_b]->size);
                sub_b[*nb_b]->size--;
			}
			else
            {
				ft_rb(b);
                sub_b[*nb_b]->rotation++;
            }
			i++;
		}
        while (*nb_b > 0 && sub_b[*nb_b]->rotation > 0)
        {
            ft_rrb(b);
            sub_b[*nb_b]->rotation--;
        }
        if (sub_b[*nb_b]->size > 3)
        {
            *nb_a++;
            sub_a[*nb_a]->size = 0;
        }
        printf("%d\n", *nb_a);
	}
    if (sub_b[*nb_b]->size <= 3)
    {
        if (sub_b[*nb_b]->size == 2 && ft_checkifreversesorted(b) == 0)
            ft_sb(b);
        else if (sub_b[*nb_b]->size == 3 && ft_checkifreversesorted(b) == 0)
            ft_sort3sub_b(b);
        *nb_b++;
        sub_b[*nb_b]->size = 0;
    }
    if (sub_a[*nb_a]->size <= 3)
    {
        if (sub_a[*nb_a]->size == 2 && ft_checkifsorted(a) == 0)
            ft_sa(a);
        else if (sub_a[*nb_a]->size == 3 && ft_checkifsorted(a) == 0)
            ft_sort3sub_a(a);
        while (sub_a[*nb_a]->size > 0)
        {
            ft_pb(a, b);
            sub_b[*nb_b]->size++;
            sub_a[*nb_a]->size--;
        }
        *nb_a--;
    }
    else
    {
        i = 0;
        size_init = sub_a[*nb_a]->size;
        sub_a[*nb_a]->rotation = 0;
        sub_a[*nb_a]->pivot = a->pile[(sub_a[*nb_a]->size - 1)];
        if (ft_isbigest(a, sub_a[*nb_a]->size, sub_a[*nb_a]->pivot) == 1)
            sub_a[*nb_a]->pivot = a->pile[sub_a[*nb_a]->size - 2];
        while (i < size_init)
        {
            if (a->pile[0] <= sub_a[*nb_a]->pivot)
            {
                if (ft_pb(a, b) < 0)
                {
                    printf("error pb\n");
                    return ;
                }
                sub_b[*nb_b]->size++;
                sub_a[*nb_a]->size--;
            }
            else
            {
                ft_ra(a);
                sub_a[*nb_a]->rotation++;
            }
            i++;
        }
        while (*nb_a > 0 && sub_a[*nb_a]->rotation > 0)
        {
            ft_rra(a);
            sub_a[*nb_a]->rotation--;
        }
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