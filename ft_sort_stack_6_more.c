/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_6_more.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:11:36 by lhelena           #+#    #+#             */
/*   Updated: 2022/02/20 20:33:04 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fw_what_place(t_stack **s_b, int i)
{
	int		j;
	t_stack	*tmp;

	j = 0;
	tmp = *s_b;
	while ((tmp) && (tmp->index != i))
	{
		tmp = tmp->next;
		j++;
	}
	return (j);
}

static void	ft_sorting_b(t_stack **s_a, t_stack **s_b, int argc)
{
	int	half;
	int	max_i;
	int	place;

	max_i = argc - 2;
	while (*s_b)
	{
		half = (max_i + 1) / 2;
		place = fw_what_place(s_b, max_i);
		if ((*s_b)->index == max_i)
		{
			ft_op_pa(s_a, s_b);
			max_i--;
		}
		else if (place > half && (*s_b)->index != max_i)
			ft_op_rrb(s_a, s_b);
		else if (place <= half && (*s_b)->index != max_i)
			ft_op_rb(s_a, s_b);
	}
}

void	ft_sorting_6_100(int argc, t_stack **s_a, t_stack **s_b)
{
	int	i;

	i = 0;
	while (*s_a)
	{
		if ((*s_a)->index <= i && i > 1)
		{
			ft_op_pb(s_a, s_b);
			ft_op_rb(s_a, s_b);
			i++;
		}
		else if ((*s_a)->index <= (i + 15))
		{
			ft_op_pb(s_a, s_b);
			i++;
		}
		else if ((*s_a)->index >= i)
			ft_op_ra(s_a, s_b);
	}
	ft_sorting_b(s_a, s_b, argc);
}

void	ft_sorting_101_more(int argc, t_stack **s_a, t_stack **s_b)
{
	int	i;

	i = 0;
	while (*s_a)
	{
		if ((*s_a)->index <= i && i > 1)
		{
			ft_op_pb(s_a, s_b);
			ft_op_rb(s_a, s_b);
			i++;
		}
		else if ((*s_a)->index <= (i + 30))
		{
			ft_op_pb(s_a, s_b);
			i++;
		}
		else if ((*s_a)->index >= i)
			ft_op_ra(s_a, s_b);
	}
	ft_sorting_b(s_a, s_b, argc);
}
