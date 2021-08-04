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