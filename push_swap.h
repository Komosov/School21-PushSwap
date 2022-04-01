/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:12:22 by lhelena           #+#    #+#             */
/*   Updated: 2022/02/23 15:20:01 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		ft_atoi_push_swap(const char *str);
int		ft_elements_count(t_stack *list);
void	ft_error_and_exit(void);
int		ft_is_sorted(t_stack **list);
void	ft_node_clear_list(t_stack **list);
t_stack	*ft_node_create(int set_data, int set_index);
void	ft_node_insert(t_stack **list, int set_data, int set_index);
void	ft_node_push_back(t_stack **list, int set_data, int set_index);
void	ft_node_push_front(t_stack **list, int set_data, int set_index);
void	ft_op_pa(t_stack **list_a, t_stack **list_b);
void	ft_op_pb(t_stack **list_a, t_stack **list_b);
void	ft_op_ra(t_stack **list_a, t_stack **list_b);
void	ft_op_rb(t_stack **list_a, t_stack **list_b);
void	ft_op_rr(t_stack **list_a, t_stack **list_b);
void	ft_op_rra(t_stack **list_a, t_stack **list_b);
void	ft_op_rrb(t_stack **list_a, t_stack **list_b);
void	ft_op_rrr(t_stack **list_a, t_stack **list_b);
void	ft_op_sa(t_stack **list_a, t_stack **list_b);
void	ft_op_sb(t_stack **list_a, t_stack **list_b);
void	ft_op_ss(t_stack **list_a, t_stack **list_b);
void	ft_sort_array(int argc, int *array);
void	ft_sort_stack(int argc, t_stack **stack_a);
void	ft_sorting_101_more(int argc, t_stack **s_a, t_stack **s_b);
void	ft_sorting_6_100(int argc, t_stack **s_a, t_stack **s_b);
int		*ft_write_array(int argc, char **argv, t_stack **stack_a);

#endif
