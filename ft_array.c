/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:27:08 by lhelena           #+#    #+#             */
/*   Updated: 2022/02/23 15:08:56 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_write_array(int argc, char **argv, t_stack **stack_a)
{
	int	i;
	int	*array;

	array = (int *)malloc(sizeof(int) * (argc - 1));
	if (!array)
	{
		ft_node_clear_list(stack_a);
		ft_error_and_exit();
	}
	i = 1;
	while (i < argc)
	{
		array[i - 1] = ft_atoi_push_swap(argv[i]);
		i++;
	}
	return (array);
}

void	ft_sort_array(int argc, int *array)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < ((argc -1) - 1))
	{
		while (j < ((argc -1) - i - 1))
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
		j = 0;
	}
}
