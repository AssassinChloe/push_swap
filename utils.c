#include "push_swap.h"
void ft_swap_two(t_pile *the)
{
    int swp;
    swp = the->pile[0];
    the->pile[0] = the->pile[1];
    the->pile[1] = swp;
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