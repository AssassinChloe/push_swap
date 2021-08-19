/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:16:41 by cassassi          #+#    #+#             */
/*   Updated: 2021/08/19 15:18:23 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_pile *a, t_pile *b)
{
	ft_endfree(a);
	ft_endfree(b);
}

void	ft_endfree(t_pile *the)
{
	if (the->pile != NULL)
	{
		free(the->pile);
		the->pile = NULL;
	}
	if (the->sub != NULL)
	{
		free(the->sub);
		the->sub = NULL;
	}
	if (the->ignore != NULL)
	{
		free(the->ignore);
		the->ignore = NULL;
	}
}

