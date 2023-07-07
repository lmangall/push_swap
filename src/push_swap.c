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

static void free_array(char **str)
{
    int i = 0;

    while (str[i])
    {
        free(str[i]);
        i++;
    }
	free(str);
}

static void check_duplicate(char **args)
{
	int	i;
	int j;
	char *tmp;

	i = 0;
	j = 0;
	while(args[i])
	{
		tmp = args[i];
		j = i + 1;
		while (args[j])
		{
			// 	printf("  CHECK  \n");
			// printf("%s | %s\n", tmp, args[j]);
			if(!(ft_strcmp(tmp, args[j])))
				exit_free("Duplicate among the arguments", NULL, NULL);
			j++;
		}
		i++;
	}
}

void	stack_ini(t_list **stack, int argc, char **argv)
{
	int		i;
	t_list	*new_list;
	char	**args;
	char	*msg;

	i = 0;
	if (! stack)
		return ;
	 if (argc == 2)
		{
		args = ft_split(argv[1], ' ');
		check_duplicate(args);
		while (args[i])
		{
			msg = check_int(args[i]);
			if (ft_strcmp(msg, "all good") != 0)
				{
					free_array(args);
					exit_free(msg, NULL, NULL);
				}
			new_list = ft_lstnew(ft_atoi(args[i]));
			ft_lstadd_back(stack, new_list);
			i++;
		}
		free_array(args);
		}
	else
	{
		check_duplicate(argv + 1);
		while (i != argc - 1)
		{
			check_int(argv[i + 1]);
			new_list = ft_lstnew(ft_atoi(argv[i + 1]));
			ft_lstadd_back(stack, new_list);
			i++;
		}
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
	if(is_sorted(*stack_a))
		exit_free("sorted",*stack_a, *stack_b);
	algo(stack_a, stack_b);
	print_list(*stack_a);
	exit_free("allgood", *stack_a, *stack_b);
	return (0);
}
