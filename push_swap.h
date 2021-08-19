/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:24:28 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/19 17:12:18 by cassassi         ###   ########.fr       */
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
	int	*sub;
	int	*ignore;
	int	i;
	int	size_max;
}	t_pile;

long long	ft_atoll(const char *str);
int		ft_isdigit(int c);
int		ft_buildpile(t_pile *a, int size, char **av);
int		ft_isnb(char *str);
int		ft_checkifsorted(t_pile *a);
int		ft_checkifallsorted(t_pile *a);
int		ft_init(t_pile *the, int size);
void		ft_sort(t_pile *a, t_pile *b);
void		ft_sort_3(t_pile *a);
void		ft_sort5_a(t_pile *a, t_pile *b);
void		ft_swap_two(t_pile *the);
void		ft_toptobot(t_pile *the);
void		ft_bottotop(t_pile *the);
int		ft_pa(t_pile *a, t_pile *b);
int		ft_pb(t_pile *a, t_pile *b);
void		ft_sa(t_pile *a);
void		ft_sb(t_pile *b);
void		ft_ss(t_pile *a, t_pile *b);
void		ft_ra(t_pile *a);
void		ft_rb(t_pile *b);
void		ft_rr(t_pile *a, t_pile *b);
void		ft_rra(t_pile *a);
void		ft_rrb(t_pile *b);
void		ft_rrr(t_pile *a, t_pile *b);
void		ft_quick_sort(t_pile *a, t_pile *b);
int		ft_addonetop(t_pile *the, int add);
int		ft_removeonetop(t_pile *the);
int		ft_freepile(t_pile *the);
int		ft_checkifreversesorted(t_pile *b);
int		ft_checkifallreversesorted(t_pile *b);
int		ft_issmallest(t_pile *the, int pivot);
int		ft_isbigest(t_pile *the, int pivot);
int		ft_checkdouble(t_pile *a);
void		init_quick_sort(t_pile *a, t_pile *b);
void		ft_sort3sub_b(t_pile *b);
void		ft_sort3sub_a(t_pile *a);
void		ft_newsort5(t_pile *a, t_pile *b);
void		ft_sort_3b(t_pile *a);
void		ft_sort5_b(t_pile *a, t_pile *b);
int		ft_findmed(t_pile *the);
int		ft_anypbleft(t_pile *a, int pivot);
int		ft_anypaleft(t_pile *b, int pivot);
void		ft_ignorezero(t_pile *the);
int		ft_findmedstack(t_pile *the);
void		ft_endfree(t_pile *the);
int		ft_free(t_pile *a, t_pile *b);
#endif
