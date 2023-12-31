/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:30:14 by lmangall          #+#    #+#             */
/*   Updated: 2023/07/09 23:00:17 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//prototyping
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

# include "../lib/libft/src/libft.h"

# define NO_IDX -1

typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*next;
}	t_list;

//PROTOTYPING   get rid of
int		print_binary(int num);
void	print_list(const t_list *head);

//Checks, error handling, freeing and exiting
/**
 * @brief Check if the linked list is sorted in ascending order.
 *
 * This function traverses the linked list starting from the given stack
 * and checks if the elements are arranged in ascending order based on their
 * index values. It returns 1 if the list is sorted, and 0 otherwise.
 *
 * @param stack A pointer to the head of the linked list.
 * @return 1 if the list is sorted in ascending order, 0 otherwise.
 */
int		is_sorted(t_list *stack);
/**
 * @brief Checks for duplicate arguments in an array.
 *
 * This function checks for duplicate arguments in the given array. It
 * iterates through the array and compares each argument with the rest
 * of the arguments. If a duplicate argument is found, the function takes
 * appropriate action based on the provided message. If the message is
 * "free", it frees the memory allocated for the array before exiting
 * with an error message. Otherwise, it simply exits with an error
 * message.
 *
 * @param args An array of character pointers representing the arguments.
 * @param msg A pointer to a character array representing the message.
 * @return None.
 */

void	check_duplicate(char **args, char *msg);
/**
 * @brief Checks if a given argument is a valid integer.
 *
 * This function checks whether the provided argument is a valid int. 
 * It verifies if the argument consists of digits only and 
 * falls within the range of a signed 32-bit integer. 
 * If the argument fails any of these checks,
 * the program terminates and displays an appropriate error message.
 *
 * @param arg A pointer to the character array representing the argument.
 * @return None.
 */
char	*check_int(char *arg);
/**
 * @brief Checks the arguments and performs necessary validations.
 *
 * This function checks the arguments passed to the program and performs
 * necessary validations. If the number of arguments is less than 2, the
 * function exits with an error message stating that there is nothing to
 * sort. If the number of arguments is exactly 2, it splits the second
 * argument into an array of strings using space as the delimiter. It then
 * checks for duplicate arguments in the array and performs integer
 * validation on each argument. If any argument is not a valid integer,
 * the function frees the memory allocated for the array and exits with an
 * appropriate error message. Finally, if there are more than 2 arguments,
 * the function checks for duplicate arguments in the arguments array,
 * without freeing the memory.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of character pointers representing the
 *             command-line arguments.
 * @param stack_a A pointer to a pointer to the t_list structure
 *                representing stack A.
 * @return None.
 */

void	check_args(int argc, char **argv, t_list **stack_a);
/**
 * @brief Frees a stack of t_list nodes.
 *
 * @param stack Pointer to the top of the stack.
 */
void	free_stack(t_list *stack);
/**
 * @brief Exits the program after displaying an error message 
 * and freeing the stack_a and stack_b.
 *
 * @param msg Error message to display.
 * @param stack_a Pointer to stack A.
 * @param stack_b Pointer to stack B.
 */
void	exit_free(char *msg, t_list **stack_a);
void	free_array(char **str);

//list manipulation
/**
 * @brief Adds a node to the front of a stack making it the new head.
 *
 * @param stack A pointer to the stack (list).
 * @param new The node to add to the stack.
 *
 * @note The new node becomes the head of the stack, 
 * and its next pointer is set to the previous head.
 */
void	ft_lstadd_front(t_list **stack, t_list *new);
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
 * This function creates a new node with the specified value,
 * it returns a pointer to the newly created node. 
 * The value is assigned to the 'value' field of the node, 
 * and other fields such as 'index' and 'next' are
 * initialized to -1 and NULL.
 *
 * @param value The value to be assigned to the new node.
 * @return A pointer to the newly node, or NULL if memalloc fails.
 */
t_list	*ft_lstnew(int value);
/**
 * @brief Returns the last node of a linked list.
 *
 * This function traverses the linked list until it reaches 
 * the last node and returns a pointer to that last node.
 *
 * @param lst The starting node of the linked list.
 * @return A pointer to the last node or NULL if the list is empty.
 */
t_list	*ft_lstlast(t_list *lst);

//Initialization and sorting
/**
 * @brief Assigns an index to each node based on their values.
 *
 * This function iterates through the linked list and assigns an index 
 * Nodes with smaller values are assigned lower indices, starting from 0.
 *
 * @param stack Pointer to the head of the linked list.
 */
void	assign_index_by_value(t_list *stack, int node_nbr);
/**
 * @brief Initializes a stack with values from command-line arguments.
 *
 * This function initializes a stack using the provided command-line arguments.
 * It checks for duplicates among the arguments and adds the values to the stack.
 * It checks for the values as a long string or as separate args
 *
 * @param stack A pointer to the pointer of the stack.
 * @param argc The number of command-line arguments.
 * @param argv An array of strings representing the command-line arguments.
 */
void	stack_ini(t_list **stack_a, int argc, char **argv);

/**
 * @brief Perform radix sort algorithm to sort integers in stack_a using stack_b.
 *
 * Implements radix sort to sort integers in stack_a in ascending order.
 * It iterates through each bit of the index value of nodes, separating them
 * into stack_a and stack_b based on the checked bit. Nodes with the bit set(=1)
 * are moved to stack_b using "pb", while nodes with the bit unset are rotated
 * in stack_a using "ra". After separating the nodes, it moves them back from
 * stack_b to stack_a using "pa", preserving relative order. This process is
 * repeated for each bit until all bits are checked.
 *
 * @param stack_a Pointer to stack_a list.
 * @param stack_b Pointer to stack_b list.
 * @return 0 for successful execution of the algorithm.
 */

