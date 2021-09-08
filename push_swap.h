/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:24:28 by cassassi          #+#    #+#             */
/*   Updated: 2021/09/08 15:37:48 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_pile
{
	int	*pile;
	int	size;
	int	*sub;
	int	*ignore;
	int	pivot;
	int	rot;
	int	i;
}	t_pile;

void		ft_check_arg(int ac, char **av);
void		ft_check_pile(t_pile *a, t_pile *b, char ***tab, int i);
int			ft_buildpile(t_pile *a, int size, char ***tab);
int			ft_isnb(char *str);
int			ft_checkifsorted(t_pile *a);
int			ft_checkifallsorted(t_pile *a);
int			ft_init(t_pile *the, int size);
void		ft_sort(t_pile *a, t_pile *b);
void		ft_sort_3(t_pile *a);
void		ft_sort5_a(t_pile *a, t_pile *b);
void		ft_swap_two(t_pile *the);
void		ft_toptobot(t_pile *the);
void		ft_bottotop(t_pile *the);
void		ft_pa(t_pile *a, t_pile *b);
void		ft_pb(t_pile *a, t_pile *b);
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
void		ft_divide_a(t_pile *a, t_pile *b, int size);
void		ft_divide_b(t_pile *a, t_pile *b, int size);
void		ft_fiveunder_a(t_pile *a, t_pile *b);
void		ft_fiveunder_b(t_pile *a, t_pile *b);
int			ft_addonetop(t_pile *the, int add);
int			ft_removeonetop(t_pile *the);
int			ft_freepile(t_pile *the);
int			ft_checkifreversesorted(t_pile *b);
int			ft_checkifallreversesorted(t_pile *b);
int			ft_small(t_pile *the, int pivot);
int			ft_big(t_pile *the, int pivot);
int			ft_checkdouble(t_pile *a);
void		init_quick_sort(t_pile *a, t_pile *b);
void		ft_sort3sub_b(t_pile *b);
void		ft_sort3sub_a(t_pile *a);
void		ft_sort_3b(t_pile *a);
void		ft_sort5_b(t_pile *a, t_pile *b);
int			ft_anypbleft(t_pile *a, int size);
int			ft_anypaleft(t_pile *b, int size);
void		ft_ignorezero(t_pile *the);
void		ft_findmedstack(t_pile *the);
void		ft_endfree(t_pile *the);
int			ft_free(t_pile *a, t_pile *b);
int			ft_error(t_pile *a, t_pile *b);
void		ft_free_tab(char ***tab, int size);
void		ft_quit(void);

int	ft_sort_3bd(t_pile *b, int *tab[2]);
int	ft_sort_3d(t_pile *a, int *tab[2]);
void	ft_double_sort(t_pile *a, t_pile *b);
void	ft_acton_b (t_pile *b, int *tab[2], int *j);
void	ft_acton_a (t_pile *a, int *tab[2], int *i);
int		ft_sort3sub_bd(t_pile *b, int *tab[2]);
int		ft_sort3sub_ad(t_pile *a, int *tab[2]);

#endif
