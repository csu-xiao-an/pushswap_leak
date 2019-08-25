/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:48:16 by minakim           #+#    #+#             */
/*   Updated: 2019/08/22 13:16:33 by minakim          ###   ########.fr       */
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
	int	i;
	int	*sortedArr;
	int		*arr = (int*)malloc(sizeof(int) * n + 1);
	t_node	*tmp;

	i = 0;
	tmp = a->top;
	while (i++ < n)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
	}
	arr[i] = '\0';
	sortedArr = letsSort(arr, n);
	return (sortedArr);
}
/*
void	chunk_a_sorting(t_stack *a, t_stack *b, int size)
{
	int		*arr;
	int		num_a;
	int		count;
	int		num_ch;
	t_pivot	*new;

	count = 0;
	new = init_pivot();
	arr = insertSort(a, size);
	find_pivot2(arr, new, size);
	num_a = size;
	if (isEmpty(b) == 1)
		return ;
//	ft_printf("CHUNK_A\n");
	while (num_a != 0) {
		if (num_a == 1) {
		//	num_a--;
		//	ft_printf("RETURED\n");
			return ;
		}
		if (size == 2) {
			if (ft_strcmp(is_chunk_sorted(a, num_a), "A") == 0) {
				sa(a);
			}
		}
		if (ft_strcmp(is_chunk_sorted(a, num_a), "B") == 0) {
	//		ft_printf("AA\n");
			return ;
		}
		else {
			if (a->top->value < new->i_value) {
				pb(a, b);
		//		num_a--;
			}
			else {
				ra(a);
				count++;
		//		num_a--;
			}
		}
		num_ch = num_a / 2;
		num_a = num_a / 2;
		if (num_ch > num_a)
			chunk_a_sorting(a, b, num_a);
			chunk_sorting(a, b, size-num_a);
		while (count-- > 0) {
			rra(a);
		}
	}
}
*/
/*
void	chunk_a_sorting(t_stack *a, t_stack *b, int size)
{
	t_pivot	*new;
	t_node	*tmp;
	int		i;
	int		count;

	i = 0;
	count = 0;
	tmp = a->top;
	new = init_pivot();
	chunk_mid(a, size, new);
	while (i < size) {
		if (tmp->value < new->i_value)
			pb(a, b);
		else {
			ra(a);
			count++;
		}
		i++;
		tmp = a->top;
	}
	while (count-- > 0)
	{
		rra(a);
		count--;
	}
}
*/

//last
/*
void	chunk_sorting(t_stack *a, t_stack *b, int n)
{
	int	*arr;
	int	num_a;
	int	count;
	int	num_ch;
	t_pivot	*new;

	count = 0;
	new = init_pivot();
	arr = insertSort(b, n);
	find_pivot2(arr, new, n);
	num_a = n;
//	ft_printf("\n n = %d\n", n);
	while (num_a != 0) {
//		ft_printf("%d\n", num_a);
		if (num_a == 1) {
//			ft_printf("PA\n");
			pa(a, b);
//			num_a--;
//			ft_printf("what : %d\n", num_a);
			return ;
		}
//		ft_printf("n : %d, num_a : %d\n", n, num_a);
		if (num_a == 2) {
//			ft_printf("chara : %s\n", is_chunk_sorted(b, num_a));
//			ft_printf("int : %d\n", ft_strcmp(is_chunk_sorted(b, num_a), "B"));
			if (ft_strcmp(is_chunk_sorted(b, num_a), "B") == 0) {
				sb(b);
			}
		}
		if (ft_strcmp(is_chunk_sorted(b, num_a), "A") == 0) {
//			ft_printf("BB\n");
			pa(a, b);
//			num_a--;
		}
		if (num_a > 2) {
			if (b->top->value > new->i_value) {
//				ft_printf("??????\n");
				pa(a, b);
//				num_a--;
//				ft_printf("new->i_value : %d\n", new->i_value);
			}
			else {
				rb(b);
				count++;
//				num_a--;
			}
		}
		num_ch = num_a / 2;
		num_a = num_a / 2;
//		ft_printf("\nhi%d\n", num_ch);
//		ft_printf("\nhi%d\n", num_a);
//		ft_printf("\nhi\n");
		if (num_ch > num_a)
			chunk_sorting(a, b, num_a);
		chunk_a_sorting(a, b, n - num_a);
		while (count-- > 0) {
			rrb(b);
//			num_a++;
		}
//		ft_printf("num_a : %d\n", num_a);
//		ft_printf("checkpoint\n");
//		chunk_a_sorting(a, b, n - num_a);
	}
}
*/

/*
void	chunk_sorting(t_stack *a, t_stack *b, int n)
{
	int	*arr;
	int	num_a;
	int	count;
	int	i;
	t_pivot	*new;

	i = 0;
	count = 0;
	new = init_pivot();
	arr = insertSort(a, n);
	find_pivot2(arr, new, n);
	num_a = n;
	ft_printf("num_a : %d, n : %d\n", num_a, n);
	while (i < num_a)
	{
		if (num_a == 2) {
			if (b->top->value > b->top->next->value) {
				pa(a, b);
				pa(a, b);
			}
			else {
				sb(b);
				pa(a, b);
				pa(a, b);
			}
			return ;
		}
		else {
			if (b->top->value > new->i_value) {
				pa(a, b);
			}
			else {
				rb(b);
				count++;
			}
			num_a = n / 2;
			while (num_a > 2) {
				a_to_b_sorting(a, b, num_a);
				num_a = num_a / 2;
			}
			i++;
		}
	}
	while (count-- > 0) {
		rrb(b);
	}
	//free(arr);
}
*/
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
//			ft_printf("     new chunk\n");
		//	ft_printf("!!!!!!!!!\n");
		}
		l--;
	}
//	ft_printf("len = %d\n", l);
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
