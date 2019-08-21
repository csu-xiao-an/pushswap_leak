/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:48:16 by minakim           #+#    #+#             */
/*   Updated: 2019/08/20 20:05:10 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	b_to_a(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	ft_printf("b_to_a\n");
	ft_printf("b->top : %d\n", b->top->value);
//	if (a->top) {
	while (b->top) {
		ft_printf("whileloop\n");
		if (isEmpty(a)) {
			pa(a, b);
			ft_printf("1\n");
		}
		if (a->top->value > b->top->value) {
			pa(a, b);
			ft_printf("2\n");
			while (count > 0) {
				rra(a);
				ft_printf("3\n");
				count--;
			}
	//		for (int i = 0; i < count; i++) {
	//			rra(a);
	//		}
		}
		else {
			ra(a);
			ft_printf("4\n");
			count++;
		}
	}
}
