#include "../includes/push_swap.h"

int		mid_point_a(t_stack *a, int n)
{
	int	i;
	int	arr[n];
	int	*new_arr;
	t_node	*tmp;

	i = 0;
	tmp = a->top;
	while (i < n)
	{
		arr[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	new_arr = letsSort(arr, n);
	return (new_arr[n / 2]);
}

int		a_to_b(t_stack *a, t_stack *b, int n)
{
//	int	*arr;
//	t_pivot	*new;
	int	i;
	int	mid;
	int	count;
	t_node	*tmp;

	i = 0;
	count = 0;
	mid = mid_point_a(a, n);
//	new = init_pivot();
//	arr = insertSort(a, n);
//	find_pivot2(arr, new, n);
	tmp = a->top;
	while (i < n)
	{
		if (tmp->value < mid)
			pb(a, b);
		else {
			ra(a);
			count++;
		}
		i++;
		tmp = a->top;
	}
	while (count-- > 0)
		rra(a);
	return (n / 2);
}

//last
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
		if (size > 2) {
			if (a->top->value < new->i_value) {
				pb(a, b);
		//		num_a--;
			}
			else {
				ra(a);
				count++;
//				num_a--;
			}
		}
		num_ch = num_a / 2;
		num_a = num_a / 2;
		if (num_ch > num_a)
			chunk_a_sorting(a, b, num_a);
			chunk_sorting(a, b, size-num_a);
		while (count-- > 0) {
			rra(a);
//			num_a++;
		}
	}
}
*/
