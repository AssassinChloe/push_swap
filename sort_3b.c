#include "push_swap.h"

void	ft_sort_3b(t_pile *b)
{
	if (b->pile[0] > b->pile[1] && b->pile[0] < b->pile[2]
			&& b->pile[1] < b->pile[2])
		ft_sb(b);
	else if (b->pile[0] > b->pile[1] && b->pile[0] > b->pile[2]
			&& b->pile[1] > b->pile[2])
	{
		ft_sb(b);
		ft_rrb(b);
	}
	else if (b->pile[0] > b->pile[1] && b->pile[0] > b->pile[2]
			&& b->pile[1] < b->pile[2])
		ft_rb(b);
	else if (b->pile[0] < b->pile[1] && b->pile[0] < b->pile[2]
			&& b->pile[1] > b->pile[2])
	{
		ft_sb(b);
		ft_rb(b);
	}
	else if (b->pile[0] < b->pile[1] && b->pile[0] > b->pile[2]
			&& b->pile[1] > b->pile[2])
		ft_rrb(b);
	return ;
}