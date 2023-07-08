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


// int	small_algo(t_list *stack)
// {
// 	// int	min_index;
// 	// int	proximity;

// 	// proximity = 0;
// 	// min_index = 0;
// 	// t_list *tmp = find_minimum(stack_a);
// 	// min_index = tmp->index;
// 	// proximity = lst_size(stack) / 2;
// 	// if (proximity > min_index)
// 	// 	rotate(stack_a, "ra");
// 	// else
// 	// 	reverse_rotate(stack_a, "rra");

// 	// If the minimum value is equal to the value of the top element
// 	if (find_minimum_idx(stack) == stack->index)
// 	{
// 		printf("minimum value is equal to the value of the top element");
// 		reverse_rotate(&stack, "rra");
// 		swap(&stack, "sa");
// 	}
// 	//If the maximum value is equal to the value of the top element 
// 	else if (lst_size(stack) == stack->index)
// 	{
// 		printf("maximum value is equal to the value of the top element");
// 		rotate(&stack, "rra");
// 		if (!(is_sorted(stack)))
// 			swap(&stack, "sa");
// 	}
// 	//If neither the mini nor the max value the top element
// 	else
// 	{
// 		printf("neither the mini nor the max value the top element");
// 		//if the maximum value is located at index 1 (second element) 
// 		if (find_position(stack, lst_size(stack)) == 1)
// 			reverse_rotate(&stack, "rra");
// 		else
// 			swap(&stack, "sa");
// 	}
// 	exit_free("correct execution", &stack);
// 	return(0);
// }


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



// Combination 6: (3, 2, 1) 
// Combination 4: (2, 3, 1)
// sa if max on top then rra

// Combination 1: (1, 2, 3) sorted: problem already exited
// Combination 3: (2, 1, 3)
// sa

// Combination 2: (1, 3, 2)
// Combination 5: (3, 1, 2) 
// sa if min on top then ra


int small_algo(t_list *stack)
{
	int size = lst_size(stack) - 1;/////CHECK THIS
		printf("\nsize = %i\n", size);

// printf("\nposition de index 0 (1) = %i\n", find_position(stack, 0));
// printf("\nposition de index 1 (2)= %i\n", find_position(stack, 1));
// printf("\nposition de index 2 (3)= %i\n", find_position(stack, 2));
// printf("\n\nfind_minimum_idx(stack) = %i\n", find_minimum_idx(stack));

//index goes from 0 to 2

	// If the minimum index is at the bottom of the stack (231,321)
	if (find_position(stack, find_minimum_idx(stack)) == size)
	{
		// printf("\nIf the minimum index is at the bottom of the stack (231,321)\n");
		// printf("\nstack->index = %i\n", stack->index);
		// printf("\nfind_position(stack, size) = %i\n", find_position(stack, size));
		// printf("\n%i = %i\n", size, stack->index);
			//if maximium is on top
		if(size == stack->index)
			swap(&stack, "sa");
		reverse_rotate(&stack, "rra");

	}
	// If the maximum index is at the bottom of the stack (213)(cannot be 123)
	else if (size == ft_lstlast(stack)->index)
	{
		printf("If the maximum index is at the bottom of the stack ");
		swap(&stack, "sa");
	}
	// If neither the minimum nor the maximum index are at the bottom of the stack (312,132)
	else //if (find_position(stack, find_minimum_idx(stack)) == 2)
	{
		// printf("If neither the minimum nor the maximum index are at the bottom of the stack");
		// printf("\n%i = %i\n", size, stack->index);
		//if minimium is on top
		if (find_minimum_idx(stack) == stack->index)
			swap(&stack, "sa");
		rotate(&stack, "ra");
	}

	print_list(stack);
	exit_free("correct execution", &stack);
	return 0;
}


