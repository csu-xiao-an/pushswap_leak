#include "../includes/push_swap.h"

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
