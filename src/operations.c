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

int	rotate(t_list **stack, char *code)
{
	t_list	*head;
	t_list	*tail;

	if (lst_size(*stack) < 2)
		return (-1);

	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;

	if (ft_strstr(code, "ra") || ft_strstr(code, "rb"))
	// if ((ft_strcmp(code, "ra") == 0) || (ft_strcmp(code, "rb") == 0))
		ft_putendl_fd(code, 1);

	return (0);
}

int rr(t_list **stack_a, t_list **stack_b)
{
	if ((lst_size(*stack_a) < 2) || (lst_size(*stack_b) < 2))
		return (-1);
	rotate(stack_a, "no msg");
	rotate(stack_b, "no msg");
	ft_putendl_fd("rr", 1);
	return(0);
}

int	reverse_rotate(t_list **stack, char *code)
{
	t_list	*head;
	t_list	*tail;
	t_list	*prev_tail;

	if (lst_size(*stack) < 2)
		return (-1);

	head = *stack;
	tail = ft_lstlast(head);
	prev_tail = ft_lstprev(*stack, tail);
	prev_tail->next = NULL;
	tail->next = head;
	*stack = tail;

	if (ft_strstr(code, "rra") || ft_strstr(code, "rrb"))
	// if((ft_strcmp(code, "rra") == 0) || (ft_strcmp(code, "rrb") == 0))
		ft_putendl_fd(code, 1);

	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((lst_size(*stack_a) < 2) || (lst_size(*stack_b) < 2))
		return (-1);
	reverse_rotate(stack_a, "no msg");
	reverse_rotate(stack_b, "no msg");
	ft_putendl_fd("rrr", 1);
	return(0);
}

int is_bit_set(int num, int bit)
{
	int shifted;
	int	result;

	shifted = num >> bit;
	result = shifted & 1;
	return (result);
}

static int	bits_of_biggest_index(t_list **stack_a)
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
	t_list	*current;
	int i;
	int j = 0;
	int checked_bit = 0;
	int size;
	int bits_nbr;

	bits_nbr = bits_of_biggest_index(stack_a);

	printf("\nbits_nbr:%d\n", bits_nbr);


	i = 0;
	size = 1;
	printf("\nsize:%d\n", size);
	current = *stack_a;
	while (checked_bit < bits_nbr)
	{
		while(j++ <= size)
		{
			size = lst_size(*stack_a);
			while(i++ < size)
			{
				// printf("\n             i:%d\n", i);
				// printf("current->index:%d\n", current->index);
				if(is_bit_set(current->index, checked_bit) == 1)
					push(stack_a, stack_b, "pb");
				else
					rotate(stack_a, "ra");
				current = *stack_a;
			}
			size = lst_size(*stack_b);
			push(stack_a, stack_b, "pa");
		}
		checked_bit++;
		j = 0;
		i = 0;
	}


	return (0);
}

