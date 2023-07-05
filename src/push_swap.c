#include "../include/push_swap.h"


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

void	stack_ini(t_list **stack, int argc, char **argv)
{
	int		i;
	t_list	*new_list;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	while (args[i])
	{
		check_int(args[i]);
		new_list = ft_lstnew(atoi(args[i]));
		ft_lstadd_back(stack, new_list);
		i++;

		//SHOULD I FREE THIS STRING (args)
	}
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		exit_free("Nothing to sort", NULL, NULL);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	stack_ini(stack_a, argc, argv);
	assign_index_by_value(*stack_a);
	algo(stack_a, stack_b);
	// print_list(*stack_a);
	exit_free("allgood", *stack_a, *stack_b);
	return (0);
}
