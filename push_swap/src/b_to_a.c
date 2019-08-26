/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:44:39 by minakim           #+#    #+#             */
/*   Updated: 2019/08/25 20:50:25 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		count_arr(int n)
{
	int	count;
	int	tmp;

	tmp = n / 2;
	count = 1;
	while (tmp > 2) {
		tmp = tmp - tmp / 2;
		count++;
	}
	return (count);
}

int		mid_point(t_stack *s, int n)
{
	int	i;
	int	arr[n];
	int	*new_arr;
	t_node	*tmp;

	i = 0;
	tmp = s->top;
	while (i < n)
	{
		arr[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	new_arr = letsSort(arr, n);
	i = n % 2 ? n / 2 :  n / 2 - 1;
//	ft_printf("new_arr[n/2] %d\n", new_arr[n / 2]);
	return (new_arr[i]);
}

void	push_to_a(t_stack *a, t_stack *b, int n)
{
//	int	*arr;
//	t_pivot	*new;
	int	i;
	int	mid;
	int	count;
	t_node	*tmp;

	i = 0;
	count = 0;
	mid = mid_point(b, n);
//	new = init_pivot();
//	arr = insertSort(b, n);
//	find_pivot2(arr, new, n);
	tmp = b->top;
	while (i < n)
	{
	//	ft_printf("n : %d\n", n);
	//	ft_printf("arr : %d\n", arr[i]);
	//	ft_printf("i : %d, n : %d\n", i, n);
	//	ft_printf("tmp->value : %d, new->i_value : %d\n", tmp->value, mid);
		if (tmp->value > mid)
			pa(a, b);
		else {
			rb(b);
			count++;
		}
		i++;
		tmp = b->top;
	}
	while (count-- > 0)
		rrb(b);
}

void	chunk_sorting(t_stack *a, t_stack *b, int n)
{
	int	nbr_a;
	int	arr[count_arr(n)];
	int	i;

	i = 1;
//	ft_printf("----------Stack b-----------\n");
//	print_stack (b);
//	ft_printf("----------Stack a-----------\n");
//	print_stack (a);
	if (n == 1) {
	//	ft_printf("n == 1\n");
		pa(a, b);
	}
	else if (n == 2) {
	//	ft_printf("n == 2\n");
		if (ft_strcmp(is_chunk_sorted(b, n), "B") == 0) {
	//		ft_printf("strcmp with B\n");
			sb(b);
		}
		while (n-- > 0) {
	//		ft_printf("loop1\n");
			pa(a, b);
		}
	}
//	else if (n >= 3 && n <= 5) {
//		super_fast(a, b);
//	}
	else {
//		ft_printf("chunk n : %d\n", n);
	//	ft_printf("else\n");
//		if (ft_strcmp(is_chunk_sorted(b, n), "A") == 0) {
//			while (n-- > 0)
//				pa(a, b);
//		}
		push_to_a(a, b, n);
		nbr_a = n / 2;
		arr[0] = n - nbr_a;
	//	ft_printf("nbr_a : %d, arr[0] = %d\n", nbr_a, arr[0]);
		while (nbr_a > 2) {
			arr[i] = a_to_b(a, b, nbr_a);
		//	nbr_a = nbr_a / 2;
			nbr_a = nbr_a % 2 ? nbr_a / 2 + 1 : nbr_a / 2;
			i++;
		}
		if (ft_strcmp(is_chunk_sorted(a, 2), "A") == 0)
			sa(a);
		i = count_arr(n) - 1;
		while (i >= 0)
			chunk_sorting(a, b, arr[i--]);
	}
}

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
	ft_printf("stack a\n");
	print_stack(a);
	ft_printf("stack b\n");
	print_stack(b);
	if (num_a == 1) {
		pa(a, b);
		return ;
	}
	else if (num_a == 2) {
		if (ft_strcmp(is_chunk_sorted(b, num_a), "B") == 0) {
			sb(b);
		}
		while (num_a-- > 0)
			pa(a);
		return ;
	}
	else {
		while (num_a != 0) {
			if (ft_strcmp(is_chunk_sorted(b, num_a), "A") == 0) {
				while (num_a-- > 0)
					pa(a);
				return ;
			}
			if (b->top->value > new_i_value) {
				pa(a, b);
				num_a--;
			}
			else {
				rb(b);
				count++;
			}
		}
		
	}

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
