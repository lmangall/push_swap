#include "../include/push_swap.h"
# include "../lib/libft/src/libft.h"

int swap(t_list **stack)
{
	t_list	*head;
	t_list	*scnd;
	int		value;
	int		index;

		if(lst_size(*stack) < 2)
			return (-1);
	value = 0;
	index = NO_IDX;
	head = *stack;
	scnd = head->next;
	// if head is null and next is null
	// 	throw an error "Error occurred while swapping!"
	value = head->value;
	index = head->index;
	head->value = scnd->value;
	head->index = scnd->index;
	scnd->value = value;
	scnd->index = index;
	ft_putendl_fd("swap", 1);
	return (0);
}

// int sa(t_list **stack_a)
// int sb(t_list **stack_b)
// int ss(t_list **stack_a, t_list **stack_b)
// int push(t_list **stack_to, t_list **stack_from)
// int pa(t_list **stack_a, t_list **stack_b)
// int pb(t_list **stack_a, t_list **stack_b)
// int rotate(t_list **stack)
// int ra(t_list **stack_a)
// int rb(t_list **stack_b)
// int rr(t_list **stack_a, t_list **stack_b)
// int reverseRotate(t_list **stack)
// int rra(t_list **stack_a)
// int rrb(t_list **stack_b)
// int rrr(t_list **stack_a, t_list **stack_b)
