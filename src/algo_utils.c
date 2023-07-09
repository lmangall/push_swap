/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:54:39 by lmangall          #+#    #+#             */
/*   Updated: 2023/07/09 22:42:34 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*current_node;

	current_node = stack;
	while (current_node->next != NULL)
	{
		if (current_node->index > current_node->next->index)
			return (0);
		else
			current_node = current_node->next;
	}
	return (1);
}

int	find_min_idx(t_list *stack_a)
{
	t_list	*node;
	int		min_index;

	node = stack_a;
	min_index = 2147483646;
	while (node)
	{
		if (node->index < min_index)
			min_index = node->index;
		if (node->next == NULL)
			break ;
		node = node->next;
	}
	return (min_index);
}

int	find_max_idx(t_list *stack)
{
	t_list	*node;
	int		max_index;

	node = stack;
	max_index = 0;
	while (node)
	{
		if (node->index > max_index)
			max_index = node->index;
		if (node->next == NULL)
			break ;
		node = node->next;
	}
	return (max_index);
}

int	is_bit_set(int num, int bit)
{
	int	shifted;
	int	result;

	shifted = num >> bit;
	result = shifted & 1;
	return (result);
}

int	max_index_bits_nbr(t_list **stack_a)
{
	int	idx;
	int	bits_nbr;

	bits_nbr = 0;
	idx = lst_size(*stack_a) - 1;
	while ((idx >> bits_nbr) != 0)
		bits_nbr++;
	return (bits_nbr);
}
