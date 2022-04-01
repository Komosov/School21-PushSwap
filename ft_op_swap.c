/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:19:24 by lhelena           #+#    #+#             */
/*   Updated: 2022/02/23 15:12:36 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_op_swap(t_stack **list)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *list;
	tmp_b = (*list)->next;
	tmp_a->next = (*list)->next->next;
	tmp_b->next = tmp_a;
	*list = tmp_b;
}

void	ft_op_sa(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;

	tmp = *list_b;
	if (ft_elements_count(*list_a) < 2)
		return ;
	ft_op_swap(list_a);
	write(1, "sa\n", 3);
}

void	ft_op_sb(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;

	tmp = *list_a;
	if (ft_elements_count(*list_b) < 2)
		return ;
	ft_op_swap(list_b);
	write(1, "sb\n", 3);
}

void	ft_op_ss(t_stack **list_a, t_stack **list_b)
{
	if (ft_elements_count(*list_a) > 1)
		ft_op_swap(list_a);
	if (ft_elements_count(*list_b) > 1)
		ft_op_swap(list_b);
	if ((ft_elements_count(*list_a) > 1) || (ft_elements_count(*list_b) > 1))
		write(1, "ss\n", 3);
}
