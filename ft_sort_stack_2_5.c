/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_2_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:23:52 by lhelena           #+#    #+#             */
/*   Updated: 2022/02/20 18:13:24 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sorting_3(t_stack **s_a, t_stack **s_b)
{
	int	a;
	int	b;
	int	c;

	a = (*s_a)->data;
	b = (*s_a)->next->data;
	c = (*s_a)->next->next->data;
	if (a > b && c > b && c > a)
		ft_op_sa(s_a, s_b);
	else if (a > b && c > b && a > c)
		ft_op_ra(s_a, s_b);
	else if (b > a && b > c && a > c)
		ft_op_rra(s_a, s_b);
	else if (a > b && b > c && a > c)
	{
		ft_op_sa(s_a, s_b);
		ft_op_rra(s_a, s_b);
	}
	else if (b > a && b > c && c > a)
	{
		ft_op_sa(s_a, s_b);
		ft_op_ra(s_a, s_b);
	}
}

static void	ft_sorting_4_5(int argc, t_stack **s_a, t_stack **s_b)
{
	while (ft_elements_count(*s_a) > 3)
	{
		if (((*s_a)->index == 0) || ((*s_a)->index == argc - 2))
			ft_op_pb(s_a, s_b);
		if (((*s_a)->index != 0) && ((*s_a)->index != argc - 2))
			ft_op_ra(s_a, s_b);
	}
	ft_sorting_3(s_a, s_b);
	while (ft_elements_count(*s_b) > 0)
	{
		if ((*s_b)->index == 0)
			ft_op_pa(s_a, s_b);
		else
		{
			ft_op_pa(s_a, s_b);
			ft_op_ra(s_a, s_b);
		}
	}
}

void	ft_sort_stack(int argc, t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc == 3)
		ft_op_sa(stack_a, &stack_b);
	else if (argc == 4)
		ft_sorting_3(stack_a, &stack_b);
	else if (argc <= 6)
		ft_sorting_4_5(argc, stack_a, &stack_b);
	else if (argc >= 7 && argc <= 101)
		ft_sorting_6_100(argc, stack_a, &stack_b);
	else
		ft_sorting_101_more(argc, stack_a, &stack_b);
}
