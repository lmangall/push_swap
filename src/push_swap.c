#include "../include/push_swap.h"

// static	void add_value(int value, int index, struct s_list	next)
// {


// }

/**
 * @brief Prints the content of a linked list.
 *
 * This function iterates through the linked list starting from the given head
 * and prints the index and value of each node.
 *
 * @param list Pointer to the head of the linked list.
 */
void print_list(const t_list *list)
{
    const t_list *current = list;

    while (current != NULL)
    {
        printf("Index: %d, Value: %d\n", current->index, current->value);
        current = current->next;
    }
}

void stack_ini(t_list **stack, int argc, char **argv)
{
	int		i;
	t_list *new_list;

	i = 0;
	// t_list = new_lst;

	// go over the args (values), create a list for each and add it to the stack
	while( i < argc)
	{
		new_list = ft_lstnew(atoi(argv[i]));
		ft_lstadd_back(stack, new_list);
		i++;
	}
}

int main(int argc, char **argv)
{
	//  The reason for using double pointers 
	// is to allow modifications to the original pointers within a function.
	t_list **stack_a;
	t_list **stack_b;

	if (argc < 2)
		return (-1);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	// NULL signifies the end of the list. => those are empty
	*stack_a = NULL;
	*stack_b = NULL;
	stack_ini(stack_a, argc, argv);

	// Print the contents of stack_a
	printf("Contents of stack_a:\n");
	print_list(*stack_a);

	// Print the command-line arguments
	printf("\nargc = %d\n", argc);
	int i = 0;
	while (i < argc)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}

	// 	sort_stack(stack_a, stack_b);
	// free_stack(stack_a);
	// free_stack(stack_b);

    return 0;
}
