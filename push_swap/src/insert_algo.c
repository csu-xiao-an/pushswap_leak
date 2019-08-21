/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 01:17:14 by minakim           #+#    #+#             */
/*   Updated: 2019/08/20 16:30:00 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		*letsSort(int *arr, int n)
{
	int	i, key, j;

	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	return(arr);
}

int		*insertionSort(t_stack *a)
{
	int	i;
	int	n = check_nbr(a);
	int	*arr = (int*)malloc(sizeof(int) * (n + 1));
	int	*sortedArr;
	t_node	*tmp;

	i = 0;
	tmp = a->top;
	while (tmp)
	{
		arr[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	arr[i] = '\0';
	sortedArr = letsSort(arr, n);
	return (sortedArr);
}
