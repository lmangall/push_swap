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

 void check_int(char *arg)
{
    int i;
    int is_negative;
	size_t max_length;

    i = 0;
    is_negative = 0;
    if (arg[i] == '-')
    {
        is_negative = 1;
        i++;
    }

    max_length = (is_negative) * 11 + (!is_negative) * 10;
    if (ft_strlen(arg) > max_length)
        exit_free("Number exceeds int range", NULL, NULL);

    while (arg[i])
    {
        if (!ft_isdigit(arg[i]))
            exit_free("Not a number", NULL, NULL);
        i++;
    }

    int is_exceed_range = 0;
    if (is_negative)
    {
        if (strlen(arg) == 11 && strcmp(arg, "2147483648") > 0)
            is_exceed_range = 1;
    }
    else
    {
        if (strlen(arg) == 10 && strcmp(arg, "2147483647") > 0)
            is_exceed_range = 1;
    }

    if (is_exceed_range)
        exit_free("Number exceeds int range", NULL, NULL);
}

void	stack_ini(t_list **stack, int argc, char **argv)
{
	int		i;
	t_list	*new_list;

	i = 1;
	while (i < argc)
	{
		check_int(argv[i]); // Validate the integer before adding it to the stack
		new_list = ft_lstnew(atoi(argv[i]));
		ft_lstadd_back(stack, new_list);
		i++;
	}
}


int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	//  The reason for using double pointers
	// is to allow modifications to the original pointers within a function.
	if (argc < 2)
		exit_free("Nothing to sort", NULL, NULL);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	// NULL signifies the end of the list. => those are empty
	*stack_a = NULL;
	*stack_b = NULL;
	stack_ini(stack_a, argc, argv);
	assign_index_by_value(*stack_a);
	algo(stack_a, stack_b);
	print_list(*stack_a);
	exit_free("allgood", *stack_a, *stack_b);
	return (0);
}
