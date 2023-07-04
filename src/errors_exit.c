#include "../include/push_swap.h"

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
	free_stack(stack_a);
	free_stack(stack_b);
	exit(1);
}

void check_int(char *arg)
{
	int i;
	int tmp;
	
	i = 0;
	while (arg[i])
	{
		tmp = ft_atoi(&arg[i]);
		printf("tmp: %d\n", tmp);
		if (ft_isdigit(tmp))
			exit_free("Not a number", NULL, NULL);
		if (tmp < -2147483648 || tmp > 2147483647)
			exit_free("Number exceeds int range", NULL, NULL);
		i++;
	}
}
