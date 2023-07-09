/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ini_assign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:12:07 by lmangall          #+#    #+#             */
/*   Updated: 2023/07/09 21:11:38 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../lib/libft/src/libft.h"

void	assign_index_by_value(t_list *stack, int node_nbr)
{
	t_list	*node;
	int		index;
	t_list	*min_node;
	int		min_value;

	index = 0;
	while (index < node_nbr)
	{
		min_value = 2147483647;
		min_node = NULL;
		node = stack;
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
			break ;
	}
}

void	stack_ini(t_list **stack_a, int argc, char **argv)
{
	int		i;
	t_list	*new_list;
	char	**args;

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		while (args[i])
		{
			new_list = ft_lstnew(ft_atoi(args[i]));
			ft_lstadd_back(stack_a, new_list);
			i++;
		}
		free_array(args);
	}
	else
	{
		while (i != argc - 1)
		{
			new_list = ft_lstnew(ft_atoi(argv[i + 1]));
			ft_lstadd_back(stack_a, new_list);
			i++;
		}
	}
}

void	print_list(const t_list *head)
{
	const t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit_free("correct execution", NULL);
	check_args(argc, argv, &stack_a);
	stack_ini(&stack_a, argc, argv);
	assign_index_by_value(stack_a, lst_size(stack_a));
	if (is_sorted(stack_a))
		exit_free("sorted", &stack_a);
	if (lst_size(stack_a) == 3)
		sort_3(&stack_a, "correct execution");
	if (lst_size(stack_a) == 5)
		sort_5(&stack_a, &stack_b, find_maximum_idx(stack_a), lst_size(stack_b));
	algo(&stack_a, &stack_b, lst_size(stack_a), lst_size(stack_b));
	exit_free("correct execution", &stack_a);
	return (0);
}
