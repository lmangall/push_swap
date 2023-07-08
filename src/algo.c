#include "../include/push_swap.h"
#include "../lib/libft/src/libft.h"

t_list	*find_minimum_node(t_list *stack_a)
{
	t_list *node;
	t_list *min_node;
	int min_value;

	min_value = 2147483647; // Initialize min_value to MAX_INT
	// min_node = NULL; // Initialize min_node to NULL
	node = stack_a; // Start from the first node
	while (node->next != NULL)
	{
		if (node->index < min_value)
		{
			min_value = node->index;
			min_node = node;
		}
		node = node->next;
		// printf("\nindex = %i\nvalue = %i\nmin_value = %i\n", node->index, node->value, min_value);
	}
	return(min_node);
}

int	find_minimum_idx(t_list *stack_a)
{
	t_list *node;
	int min_index;

	node = stack_a;
	min_index = 0;
	while(node->next != NULL)
	{
		if (node->index < min_index)
			min_index = node->index;
		node = node->next;
	}
	return(min_index);
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

int algo(t_list **stack_a, t_list **stack_b)
{
	int i;
	int j;
	t_list *current_node;
	int stack_a_size;
	int stack_b_size;
	int checked_bit;

	stack_a_size = lst_size(*stack_a);
	stack_b_size = 0;
	checked_bit = 0;
	current_node = *stack_a;
	if(stack_a_size <= 3)
		small_algo(*stack_a);
	while (checked_bit < max_index_bits_nbr(stack_a))
	{
		i = 0;
		j = 0;
		while (j < stack_a_size - i)
		{
			i = 0;
			while (i < stack_a_size)
			{
				if (is_bit_set(current_node->index, checked_bit))
					push(stack_a, stack_b, "pb");
				else
					rotate(stack_a, "ra");
				current_node = *stack_a;
				i++;
			}
			j++;
			stack_b_size = lst_size(*stack_b);
			while (stack_b_size-- > 0)
				push(stack_a, stack_b, "pa");
		}
		checked_bit++;
	}
	return (0);
}

/**
 * @brief Finds the position of a node with a given index in a linked list.
 *
 * This function searches for a node with the specified index in the linked list
 * starting from the given stack_a node. It returns the position of the node if found,
 * otherwise -1 is returned.
 *
 * @param stack_a The pointer to the head of the linked list.
 * @param index   The index value to search for.
 * @return        The position of the node if found, -1 otherwise.
 */
static int	find_position(t_list *stack_a, int index)
{
	// printf("current index  |  index searched  |  position");
	t_list *node;
	int	position;

	node = stack_a;
	position = 0;
	while (node != NULL)
	{
		// printf("\n%i | %i | %i\n", node->index, index, position);
		if (node->index == index)
			return(position);
		position++;
		node = node->next;
	}
	return(-1);
}





int small_algo(t_list *stack)
{
	int size;
	
	size = lst_size(stack) - 1;
	if(size == 1)
	{
		rotate(&stack, "ra");
		exit_free("correct execution", &stack);
	}
	// If the minimum index is at the bottom of the stack (231,321)
	if (find_position(stack, find_minimum_idx(stack)) == size)
	{
			//if maximium is on top
		if(size == stack->index)
			swap(&stack, "sa");
		reverse_rotate(&stack, "rra");

	}
	// If the maximum index is at the bottom of the stack (213)(cannot be 123)
	else if (size == ft_lstlast(stack)->index)
		swap(&stack, "sa");
	// If neither the minimum nor the maximum index are at the bottom of the stack (312,132)
	else //if (find_position(stack, find_minimum_idx(stack)) == 2)
	{
		if (find_minimum_idx(stack) == stack->index)
			swap(&stack, "sa");
		rotate(&stack, "ra");
	}

	print_list(stack);
	exit_free("correct execution", &stack);
	return 0;
}


// int	sort_5(t_list *stack)
