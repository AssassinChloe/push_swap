#include "push_swap.h"

int main(void)
{
    t_pile test;
    int i;

    i = 0;
    test.pile = malloc(sizeof(int) * 5);
    test.size_max = 6;
    test.size = 5;
    while (i < 5)
    {
        test.pile[i] = i;
        i++;
    }
    i = 0;
    while (i < test.size)
        printf("%d ", test.pile[i++]);
    printf("\n");
    if (ft_addonetop(&test, 198) < 0)
        return (1);
    i = 0;
    while (i < test.size)
        printf("%d ", test.pile[i++]);
    return (0);
}