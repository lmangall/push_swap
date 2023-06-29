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
 * @param head Pointer to the head of the linked list.
 */
void print_list(const t_list *head)
{
    const t_list *current = head;

    while (current != NULL)
    {
        printf("Index: %d, Value: %d\n", current->index, current->value);
        current = current->next;
    }
}

// void print_list(t_list *head)
// {
// 	t_list	*tmp;

// 	tmp = head;
// 	while (tmp != NULL)
// 	{
// 		ft_putnbr_fd(tmp->value, 1);
// 		ft_putendl_fd("", 1);
// 		tmp = tmp->next;
// 	}
// }


void stack_ini(t_list **stack, int argc, char **argv)
{
	int		i;
	t_list *new_list;

	i = 1;
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

	assign_index_by_value(*stack_a);

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

	printf("\nlst_size = %d\n", lst_size(*stack_a));


	// printf("\nmax_index = %d\n", set_maxindex(*stack_a));

	// 	sort_stack(stack_a, stack_b);
	// free_stack(stack_a);
	// free_stack(stack_b);

    return 0;
}
