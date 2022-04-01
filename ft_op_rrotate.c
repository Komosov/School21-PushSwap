/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:24:18 by lhelena           #+#    #+#             */
/*   Updated: 2022/02/23 15:12:05 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_op_rrotate(t_stack **list)
{
	t_stack	*up;
	t_stack	*tmp;
	t_stack	*penultimate;

	tmp = *list;
	penultimate = *list;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	up = penultimate->next;
	penultimate->next = NULL;
	up->next = tmp;
	*list = up;
}

void	ft_op_rra(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;

	tmp = *list_b;
	if (ft_elements_count(*list_a) < 2)
		return ;
	ft_op_rrotate(list_a);
	write(1, "rra\n", 4);
}

void	ft_op_rrb(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;

	tmp = *list_a;
	if (ft_elements_count(*list_b) < 2)
		return ;
	ft_op_rrotate(list_b);
	write(1, "rrb\n", 4);
}

void	ft_op_rrr(t_stack **list_a, t_stack **list_b)
{
	if (ft_elements_count(*list_a) > 1)
		ft_op_rrotate(list_a);
	if (ft_elements_count(*list_b) > 1)
		ft_op_rrotate(list_b);
	if ((ft_elements_count(*list_a) > 1) || (ft_elements_count(*list_b) > 1))
		write(1, "rrr\n", 4);
}
