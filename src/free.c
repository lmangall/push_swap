/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:25:57 by lmangall          #+#    #+#             */
/*   Updated: 2023/07/09 18:28:49 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
