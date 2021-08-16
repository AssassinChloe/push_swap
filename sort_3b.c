#include "push_swap.h"

void	ft_sort_3b(t_pile *a)
{
	if (a->size == 1)
		return ;
	if (a->size == 2 && ft_checkifreversesorted(a) == 0)
	{
		ft_sb(a);
		return ;
	}
	if (a->pile[0] < a->pile[1] && a->pile[0] > a->pile[2]
			&& a->pile[1] > a->pile[2])
		ft_sb(a);
	else if (a->pile[0] < a->pile[1] && a->pile[0] < a->pile[2]
			&& a->pile[1] < a->pile[2])
	{
		ft_sb(a);
		ft_rrb(a);
	}
	else if (a->pile[0] < a->pile[1] && a->pile[0] < a->pile[2]
			&& a->pile[1] > a->pile[2])
		ft_rb(a);
	else if (a->pile[0] > a->pile[1] && a->pile[0] > a->pile[2]
			&& a->pile[1] < a->pile[2])
	{
		ft_sb(a);
		ft_rb(a);
	}
	else if (a->pile[0] > a->pile[1] && a->pile[0] < a->pile[2]
			&& a->pile[1] < a->pile[2])
		ft_rrb(a);
	return ;
}

void	ft_sort3sub_b(t_pile *b)
{
	if (b->sub[b->i] == 1)
		return ;
	if (b->sub[b->i] == 2 && ft_checkifreversesorted(b) == 0)
	{
		ft_sb(b);
		return ;
	}
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
	if (a->sub[a->i] == 1)
		return ;
	if (a->sub[a->i] == 2 && ft_checkifsorted(a) == 0)
	{
		ft_sa(a);
		return ;
	}
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
