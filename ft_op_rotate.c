/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:23:23 by lhelena           #+#    #+#             */
/*   Updated: 2022/02/23 15:11:26 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_op_rotate(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*down;

	tmp = *list;
	*list = (*list)->next;
	down = *list;
	while (down->next)
		down = down->next;
	down->next = tmp;
	down->next->next = NULL;
}

void	ft_op_ra(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;

	tmp = *list_b;
	if (ft_elements_count(*list_a) < 2)
		return ;
	ft_op_rotate(list_a);
	write(1, "ra\n", 3);
}

void	ft_op_rb(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;

	tmp = *list_a;
	if (ft_elements_count(*list_b) < 2)
		return ;
	ft_op_rotate(list_b);
	write(1, "rb\n", 3);
}

void	ft_op_rr(t_stack **list_a, t_stack **list_b)
{
	if (ft_elements_count(*list_a) > 1)
		ft_op_rotate(list_a);
	if (ft_elements_count(*list_b) > 1)
		ft_op_rotate(list_b);
	if ((ft_elements_count(*list_a) > 1) || (ft_elements_count(*list_b) > 1))
		write(1, "rr\n", 3);
}
