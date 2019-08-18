/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:47:00 by minakim           #+#    #+#             */
/*   Updated: 2019/08/17 21:49:34 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_struct	*init_nbr(void)
{
	struct s_struct	*new = malloc(sizeof(struct s_struct));

	new->mid = 0;
	new->max = 0;
	new->min = 0;
	return (new);
}

int			find_range(t_struct *nbr, int div)
{
	int	range;

	range = (nbr->max - nbr->min) / div;
	return (range);
}
