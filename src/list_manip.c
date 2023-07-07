#include "../include/push_swap.h"

void	ft_lstadd_front(t_list **stack, t_list *new)
{
	new->next = *stack;
	*stack = new;
}

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*n;

	if (*stack)
	{
		n = ft_lstlast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL; // why parenthesis ?
	}
}

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));//sizeof (t_list) ??
	if (!new)
		return (NULL);
	new->value = value;
	new->index = NO_IDX;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (tmp == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_list	*ft_lstprev(t_list **lst, t_list *current)
{
	t_list	*prev;

	prev = NULL;
	while (lst && lst != &current)
	{
		prev = *lst;
		*lst = (*lst)->next;//why parenthesis
	}
	return (prev);
}

int	lst_size(t_list *head)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void assign_index_by_value(t_list *stack)
{
	t_list *node;
	int index;
	int node_nbr;
	t_list *min_node;

	node_nbr = lst_size(stack);
	index = 0;
	while (index < node_nbr)//instead of this I could use 'while(node->next != NULL) 7 lines below ?
		{
		int min_value = 2147483647; // Initialize min_value to MAX_INT
		min_node = NULL; // Initialize min_node to NULL
		node = stack; // Start from the first node
		// Find the node with the minimum value
		while (node != NULL)
		{
			if (node->index == NO_IDX && node->value < min_value)
			{
				min_value = node->value;
				min_node = node;
			}
			node = node->next;
		}
		if (min_node != NULL)
			min_node->index = index++;
		else
			break; // Break the loop if no node is found or all nodes have been assigned an index
	}
}
