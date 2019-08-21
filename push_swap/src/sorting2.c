/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:48:16 by minakim           #+#    #+#             */
/*   Updated: 2019/08/20 20:19:25 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	b_to_a(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
//	if (a->top) {
	while (b->top) {
		if (isEmpty(a)) {
			pa(a, b);
		}
		if (a->top->value > b->top->value) {
			pa(a, b);
			while (count > 0) {
				rra(a);
				count--;
			}
	//		for (int i = 0; i < count; i++) {
	//			rra(a);
	//		}
		}
		else {
			ra(a);
			count++;
		}
	}
}
