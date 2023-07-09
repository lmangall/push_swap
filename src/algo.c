#include "../include/push_swap.h"
#include "../lib/libft/src/libft.h"

int	find_minimum_idx(t_list *stack_a)
{
	t_list	*node;
	int		min_index;

	node = stack_a;
	min_index = 2147483646;
	while (node) /// try: 	while (node != NULL)
	{
		if (node->index < min_index)
			min_index = node->index;
		if (node->next == NULL)
			break ;
		node = node->next;
	}
	return (min_index);
}

static int	find_maximum_idx(t_list *stack)
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

int	algo(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*current_node;
	int		stack_a_size;
	int		stack_b_size;
	int		checked_bit;

	stack_a_size = lst_size(*stack_a);
	stack_b_size = 0;
	checked_bit = 0;
	current_node = *stack_a;
	if (stack_a_size <= 3)
	{
		sort_3(stack_a);
		exit_free("correct execution", stack_a);
	}
	if (stack_a_size == 5)
		sort_5(*stack_a, *stack_b);
	while (checked_bit < max_index_bits_nbr(stack_a))
	{
		i = 0;
		while (i < stack_a_size)
		{
			current_node = *stack_a;
			if (!is_bit_set(current_node->index, checked_bit))
				push(stack_a, stack_b, "pb");
			else
				rotate(stack_a, "ra");
			i++;
		}
		stack_b_size = lst_size(*stack_b);
		while (stack_b_size != 0)
		{
			push(stack_a, stack_b, "pa");
			stack_b_size--;
		}
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
}

void	sort_5(t_list *stack_a, t_list *stack_b)
{
	int	max;
	int	min;
	int	size;

	max = lst_size(stack_a) - 1;
	min = find_minimum_idx(stack_a);
	size = lst_size(stack_b);
	while (size < 2)
	{
		// if the head index is the minimum or maximum
		if (stack_a->index == min || stack_a->index == max)
			push(&stack_a, &stack_b, "pb");
		else
			rotate(&stack_a, "ra");
		min = find_minimum_idx(stack_a);
		size = lst_size(stack_b);
	}
	sort_3(&stack_a);
	push(&stack_a, &stack_b, "pa");
	push(&stack_a, &stack_b, "pa");
	if (is_sorted(stack_a))
		exit_free("correct execution", &stack_a);
	else
	{
		// if the head index is the maximum
		if (stack_a->index == max)
			rotate(&stack_a, "ra");
		else
		{
			swap(&stack_a, "sa");
			rotate(&stack_a, "ra");
		}
	}
	exit_free("correct execution", &stack_a);
}
