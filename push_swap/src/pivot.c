/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:03:37 by minakim           #+#    #+#             */
/*   Updated: 2019/08/22 02:57:56 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_bot(t_stack *a)
{
	t_node	*tmp;
	int		bot;

	tmp = a->top;
	while (tmp) {
		bot = tmp->value;
		tmp = tmp->next;
	}
	return (bot);
}

void	find_pivot(t_stack *a, int *arr, t_pivot *p)
{
	int	n;

	n = check_nbr(a);
	p->index = (n / 2);
	p->left_nbr = (n / 2);
	p->i_value = arr[p->index];
//	ft_printf("element nbr = %d\n", n);
//	ft_printf("p->index = %d\n", p->index);
//	ft_printf("p->left_nbr = %d\n", p->left_nbr);
//	ft_printf("p->i_value = %d\n", p->i_value);
}

void	find_pivot2(int *arr, t_pivot *p, int n)
{
	p->index = (n / 2);
	p->left_nbr = (n / 2);
	p->i_value = arr[p->index];
}
