#include "push_swap.h"

void ft_rra(t_pile *a)
{
    ft_bottotop(a);
    printf("rra\n");
}

void ft_rrb(t_pile *b)
{
    ft_bottotop(b);
    printf("rrb\n");
}

void ft_rrr(t_pile *a, t_pile *b)
{
    ft_bottotop(a);
    ft_bottotop(b);
    printf("rrr\n");
}

void    ft_bottotop(t_pile *the)
{
    int tmp;
    int i;
    int j;

    i = the->size - 2;
    j = the->size - 1;
    tmp = the->pile[j];
    while (i >= 0)
    {
        the->pile[j] = the->pile[i];
        i--;
        j--;
    }
    the->pile[j] = tmp;
}