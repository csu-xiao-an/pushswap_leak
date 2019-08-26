#include "../includes/push_swap.h"

void	check_3_mid(t_stack *s, t_struct *nbr, int n)
{
	t_node	*tmp;
	int		mid;

	tmp = s->top;
	mid = tmp->value;
	for (int i = 0; i < n; i++) {
		if (tmp->value != nbr->min && tmp->value != nbr->max)
			mid = tmp->value;
		tmp = tmp->next;
	}
	nbr->mid = mid;
}

void	check_b_3(t_stack *s, t_struct *nbr, int n)
{
	t_node	*tmp;
	int	max;
	int	min;

	tmp = s->top;
	max = 0;
	min = tmp->value;
	for (int i = 0; i < n; i++) {
		if (tmp->value > max)
			max = tmp->value;
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	nbr->min = min;
	nbr->max = max;
	check_3_mid(s, nbr, n);
}

void	sort_3(t_stack *s, int n)
{
	t_struct	*nbr;

	nbr = init_nbr();
	check_b_3(s, nbr, n);
	if (s->top->value == nbr->max && s->top->next->value == nbr->min)
	{
		rrb(s);
		sb(s);
	}
	else if (s->top->value == nbr->mid) {
		if (s->top->next->value == nbr->max)
			sb(s);
		else
			rrb(s);
	}
	else if (s->top->value == nbr->min) {
		if (s->top->next->value == nbr->mid) {
			sb(s);
			rrb(s);
		}
		else
			rb(s);
	}
	free(nbr);
}


void	super_fast(t_stack *a, t_stack *b, int n)
{
	int	i;
	t_struct	*nbr;

	i = 0;
	nbr = init_nbr();
	if (n == 3)
		sort_3(b, n);
	else {
		pa(a, b);
		pa(a, b);
		sort_3(b, n);
		check_b_3(b, nbr, 3);
		while (n-- > 3) {
			if (a->top->value >= b->top->value)
				pb(a, b);
			else if (a->top->value <= nbr->min) {
				pb(a, b);
				rb(b);
			}
			else if (a->top->value > nbr->min && a->top->value <= b->top->next->value) {
				if (n == 5) {
					pb(a, b);
					rrb(b);
					sb(b);
					rb(b);
					rb(b);
				}
				else {
					if (a->top->value < b->top->next->next->value) {
						pb(a, b);
						rrb(b);
						sb(b);
						rb(b);
						rb(b);
					}
					else {
						rrb(b);
						rrb(b);
						rrb(b);
						pb(a, b);
						rb(b);
						rb(b);
						rb(b);
					}
				}
			}
			else if (a->top->value < b->top->value && a->top->value > b->top->next->value) {
				pb(a, b);
				sb(b);
			}
		}
	}
}
