/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:10:42 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/15 13:07:34 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_node_create(int set_data, int set_index)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = set_data;
	node->index = set_index;
	node->next = NULL;
	return (node);
}

void	ft_node_push_front(t_stack **list, int set_data, int set_index)
{
	t_stack	*new_node;

	new_node = ft_node_create(set_data, set_index);
	if (!new_node)
	{
		ft_node_clear_list(list);
		ft_error_and_exit();
	}
	new_node->next = *list;
	*list = new_node;
}

void	ft_node_push_back(t_stack **list, int set_data, int set_index)
{
	t_stack	*new_node;
	t_stack	*tmp;

	tmp = *list;
	new_node = ft_node_create(set_data, set_index);
	if (!new_node)
	{
		ft_node_clear_list(list);
		ft_error_and_exit();
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
}

void	ft_node_insert(t_stack **list, int set_data, int set_index)
{
	t_stack	*new_node;
	t_stack	*tmp;

	tmp = *list;
	new_node = ft_node_create(set_data, set_index);
	if (!new_node)
	{
		ft_node_clear_list(list);
		ft_error_and_exit();
	}
	new_node->next = tmp->next;
	tmp->next = new_node;
}

void	ft_node_clear_list(t_stack **list)
{
	t_stack	*tmp_clear;
	t_stack	*tmp_next;

	tmp_next = *list;
	while (tmp_next->next != NULL)
	{
		tmp_clear = tmp_next;
		tmp_next = tmp_next->next;
		free(tmp_clear);
	}
	free(tmp_next);
}
