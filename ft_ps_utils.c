/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:42:21 by lhelena           #+#    #+#             */
/*   Updated: 2022/02/23 15:17:12 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int	ft_elements_count(t_stack *list)
{
	int		i;
	t_stack	*tmp;

	tmp = list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_is_sorted(t_stack **list)
{
	t_stack	*tmp;

	if (ft_elements_count(*list) < 2)
		return (1);
	tmp = *list;
	while ((tmp->next->next) && (tmp->data < tmp->next->data))
		tmp = tmp->next;
	if (tmp->data < tmp->next->data)
		return (1);
	return (0);
}
