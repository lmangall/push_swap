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
	if (ft_strcmp(msg, "allgood") != 0)
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
	printf("stacks are freed, or not ?");
	exit(1);
}

void check_int(char *arg)
{
	long long tmp;
	int i;

    i = 0;
    if (arg[0] == '-')
        i++;
    while (arg[i])
    {
        if (!ft_isdigit(arg[i]))
			exit_free("Non authorized symbol among the arguments", NULL, NULL);
        i++;
    }
	//printf("str tmp = %s\n", arg);
	tmp = ft_atolli(arg);
		if (tmp < -2147483648 || tmp > 2147483647)
			exit_free("Number exceeds int range", NULL, NULL);
}
