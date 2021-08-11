#include "push_swap.h"

void	ft_sort3sub_b(t_pile *b)
{
	if (b->pile[0] < b->pile[1] && b->pile[0] > b->pile[2]
			&& b->pile[1] > b->pile[2])
		ft_sb(b);
	else if (b->pile[0] < b->pile[1] && b->pile[0] < b->pile[2]
			&& b->pile[1] < b->pile[2])
	{

        ft_sb(b);
        ft_rb(b);
        ft_sb(b);
		ft_rrb(b);
        ft_sb(b);
	}
	else if (b->pile[0] < b->pile[1] && b->pile[0] < b->pile[2]
			&& b->pile[1] > b->pile[2])
    {
        ft_sb(b);
        ft_rb(b);
        ft_sb(b);
        ft_rrb(b);
    }
	else if (b->pile[0] > b->pile[1] && b->pile[0] > b->pile[2]
			&& b->pile[1] < b->pile[2])
	{	
        ft_rb(b);
		ft_sb(b);
		ft_rrb(b);
	}
	else if (b->pile[0] > b->pile[1] && b->pile[0] < b->pile[2]
			&& b->pile[1] < b->pile[2])
    {
        ft_rb(b);
        ft_sb(b);
	    ft_rrb(b);
        ft_sb(b);
    }
	return ;
}

void	ft_sort3sub_a(t_pile *a)
{
	if (a->pile[0] > a->pile[1] && a->pile[0] < a->pile[2]
			&& a->pile[1] < a->pile[2])
		ft_sa(a);
	else if (a->pile[0] > a->pile[1] && a->pile[0] > a->pile[2]
			&& a->pile[1] > a->pile[2])
	{
        ft_sa(a);
        ft_ra(a);
        ft_sa(a);
		ft_rra(a);
        ft_sa(a);
	}
	else if (a->pile[0] > a->pile[1] && a->pile[0] > a->pile[2]
			&& a->pile[1] < a->pile[2])
    {
        ft_sa(a);
        ft_ra(a);
        ft_sa(a);
        ft_rra(a);
    }
	else if (a->pile[0] < a->pile[1] && a->pile[0] < a->pile[2]
			&& a->pile[1] > a->pile[2])
	{
        ft_ra(a);
		ft_sa(a);
		ft_rra(a);
	}
	else if (a->pile[0] < a->pile[1] && a->pile[0] > a->pile[2]
			&& a->pile[1] > a->pile[2])
    {
        ft_ra(a);
        ft_sa(a);
		ft_rra(a);
        ft_sa(a);
    }
	return ;
}