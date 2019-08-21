/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:42:13 by minakim           #+#    #+#             */
/*   Updated: 2019/08/20 20:17:58 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(struct s_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}

int	isInt(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	struct s_stack	*a;
	struct s_stack	*b;

	a = initstack();
	b = initstack();
	if (ac >= 2)
	{
		int	i;

		i = ac - 1;
		while (av[i] && i != 0)
		{
			if (isInt(av[i]) == 1) {
				ft_printf("ERROR\n");
				exit(0);
			}
			push(a, ft_atoi(av[i]));
			i--;
		}
	}
	if (is_sorted(a) != 1)
		return (0);
//	push_swap(a);
	push_swap(a, b);
//	magic(a);
//	print_stack(a);
////	print_stack(b);
//	magic(a, b);
//	ft_printf("b stack\n");
//	print_stack(b);
//	ft_printf("a stack\n");
//	print_stack(a);
//   free(a);
//   free(b);
	return (0);
}
