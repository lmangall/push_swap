/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:23:59 by lmangall          #+#    #+#             */
/*   Updated: 2023/07/09 20:48:16 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/libft/src/libft.h"

int	swap(t_list **stack, char *code)
{
	t_list	*head;
	t_list	*scnd;
	int		value;
	int		index;

	if (lst_size(*stack) < 2)
		return (-1);
	value = 0;
	index = NO_IDX;
	head = *stack;
	scnd = head->next;
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

int	push(t_list **stack_a, t_list **stack_b, char *code)
{
	t_list	*node_cpy;
	t_list	**stack_from;
	t_list	**stack_to;

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
	ft_lstadd_front(stack_to, node_cpy);
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
		ft_putendl_fd(code, 1);
	return (0);
}

int	reverse_rotate(t_list **stack, char *code)
{
	t_list	*head;
	t_list	*tail;

	head = *stack;
	tail = ft_lstlast(head);
	if (lst_size(*stack) < 2)
		return (-1);
	while (head->next != tail)
		head = head->next;
	head->next = NULL;
	tail->next = *stack;
	*stack = tail;
	if (ft_strstr(code, "rra") || ft_strstr(code, "rrb"))
		ft_putendl_fd(code, 1);
	return (0);
}
