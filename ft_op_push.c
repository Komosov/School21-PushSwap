/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:22:50 by lhelena           #+#    #+#             */
/*   Updated: 2022/02/23 15:11:30 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_op_pa(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;

	if (*list_b == NULL)
		return ;
	tmp = *list_b;
	*list_b = (*list_b)->next;
	tmp->next = *list_a;
	*list_a = tmp;
	write(1, "pa\n", 3);
}

void	ft_op_pb(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;

	if (*list_a == NULL)
		return ;
	tmp = *list_a;
	*list_a = (*list_a)->next;
	tmp->next = *list_b;
	*list_b = tmp;
	write(1, "pb\n", 3);
}
