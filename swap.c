#include "push_swap.h"

void ft_sa(t_pile *a)
{
    ft_swap_two(a);
    printf("sa\n");
}

void ft_sb(t_pile *b)
{
    ft_swap_two(b);
    printf("sb\n");
}

void ft_ss(t_pile *a, t_pile *b)
{
    ft_swap_two(a);
    ft_swap_two(b);   
    printf("ss\n");
}