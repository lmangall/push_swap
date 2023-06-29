#include "../include/push_swap.h"
# include "../lib/libft/src/libft.h"

int swap(t_list **stack, char *code)
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
    if (ft_strcmp(code, "sa") == 0)
        ft_putendl_fd("sa", 1);
    else if (ft_strcmp(code, "sb") == 0)
        ft_putendl_fd("sb", 1);
	return (0);
}

int ss(t_list **stack_a, t_list **stack_b)
{
	if(!(swap(stack_a, "ss")) || (!	swap(stack_b, "ss")))
		return(-1);
	ft_putendl_fd("ss", 1);
	return (0);
}

int push(t_list **stack_a, t_list **stack_b, char *code)
{
	t_list *node_cpy;
	t_list **stack_from;
	t_list **stack_to;

	stack_from = NULL;
	stack_to = NULL;
	if (ft_strcmp(code, "pb") == 0)
	{
		stack_from = stack_a;
		stack_to = stack_b;
		node_cpy = *stack_from;
		*stack_from = (*stack_from)->next;
	}
	if (ft_strcmp(code, "pa") == 0)
	{
		stack_from = stack_b;
		stack_to = stack_a;
		node_cpy = *stack_from;
		*stack_from = (*stack_from)->next;
	}
	if (!(*stack_to))
		ft_lstadd_front(stack_to, node_cpy);
	else
		ft_lstadd_back(stack_to, node_cpy);

		ft_putendl_fd(code, 1);
	return (0);
}
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
