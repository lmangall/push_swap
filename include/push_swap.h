
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//prototyping
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

# include "../lib/libft/src/libft.h"

#define NO_IDX -1

typedef struct	s_list
{
	int				index;
	int				value;
	struct	s_list	*prev;
	struct	s_list	*next;
}	t_list;


/**
 * @brief Adds the specified node to the front of a stack (list), making it the new head.
 *
 * @param stack A pointer to the stack (list).
 * @param new The node to add to the stack.
 *
 * @note The new node becomes the head of the stack, and its next pointer is set to the previous head.
 */
void ft_lstadd_front(t_list **stack, t_list *new);

/**
 * @brief Adds the specified node to a stack (list), making it the last node.
 *
 * This function adds a new node to the end of the stack (list). If the stack
 * is not empty, the new node is appended after the last node. If the stack is
 * empty, the new node becomes the first and only node in the stack.
 *
 * @param stack A pointer to the pointer to the stack (list).
 * @param new The new node to be added to the stack.
 */
void	ft_lstadd_back(t_list **stack, t_list *new);
/**
 * @brief Creates a new node and returns a pointer to it.
 *
 * This function creates a new node with the specified value and returns a
 * pointer to the newly created node. The value is assigned to the 'value'
 * field of the node, and other fields such as 'index' and 'next' are
 * initialized to -1 and NULL.
 *
 * @param value The value to be assigned to the new node.
 * @return A pointer to the newly created node, or NULL if memory allocation fails.
 */
t_list	*ft_lstnew(int value);
/**
 * @brief Returns the last node of a linked list.
 *
 * This function traverses the linked list starting from the specified node
 * until it reaches the last node and returns a pointer to that last node.
 *
 * @param lst The starting node of the linked list.
 * @return A pointer to the last node of the linked list, or NULL if the list is empty.
 */
t_list *ft_lstlast(t_list *lst);
void stack_ini(t_list **stack, int argc, char **argv);
/**
 * @brief Returns the size of a linked list.
 *
 * This function calculates the number of nodes in a linked list.
 *
 * @param head Pointer to the head of the linked list.
 * @return The size of the linked list.
 */
int lst_size(t_list *head);
/**
 * @brief Assigns an index to each node in the linked list based on their values.
 *
 * This function iterates through the linked list and assigns an index value to each node
 * based on their values. Nodes with smaller values are assigned lower indices, starting from 0.
 *
 * @param stack Pointer to the head of the linked list.
 */
void assign_index_by_value(t_list *stack);
int	print_binary(int num);


//sorting operations

/**
 * @brief Swaps the top two elements of a stack.
 *
 * @param stack A pointer to the stack.
 * @param code The operation code.
 * @return 0 if the swap was successful, -1 otherwise.
 *
 * @note If the operation code is "sa", the message "sa" will be printed.
 *       If the operation code is "sb", the message "sb" will be printed.
 */
int swap(t_list **stack, char *code);
/**
 * @brief Swaps the top two elements of both stack_a and stack_b simultaneously.
 *
 * @param stack_a A pointer to stack_a.
 * @param stack_b A pointer to stack_b.
 * @return 0 if the swap was successful, -1 otherwise.
 *
 * @note The message "ss" will be printed after the swap operation.
 */
int ss(t_list **stack_a, t_list **stack_b);
/**
 * @brief Moves the top element of one stack to the top of another stack.
 *
 * @param stack_from A pointer to the stack to move the element from.
 * @param stack_to A pointer to the stack to move the element to.
 * @param code The operation code. (pa or pb)
 * @return 0 if the push was successful, -1 otherwise.
 *
 * @note If the operation code is "pa", the top element of stack_b will be moved to the top of stack_a.
 *       If the operation code is "pb", the top element of stack_a will be moved to the top of stack_b.
 */
int push(t_list **stack_from, t_list **stack_to, char *code);




// /**
//  * @brief Shift up all elements of stack a by 1. The first element becomes the last one.
//  * 
//  * @param stack_a A pointer to stack a.
//  * @return int Returns 0 if successful, -1 otherwise.
//  */
// int ra(t_list **stack_a);

// /**
//  * @brief Shift up all elements of stack b by 1. The first element becomes the last one.
//  * 
//  * @param stack_b A pointer to stack b.
//  * @return int Returns 0 if successful, -1 otherwise.
//  */
// int rb(t_list **stack_b);

// /**
//  * @brief Shift up all elements of stack a and stack b by 1.
//  * 
//  * @param stack_a A pointer to stack a.
//  * @param stack_b A pointer to stack b.
//  * @return int Returns 0 if successful, -1 otherwise.
//  */
// int rr(t_list **stack_a, t_list **stack_b);

// /**
//  * @brief Shift down all elements of stack a by 1. The last element becomes the first one.
//  * 
//  * @param stack_a A pointer to stack a.
//  * @return int Returns 0 if successful, -1 otherwise.
//  */
// int rra(t_list **stack_a);

// /**
//  * @brief Shift down all elements of stack b by 1. The last element becomes the first one.
//  * 
//  * @param stack_b A pointer to stack b.
//  * @return int Returns 0 if successful, -1 otherwise.
//  */
// int rrb(t_list **stack_b);

// /**
//  * @brief Shift down all elements of stack a and stack b by 1.
//  * 
//  * @param stack_a A pointer to stack a.
//  * @param stack_b A pointer to stack b.
//  * @return int Returns 0 if successful, -1 otherwise.
//  */
// int rrr(t_list **stack_a, t_list



#endif








// static void	initStack(t_list **stack, int argc, char **argv)
// {
// 	t_list	*new;
// 	char	**args;
// 	int		i;

// 	i = 0;
// 	// if argc is 2 it means the values were entered as one arg
// 	if (argc == 2)
// 		args = ft_split(argv[1], ' ');
// 	else
// 	{
// 		i = 1;
// 		args = argv;
// 	}
// 	while (args[i])
// 	{
// 		new = ft_lstnew(ft_atoi(args[i]));
// 		ft_lstadd_back(stack, new);
// 		i++;
// 	}
// 	index_stack(stack);
// 	if (argc == 2)
// 		ft_free(args);
// }
// static void	sort_stack(t_list **stack_a, t_list **stack_b)
// {
// 	if (ft_lstsize(*stack_a) <= 5)
// 		simple_sort(stack_a, stack_b);
// 	else
// 		radix_sort(stack_a, stack_b);
// }

// int	main(int argc, char **argv)
// {
// 	t_list	**stack_a;
// 	t_list	**stack_b;

// 	if (argc < 2)
// 		return (-1);
// 	ft_check_args(argc, argv);
// 	stack_a = (t_list **)malloc(sizeof(t_list));
// 	stack_b = (t_list **)malloc(sizeof(t_list));
// 	*stack_a = NULL;
// 	*stack_b = NULL;
// 	initStack(stack_a, argc, argv);
// 	if (is_sorted(stack_a))
// 	{
// 		free_stack(stack_a);
// 		free_stack(stack_b);
// 		return (0);
// 	}
// 	sort_stack(stack_a, stack_b);
// 	free_stack(stack_a);
// 	free_stack(stack_b);
// 	return (0);
// }
