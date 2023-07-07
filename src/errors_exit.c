#include "../include/push_swap.h"

int is_sorted(t_list *stack)
{
	t_list *current_node;
	
	current_node = stack;
	while (current_node->next != NULL)
	{
		if (current_node->index > current_node->next->index)
			return 0;
		else
			current_node = current_node->next;
	}
	return 1;
}

void free_array(char **str)
{
    int i = 0;

    while (str[i])
    {
        free(str[i]);
        i++;
    }
	free(str);
}

void free_stack(t_list *stack) 
{
    t_list *current;
	t_list *tmp;
	
	current = stack;
    while (current != NULL) 
	{
        tmp = current;
        current = current->next;
        free(tmp);
    }
}

void exit_free(char *msg, t_list *stack_a, t_list *stack_b)
{
	if (ft_strcmp(msg, "correct execution") != 0)
	{
		ft_putstr_fd("Error:\n", 1);
		ft_putendl_fd(msg, 1);
	}
	if (ft_strcmp(msg, "Nothing to sort") == 0)
		exit(1);
	if (ft_strcmp(msg, "sorted") == 0)
	{
		free_stack(stack_a);
		exit(1);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	stack_a = NULL;
	stack_b = NULL;
	free(stack_a);
	free(stack_b);
	print_list(stack_a);
	printf("stacks are freed, or not ?");
	exit(1);
}


void check_duplicate(char **args)
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
			{
				free_array(args);
				exit_free("Duplicate among the arguments", NULL, NULL);
			}
			j++;
		}
		i++;
	}
}

char* check_int(char *arg)
{
	long long tmp;
	int i;

    i = 0;
    if (arg[0] == '-')
        i++;
    while (arg[i])
    {
        if (!ft_isdigit(arg[i]))
			return("Non authorized symbol among the arguments");
        i++;
    }
	//printf("str tmp = %s\n", arg);
	tmp = ft_atolli(arg);
	if (tmp < -2147483648 || tmp > 2147483647)
		return("Number exceeds int range");
	return("all good");
}
