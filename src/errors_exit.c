#include "../include/push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*current_node;

	current_node = stack;
	while (current_node->next != NULL)
	{
		if (current_node->index > current_node->next->index)
			return (0);
		else
			current_node = current_node->next;
	}
	return (1);
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// static void	ft_free(char **strs, int j)
// {
// 	while (j-- > 0)
// 		free(strs[j]);
// 	free(strs);
// }

// void	ft_free(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	while (i >= 0)
// 		free(str[i--]);
// }

void	free_stack(t_list *stack)
{
	t_list	*current;
	t_list	*tmp;

	current = stack;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

void	exit_free(char *msg, t_list **stack_a)
{
	if (ft_strcmp(msg, "correct execution") != 0)
	{
		ft_putstr_fd("Error:\n", 1);
		ft_putendl_fd(msg, 1);
	}
	if (ft_strcmp(msg, "Nothing to sort") == 0 || ft_strcmp(msg,
			"Duplicate among the arguments") == 0)
		exit(1);
	if (ft_strcmp(msg, "sorted") == 0)
	{
		free_stack(*stack_a);
		exit(1);
	}
	free_stack(*stack_a);
	exit(1);
}

void	check_duplicate(char **args, char *msg)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (args[i])
	{
		tmp = args[i];
		j = i + 1;
		while (args[j])
		{
			if (!(ft_strcmp(tmp, args[j])))
			{
				if (ft_strcmp(msg, "free") == 0)
					free_array(args);
				exit_free("Duplicate among the arguments", NULL);
			}
			j++;
		}
		i++;
	}
}

char	*check_int(char *arg)
{
	long long	tmp;
	int			i;

	i = 0;
	if (arg[0] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return ("Non authorized symbol among the arguments");
		i++;
	}
	tmp = ft_atolli(arg);
	if (tmp < -2147483648 || tmp > 2147483647)
		return ("Value exceeds int range");
	return ("all good");
}
