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
