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
	long tmp;
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
	tmp = ft_atoi(arg);
		if (tmp < -2147483648 || tmp > 2147483647)
			exit_free("Number exceeds int range", NULL, NULL);
}
