/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:24:28 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/06 17:13:22 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_pile
{
	int	*pile;
	int	size;
	int	size_max;
}	t_pile;

typedef struct s_subarray
{
	int pivot;
	int size;
	int rotation;
}	t_subarray;

long long	ft_atoll(const char *str);
int			ft_isdigit(int c);
int			ft_checkifsorted(t_pile *the);
void		ft_sort(t_pile *a);
void		ft_sort_3(t_pile *a);
void		ft_swap_two(t_pile *the);
void		ft_toptobot(t_pile *the);
void		ft_bottotop(t_pile *the);
int			ft_pa(t_pile *a, t_pile *b);
int			ft_pb(t_pile *a, t_pile *b);
void		ft_sa(t_pile *a);
void		ft_sb(t_pile *b);
void		ft_ss(t_pile *a, t_pile *b);
void		ft_ra(t_pile *a);
void		ft_rb(t_pile *b);
void		ft_rr(t_pile *a, t_pile *b);
void		ft_rra(t_pile *a);
void		ft_rrb(t_pile *b);
void		ft_rrr(t_pile *a, t_pile *b);
void		ft_quick_sort(t_pile *a, t_pile *b, t_subarray *sub_a, t_subarray *sub_b, int *nb_a, int *nb_b);
int			ft_addonetop(t_pile *the, int add);
int			ft_removeonetop(t_pile *the);
int			ft_freepile(t_pile *the);
int			ft_checkifreversesorted(t_pile *the);
int			ft_issmallest(t_pile *the, int pivot);
int			ft_isbigest(t_pile *the, int pivot);
int			ft_checkdouble(t_pile *a);
void		init_quick_sort(t_pile *a, t_pile *b);
void	ft_sort_3b(t_pile *b);
#endif
