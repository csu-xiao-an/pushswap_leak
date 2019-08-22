/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:48:16 by minakim           #+#    #+#             */
/*   Updated: 2019/08/22 02:57:53 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_arrlen(int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
		i++;
	return (i);
}

int		*insertSort(t_stack *a, int n)
{
	int	*sortedArr;
	int		*arr = (int*)malloc(sizeof(int) * n + 1);
	t_node	*tmp;

	tmp = a->top;
	for (int i = 0; i < n; i++)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
	}
	arr[i] = '\0';
	sortedArr = letsSort(arr, n);
	return (sortedArr);
}

void	chunk_sorting(t_stack *a, t_stack *b, int n)
{
	int	*arr;
	int	count;
	int	i;
	t_pivot	*new;

	i = 0;
	new = init_pivot();
	arr = insertSort(a, n);
	find_pivot2(arr, new, n);
	while (i < n)
	{
		count = 0;
	}
	//free(arr);
}

void	b_to_a(t_stack *a, t_stack *b, int *arr)
{
	int	l;
	int	n;

	n = 0;
	l = ft_arrlen(arr) - 1;
	while (l >= 0)
	{
		if (arr[l] == 1) {
			pa(a, b);
		}
		else {
			n = arr[l];
			chunk_sorting(a, b, n);
		}
		l--;
	}
	ft_printf("len = %d\n", l);
//	ft_printf("%d , %d \n", a->top->value, b->top->value);
}

/*
void	b_to_a(t_stack *a, t_stack *b, int *arr)
{
	int	count;

	count = 0;
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
*/
