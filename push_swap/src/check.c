/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:41:37 by minakim           #+#    #+#             */
/*   Updated: 2019/08/17 19:44:08 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_index(t_stack *a, int min)
{
	t_node	*tmp;
	int	i;

	i = 0;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->value == min)
			return (i + 1);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int		find_max(t_stack *a)
{
	t_node	*tmp;
	int	max = 0;

	tmp = a->top;
	while(tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return(max);
}

int		find_min(t_stack *a)
{
	t_node	*tmp;
	int	min;

	tmp = a->top;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

void	find_mid(t_stack *a, t_struct *nbr)
{
	t_node	*tmp;
	int	mid;

	tmp = a->top;
	mid = tmp->value;
	while(tmp)
	{
		if (tmp->value != nbr->min && tmp->value 
			!= nbr->max)
			mid = tmp->value;
		tmp = tmp->next;
	}
	nbr->mid = mid;
}

void	check_value(t_stack *a, t_struct *nbr)
{
//	t_node	*tmp;

//	tmp = a->top;
	nbr->min = find_min(a);
	nbr->max = find_max(a);
	find_mid(a, nbr);
}

int		check_nbr(t_stack *a)
{
	int	count = 0;
	t_node	*tmp;

	tmp = a->top;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

char	*is_chunk_sorted(t_stack *s, int n)
{
	int	i;
	int	j;
	int	a;
	int	b;
	char	*answer;
	int	*arr = (int*)malloc(sizeof(int) * n + 1);
	t_node	*tmp;

	i = 0;
	b = 0;
	a = 0;
	j = 0;
	tmp = s->top;
	if (n == 2) {
		if (tmp->value < tmp->next->value)
			answer = "B";
		else
			answer = "A";
		return (answer);
	}
	while (i < n)
	{
		arr[i] = tmp->value;
		i++;
	}
	arr[i] = '\0';
	i = 0;
	while (arr[i])
	{
		if (arr[i] > arr[i + 1]) {
			a++;
		}
		else if (arr[i] <= arr[i + 1]) {
			b++;
		}
		i++;
	}
	if (b == n)
		answer = "B";
	else if (a == n)
		answer = "A";
	else
		answer = "false";
	free(arr);
	return (answer);
}
