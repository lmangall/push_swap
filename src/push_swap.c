#include "../include/push_swap.h"


// }


void print_list(const t_list *head)
{
    const t_list *current = head;

    printf("\n     Value      Index     Binary\n");
    while (current != NULL)
    {
		//%10d specifies a fixed width of 10 chars, left-aligned using the - flag
        printf("%10d %10d %10d\n", current->value, current->index, print_binary(current->index));
        current = current->next;    }
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


// go over the args (values), create a list for each and add it to the stack
void stack_ini(t_list **stack, int argc, char **argv)
{
	int		i;
	t_list *new_list;

	i = 1;
	// t_list = new_lst;

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
	printf("\nStack_a has %d elements\n", lst_size(*stack_a));
	printf("Contents of stack_a:\n");
	print_list(*stack_a);

	// swap(stack_a, "sa");
	// printf("\nstack_a has %d elements\n", lst_size(*stack_a));
	// printf("\nContents of stack_a (printed from the linked list)):\n");
	// print_list(*stack_a);

	// do pb, print a and b
	push(stack_a, stack_b, "pb");
	printf("\nstack_a has %d elements\n", lst_size(*stack_a));
	printf("\nContents of stack_a:\n");
	print_list(*stack_a);
	printf("\nstack_b has %d elements\n", lst_size(*stack_b));
	printf("\nContents of stack_b:\n");
	print_list(*stack_b);

	push(stack_a, stack_b, "pb");
	printf("\nstack_a has %d elements\n", lst_size(*stack_a));
	printf("\nContents of stack_a:\n");
	print_list(*stack_a);
	printf("\nstack_b has %d elements\n", lst_size(*stack_b));
	printf("\nContents of stack_b:\n");
	print_list(*stack_b);

	rotate(stack_a, "ra");
	printf("\nstack_a has %d elements\n", lst_size(*stack_a));
	printf("\nContents of stack_a:\n");
	print_list(*stack_a);
	printf("\nstack_b has %d elements\n", lst_size(*stack_b));
	printf("\nContents of stack_b:\n");
	print_list(*stack_b);

	//a function "int index_to_binaryindex(int index_base10) that transform a base 10 number into binary

	//a function index_to_binaryindex

	// 	sort_stack(stack_a, stack_b);
	// free_stack(stack_a);
	// free_stack(stack_b);

    return 0;
}
