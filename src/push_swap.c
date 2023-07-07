#include "../include/push_swap.h"

// void print_list(const t_list *head)
// {
// 	const t_list	*tmp;

// 	tmp = head;
// 	while (tmp != NULL)
// 	{
// 		ft_putnbr_fd(tmp->value, 1);
// 		ft_putendl_fd("", 1);
// 		tmp = tmp->next;
// 	}
// }


void	stack_ini(t_list **stack_a, t_list **stack_b, int argc, char **argv)
{
	int		i;
	t_list	*new_list;
	char	**args;
	char	*msg;

	i = 0;
	if (! stack_a)
		return ;
	if (argc == 2)
		{
		args = ft_split(argv[1], ' ');
		while (args[i])
		{
			msg = check_int(args[i]);
			if (ft_strcmp(msg, "all good") != 0)
				{
					free_array(args);
					exit_free(msg, *stack_a, *stack_b);
				}
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
			msg = check_int(argv[i + 1]);
			if (ft_strcmp(msg, "all good") != 0)
				{
					free_array(argv);
					exit_free(msg, *stack_a, *stack_b);
				}			
			new_list = ft_lstnew(ft_atoi(argv[i + 1]));
			ft_lstadd_back(stack_a, new_list);
			i++;
		}
	}
}

// static void free_stack_d(t_list **stack)
// {
//     t_list *current;
//     t_list *next;

//     current = *stack; // Assign the value of stack pointer to current
//     while (current != NULL)
//     {
//         next = current->next;
//         free(current);
//         current = next;
//     }

//     *stack = NULL; // Set the stack pointer to NULL after freeing all nodes
// }


void print_list(const t_list *head)
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
	t_list	**stack_a;
	t_list	**stack_b;	
	char 	**args;

	if (argc < 2)
		exit_free("Nothing to sort", NULL, NULL);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
	 	check_duplicate(args);
		// printf("\n\nMAIN\n\n");
		free_array(args);
	}
	if (argc > 2)
		check_duplicate(argv + 1);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	stack_ini(stack_a, stack_b, argc, argv);
	assign_index_by_value(*stack_a);
	if(is_sorted(*stack_a))
		exit_free("sorted",*stack_a, *stack_b);
	algo(stack_a, stack_b);
	// print_list(*stack_a);
	// free_stack_d(stack_a);
	// free_stack_d(stack_b);
	exit_free("correct execution", *stack_a, *stack_b);
	return (0);
}
