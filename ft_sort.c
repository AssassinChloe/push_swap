#include "push_swap.h"

void ft_quick_sort(t_pile *a)
{
    int pivot;
    int *tab_b;
    int size_a;
    int size_b;
    int count;

    tab_b = NULL;
    pivot = a->pile[a->size - 1];
}

void    ft_sort_3(t_pile *a)
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

void    ft_sort_5(t_pile *a)
{
    if (a->size_max == 4)
        printf("plop\n");
    else
        printf("plop\n");
}
void ft_sort(t_pile *a)
{
    if (a->size_max == 2)
    {
        ft_sa(a->pile);
        return ;
    }
    else if (a->size_max == 3)
        ft_sort_3(a);
    else if (a->size_max > 3 && a->size_max <= 5)
        ft_sort_5(a);
    else
        ft_quick_sort(a);
    return ;
}