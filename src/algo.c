/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:46:56 by lmangall          #+#    #+#             */
/*   Updated: 2023/07/09 22:31:56 by lmangall         ###   ########.fr       */
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

int	sort_3(t_list **stack, char *msg)
{
	int	size;
printf("Address of stack_a (S3): %p\n", (void*)stack);

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
	else if (size == find_minimum_idx(*stack))
{
		swap(stack, "sa");
		printf("Address of stack_a (XXX): %p\n", (void*)stack);
}
	else
	{
		if (find_minimum_idx(*stack) == (*stack)->index)
			swap(stack, "sa");
		rotate(stack, "ra");
	}
	if (ft_strcmp(msg, "correct execution") == 0)
		exit_free(msg, stack);
	return (0);
}

void	sort_5(t_list **stack_a, t_list **stack_b, int max, int size_b)
{
	int	min;
printf("Address of stack_a (0): %p\n", (void*)stack_a);

		min = find_minimum_idx(*stack_a);
	while (size_b < 2)
	{
		printf("size = %d\n", size_b);
		printf("min = %d\n", min);
		printf("max = %d\n", max);
		printf("stack_a->index = %d\n", (*stack_a)->index);
		if ((*stack_a)->index == min || (*stack_a)->index == max)
			push(stack_a, stack_b, "pb");
		else
			rotate(stack_a, "ra");
		size_b = lst_size(*stack_b);
	}
	if (is_sorted(*stack_a) != 1)
		sort_3(stack_a, "come back");
	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
	if (is_sorted(*stack_a))
		exit_free("correct execution", stack_a);
	if ((*stack_a)->index == max)
		rotate(stack_a, "ra");
	else
	{
		swap(stack_a, "sa");
		rotate(stack_a, "ra");
	}
	exit_free("correct execution", stack_a);
}
