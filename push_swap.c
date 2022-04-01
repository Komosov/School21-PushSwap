/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:08:44 by lhelena           #+#    #+#             */
/*   Updated: 2022/03/15 13:08:55 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_arg_check(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 0)
		{
			if (i != 0)
				ft_error_and_exit();
			else if ((arg[0] != '+') && (arg[0] != '-'))
				ft_error_and_exit();
		}
		i++;
	}
	if ((ft_atoi_push_swap(arg) == 0) && (arg[0] != 48))
		ft_error_and_exit();
}

static void	ft_is_dup(t_stack **stack_a)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *stack_a;
	while (tmp_a->next != NULL)
	{
		tmp_b = tmp_a;
		while (tmp_b->next != NULL)
		{
			tmp_b = tmp_b->next;
			if (tmp_a->data == tmp_b->data)
			{
				ft_node_clear_list(stack_a);
				ft_error_and_exit();
			}
		}
		tmp_a = tmp_a->next;
	}
}

static t_stack	*ft_check_and_make_stack(int argc, char **argv)
{
	int		i;
	t_stack	*tmp;

	if (argc == 1)
		exit (1);
	i = 1;
	while (i < argc)
		ft_arg_check(argv[i++]);
	tmp = ft_node_create(ft_atoi_push_swap(argv[1]), 0);
	i = 2;
	while (i < argc)
		ft_node_push_back(&tmp, ft_atoi_push_swap(argv[i++]), 0);
	ft_is_dup(&tmp);
	return (tmp);
}

static void	ft_write_index(int argc, int *array, t_stack **list)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *list;
	while (tmp)
	{
		while (i < (argc - 1))
		{
			if (tmp->data == array[i])
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
		i = 0;
	}
	free(array);
}

int	main(int argc, char **argv)
{
	int		*arr;
	t_stack	*stack_a;

	stack_a = ft_check_and_make_stack(argc, argv);
	if (ft_is_sorted(&stack_a))
	{
		ft_node_clear_list(&stack_a);
		return (0);
	}
	arr = ft_write_array(argc, argv, &stack_a);
	ft_sort_array(argc, arr);
	ft_write_index(argc, arr, &stack_a);
	ft_sort_stack(argc, &stack_a);
	ft_node_clear_list(&stack_a);
	return (0);
}
