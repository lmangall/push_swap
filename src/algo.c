/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:46:56 by lmangall          #+#    #+#             */
/*   Updated: 2023/07/09 18:24:17 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/libft/src/libft.h"

int	algo(t_list **stack_a, t_list **stack_b, int stack_a_size, int stack_b_size)
{
	int		i;
	t_list	*current_node;
	int		checked_bit;

	checked_bit = 0;
	current_node = *stack_a;
	while (checked_bit < max_index_bits_nbr(stack_a))
	{
		i = 0;
		while (i++ < stack_a_size)
		{
			current_node = *stack_a;
			if (!is_bit_set(current_node->index, checked_bit))
				push(stack_a, stack_b, "pb");
			else
				rotate(stack_a, "ra");
		}
		stack_b_size = lst_size(*stack_b);
		while (stack_b_size-- != 0)
			push(stack_a, stack_b, "pa");
		checked_bit++;
	}
	return (0);
}

int	find_position(t_list *stack_a, int index)
{
	t_list	*node;
	int		position;

	node = stack_a;
	position = 0;
	while (node != NULL)
	{
		if (node->index == index)
			return (position);
		position++;
		node = node->next;
	}
	return (-1);
}

void	sort_3(t_list **stack)
{
	int	size;

	size = lst_size(*stack) - 1;
	if (size == 1)
	{
		rotate(stack, "ra");
		exit_free("correct execution", stack);
	}
	if (find_position(*stack, find_minimum_idx(*stack)) == size)
	{
		if (find_maximum_idx(*stack) == (*stack)->index)
			swap(stack, "sa");
		reverse_rotate(stack, "rra");
	}
	else if (size == ft_lstlast(*stack)->index)
		swap(stack, "sa");
	else
	{
		if (find_minimum_idx(*stack) == (*stack)->index)
			swap(stack, "sa");
		rotate(stack, "ra");
	}
	exit_free("correct execution", stack);
}

void	sort_5(t_list *stack_a, t_list *stack_b, int max, int size)
{
	int	min;

	min = find_minimum_idx(stack_a);
	while (size < 2)
	{
		if (stack_a->index == min || stack_a->index == max)
			push(&stack_a, &stack_b, "pb");
		else
			rotate(&stack_a, "ra");
		size = lst_size(stack_b);
	}
	sort_3(&stack_a);
	push(&stack_a, &stack_b, "pa");
	push(&stack_a, &stack_b, "pa");
	if (is_sorted(stack_a))
		exit_free("correct execution", &stack_a);
	if (stack_a->index == max)
		rotate(&stack_a, "ra");
	else
	{
		swap(&stack_a, "sa");
		rotate(&stack_a, "ra");
	}
	exit_free("correct execution", &stack_a);
}
