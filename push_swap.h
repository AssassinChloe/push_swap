#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_pile
{
    int *pile;
    int size;
    int size_max;
}   t_pile;

long long   ft_atoll(const char *str);
int	ft_isdigit(int c);
int ft_checkifsorted(t_pile *the);
void ft_sort(t_pile *a);
void ft_sort_3(t_pile *a);
void ft_swap_two(t_pile *the);
void ft_toptobot(t_pile *the);
void ft_bottotop(t_pile *the);
void ft_pa(t_pile *a, t_pile *b);
void ft_pb(t_pile *a, t_pile *b);
void ft_sa(t_pile *a);
void ft_sb(t_pile *b);
void ft_ss(t_pile *a, t_pile *b);
void ft_ra(t_pile *a);
void ft_rb(t_pile *b);
void ft_rr(t_pile *a, t_pile *b);
void ft_rra(t_pile *a);
void ft_rrb(t_pile *b);
void ft_rrr(t_pile *a, t_pile *b);
void ft_quick_sort(t_pile *a);

#endif