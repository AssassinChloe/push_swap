#include "push_swap.h"

void ft_ra(t_pile *a)
{
    ft_toptobot(a);
    printf("ra\n");
}

void ft_rb(t_pile *b)
{
    ft_toptobot(b);
    printf("rb\n");
}

void ft_rr(t_pile *a,t_pile *b)
{
    ft_toptobot(a);
    ft_toptobot(b);
    printf("rr\n");
}

void    ft_toptobot(t_pile *the)
{
    int tmp;
    int i;
    int j;

    i = 0;
    j = 1;
    tmp = the->pile[i];
    while (j < the->size)
    {
        the->pile[i] = the->pile[j];
        i++;
        j++;
    }
    the->pile[i] = tmp;
}