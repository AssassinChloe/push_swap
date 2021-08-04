#include "push_swap.h"


void ft_pa(t_pile *a, t_pile *b)
{
    int tmp;
    int i;
    int j;
    t_pile s_tmp;

    i = 1;
    j = 0;
    tmp = b->pile[0];
    while (i < b->size)
    {
        s_tmp.pile[j] = b->pile[i];
        i++;
        j++;
    }

    printf("pa\n");
    return ;
}

void ft_pb(t_pile *a, t_pile *b)
{
    printf("pb\n");
    return ;
}