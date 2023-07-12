/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_errors_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:54:54 by lmangall          #+#    #+#             */
/*   Updated: 2023/07/12 14:59:36 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_free(char *msg, t_list **stack_a)
{
	if (ft_strcmp(msg, "correct execution") != 0)
	{
		ft_putstr_fd("Error:\n", 2);
		ft_putendl_fd(msg, 2);
	}
	if (ft_strcmp(msg, "Nothing to sort") == 0 || ft_strcmp(msg,
			"Duplicate among the arguments") == 0)
		exit(1);
	if (ft_strcmp(msg, "sorted") == 0)
	{
		free_stack(*stack_a);
		exit(1);
	}
	if (stack_a != NULL)
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

void	check_args(int argc, char **argv, t_list **stack_a)
{
	char	**args;
	char	*msg;
	int		i;

	i = 0;
	msg = "all good";
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		check_duplicate(args, "free");
		while (args[++i] && (ft_strcmp(msg, "all good") == 0))
			msg = check_int(args[i]);
		free_array(args);
	}
	if (argc > 2)
	{
		check_duplicate(argv + 1, "do not free");
		while (++i != argc - 1 && (ft_strcmp(msg, "all good") == 0))
			msg = check_int(argv[i + 1]);
	}
	if (ft_strcmp(msg, "all good") != 0)
		exit_free(msg, stack_a);
}