int		algo(t_list **stack_a, t_list **stack_b, int Astk_siz, int Bstk_siz);
/**
 * @brief Finds the minimum index value in a linked list.
 *
 * This function iterates through the linked list 
 * starting from stack_a node and finds the minimum index value. 
 * It returns the minimum index value found in the list.
 *
 * @param stack_a The pointer to the head of the linked list.
 * @return        The minimum index value in the linked list.
 */
int		find_min_idx(t_list *stack_a);
int		find_max_idx(t_list *stack);
int		sort_3(t_list **stack, char *msg);
void	sort_5(t_list **stack_a, t_list **stack_b, int max, int size);

//Helper functions
/**
 * @brief Returns the size of a linked list.
 *
 * This function calculates the number of nodes in a linked list.
 *
 * @param head Pointer to the head of the linked list.
 * @return The size of the linked list WHICH IS the max index
 */
int		lst_size(t_list *head);
/**
 * @brief Checks if a specific bit in an integer is set.
 *
 * This function checks the value of a specific bit in the binary
 * representation of an integer. It works by right-shifting the integer
 * by the given bit position, effectively moving the bit of interest to
 * the rightmost position. Then, it performs a bitwise AND operation with
 * 1 to extract the value of the rightmost bit. If the extracted bit is 1,
 * the specified bit is considered set; otherwise, it is considered not set.
 *
 * @param num The integer value.
 * @param bit The position of the bit to check.
 * @return 1 if the specified bit is set (1), 0 otherwise (0).
 */
int		is_bit_set(int num, int bit);
/**
 * @brief Calculates the number of bits to represent the max index
 *
 * This function determines the number of bits needed
 * to represent the maximum index value in the stack_a. 
 * It calculates the maximum index by subtracting 1 from the size
 * of stack_a and then calculates the number of bits 
 * required to represent that maximum index value 
 * by shifting the index value right until it becomes zero,
 * counting the number of shifts.
 *
 * @param stack_a Pointer to the stack_a list.
 * @return The number of bits required to represent the maximum index in stack_a.
 */
int		max_index_bits_nbr(t_list **stack_a);

//sorting operations
/**
 * @brief Swaps the top two elements of a stack.
 *
 * @param stack A pointer to the stack.
 * @param code The operation code.
 * @return 0 if the swap was successful, -1 otherwise.
 *
 * If the operation code is "sa", the message "sa" will be printed.
 *  If the operation code is "sb", the message "sb" will be printed.
 */
int		swap(t_list **stack, char *code);
/**
 * @brief Swaps the top two elements of both stack_a and b
 *
 * @param stack_a A pointer to stack_a.
 * @param stack_b A pointer to stack_b.
 * @return 0 if the swap was successful, -1 otherwise.
 *
 * @note The message "ss" will be printed after the swap operation.
 */
int		ss(t_list **stack_a, t_list **stack_b);
/**
 * Pushes the top element from one stack to another stack.
 *
 * @param stack_a Pointer to the stack A.
 * @param stack_b Pointer to the stack B.
 * @param code    The operation code: "pa" or "pb" for push a/b.
 *
 * @return 0 if the operation is successful, otherwise -1.
 *
 * @note Prints "pa" (push a) or "pb" (push b) to stdout.
 */
int		push(t_list **stack_a, t_list **stack_b, char *code);
/**
 * Push stack: Moves the top element of a stack
 *	to the top of another stack.
 * @param stack Pointer to the stack.
 * @param code The operation code to print.
 * @return 0 if successful, -1 if there are less than 2 elements in the stack.
 */
/**
 * @brief Shifts up all elements of stack a by 1.
 * The first element becomes the last one.
 *
 * @param stack A pointer to the stack to be rotated.
 * @param code The code string representing the rotation operation.
 * @return 0 if the rotation was successful, -1 otherwise.
 */
int		rotate(t_list **stack, char *code);
/**
 * Reverse rotate stack: Shift down all elements of stack by 1.
 * The last element becomes the first one.
 * 
 * @param stack Pointer to the stack.
 * @param code The operation code to print.
 * @return 0 if successful, -1 if there are less than 2 elements in the stack.
 */
int		reverse_rotate(t_list **stack, char *code);
/**
 * Find the previous node to the given node in a linked list.
 * 
 * @param lst The linked list.
 * @param current The current node.
 * @return The previous node if found, NULL otherwise.
 */
t_list	*ft_lstprev(t_list **lst, t_list *current);
/**
 * Rotate stack a and stack b simultaneously: 
 * Shift up all elements of both stacks by 1.
 * The first element becomes the last one in each stack.
 * 
 * @param stack_a Pointer to stack a.
 * @param stack_b Pointer to stack b.
 * @return 0 if successful, -1 if there are less than 2 elements in either stack.
 */
int		rr(t_list **stack_a, t_list **stack_b);
/**
 * Reverse rotate stack a and stack b simultaneously: 
 * Shift down all elements of both stacks by 1.
 * The last element becomes the first one in each stack.
 * 
 * @param stack_a Pointer to stack a.
 * @param stack_b Pointer to stack b.
 * @return 0 if successful, -1 if there are less than 2 elements in either stack.
 */
int		rrr(t_list **stack_a, t_list **stack_b);

#endif
