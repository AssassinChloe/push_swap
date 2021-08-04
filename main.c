#include "push_swap.h"

int ft_isnb(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '+' || str[i] == '-' || ft_isdigit(str[i]) == 1)
            i++;
        else
            return (-1);
    }
    return (1);
}


int main(int ac, char **av)
{
    int i;
    int j;
    t_pile a;

    i = 1;
    j = 0;
    if (ac < 3)
    {
        printf("error : missing arguments\n");
        return (0);
    }
    else
    {
        a.pile = malloc(sizeof(int) * (ac - 1));
        if (!(a.pile))
            return (printf("error malloc\n"));
        while (i < ac)
        {
            if (ft_isnb(av[i]) > 0)
            {
                a.pile[j] = ft_atoll(av[i]);
                if (a.pile[j] < INT_MIN || a.pile[j] > INT_MAX)
                {
                    printf("error : int overflow/underflow\n");
                    return (0);
                }
                j++;
                i++;
            }
            else
            {
                printf("Some of the inputs are wrong\n");
                return (0);
            }
        }
        a.size_max = j;
        a.size = j;
    }
    if (ft_checkifsorted(&a) == 1)
        return (0);
    ft_sort(&a);
    return (0);
}

int ft_checkifsorted(t_pile *the)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (j < the->size)
    {
        if (the->pile[i] > the->pile[j])
            return (0);
        i++;
        j++;
    }
    return (1);
}

int ft_checkifreversesorted(t_pile *the)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (j < the->size)
    {
        if (the->pile[i] < the->pile[j])
            return (0);
        i++;
        j++;
    }
    return (1);
}