/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_redirect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:27:44 by lmangall          #+#    #+#             */
/*   Updated: 2023/07/09 18:28:38 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (!(swap(stack_a, "ss")) || (!swap(stack_b, "ss")))
		return (-1);
	ft_putendl_fd("ss", 1);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if ((lst_size(*stack_a) < 2) || (lst_size(*stack_b) < 2))
		return (-1);
	rotate(stack_a, "no msg");
	rotate(stack_b, "no msg");
	ft_putendl_fd("rr", 1);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((lst_size(*stack_a) < 2) || (lst_size(*stack_b) < 2))
		return (-1);
	reverse_rotate(stack_a, "no msg");
	reverse_rotate(stack_b, "no msg");
	ft_putendl_fd("rrr", 1);
	return (0);
}
