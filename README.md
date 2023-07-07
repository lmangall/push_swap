





```C
Combination 1: (1, 2, 3)
Combination 3: (2, 1, 3)
Combination 4: (2, 3, 1) X
Combination 6: (3, 2, 1) 
Combination 5: (3, 1, 2) X
Combination 2: (1, 3, 2) X

void	ft_sort_three(t_stack **stack_a)
{
	if (ft_min(*stack_a) == (*stack_a)->nbr)
	{
		ft_rra(stack_a, 0);
		ft_sa(stack_a, 0);
	}
	else if (ft_max(*stack_a) == (*stack_a)->nbr)
	{
		ft_ra(stack_a, 0);
		if (!ft_checksorted(*stack_a))
			ft_sa(stack_a, 0);
	}
	else
	{
		if (ft_find_index(*stack_a, ft_max(*stack_a)) == 1)
			ft_rra(stack_a, 0);
		else
			ft_sa(stack_a, 0);
	}
}

// This function checks the index of a number
// 	 in the stack.
int	ft_find_index(t_stack *a, int nbr)
{
	int		i;

	i = 0;
	while (a->nbr != nbr)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}
```






























- [Useful ressources:](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
- [https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e](https://www.youtube.com/watch?v=OaG81sDEpVk&ab_channel=Oceano)
- [https://www.youtube.com/watch?v=OaG81sDEpVk&ab_channel=Oceano](https://www.geeksforgeeks.org/radix-sort/)
- [https://www.geeksforgeeks.org/radix-sort/](https://www.programiz.com/dsa/radix-sort)
- [https://www.programiz.com/dsa/radix-sort](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [https://medium.com/@ayogun/push-swap-c1f5d2d41e97](https://sharkigamers.github.io/pushswap_epitech_project/)
- [https://sharkigamers.github.io/pushswap_epitech_project/](https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/)

Regarding the use of double pointers:
- [Why using double pointers](https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/)


# CHECK IF CORRECT FOR SOME NUMBERS (seems to be a lot of operations)

# Yet to do 
- 
- double check the check_int func and clean it
- implement a small number algo ?
- add a test to check if already sorted
- Use tester
- Check for leaks
- polish and check makefile
- final norminette
- check exit_free relative to check_int (doest it free, should it free?)
- organize code
- clean readme


ARG=4 20 38; ./push_swap $ARG | ./checker_Mac $ARG


 ARG="4 20 38 43 43 654 765 231 564 76 4376 765 765 423"; ./push_swap $ARG | ./checker_Mac $ARG

'



creation
	t_list	*stack_a;
sending
	&stack_a
=>sends a pointer to pointer, because it sends the address to a pointer

be careful not to dereference

```C
void	stack_ini(t_list **stack, char **argv)
{
	int		i;
	t_list	*new_list;
	char	**args;

	i = 0;
	if (! stack)
		return ;
	// if (argc == 2)
		args = ft_split(argv[1], ' ');
	// else
	// 	args = &argv[1];
	check_duplicate(args);
	while (args[i])
	{
		check_int(args[i]);
		new_list = ft_lstnew(atoi(args[i]));
		ft_lstadd_back(stack, new_list);
		i++;
	}
	free_array(args);
}
```

munmap_chunk(): invalid pointer





```C
int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}
```




Same as...
```C
void	stack_ini(t_list **stack, int argc, char **argv)
{
	int		i;
	t_list	*new_list;

	i = 1;
	// t_list = new_lst;
	while (i < argc)
	{
		new_list = ft_lstnew(atoi(argv[i]));
		ft_lstadd_back(stack, new_list);
		i++;
	}
}
```

same as:
```c
void stack_ini(t_list **stack, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(stack, ft_lstnew(atoi(argv[i])));
		i++;
	}
}
}```

The print_list function takes a pointer to the head of a linked list (head) as its input and prints the contents of the list.
```c
void	print_list(const t_list *head)
{
	const t_list	*current;

	current = head;
	printf("\n     Value      Index     Binary\n");
	while (current != NULL)
	{
		//%10d specifies a fixed width of 10 chars, left-aligned using the - flag
        printf("%10d %10d %10d\n", current->value, current->index, print_binary(current->index));
        current = current->next;
		current = current->next;
	}
}
```



```c
	// algo(stack_a, stack_b);
	printf("\nstack_a has %d elements\n", lst_size(*stack_a));
	printf("\nContents of stack_a:\n");
	print_list(*stack_a);
	printf("\nstack_b has %d elements\n", lst_size(*stack_b));
	printf("\nContents of stack_b:\n");
	print_list(*stack_b);
````



```c
c code block
```


VSCode:
Collapse all regions in Visual Studio Code is Cmd+K followed by Cmd+0 (zero).
Cmd+j hides the terminal


# push_swap
Coding assignment from the 42 Berlin school : sort a stack of int in the most efficient way possible

## The push_swap project is a coding assignment from the coding school 42 (which is known for its unique pedagogical approach and focus on peer learning). The goal of the push_swap project is to develop a sorting algorithm that can sort a stack of integers using a limited set of predefined operations.

Here's a breakdown of how the project works:

Stacks:
The project revolves around two stacks, named `stack_a` and `stack_b`. `stack_a` initially contains a random list of integers, and `stack_b` is empty. The objective is to sort the integers in `stack_a` in ascending order.

Operations: A limited set of operations is provided to manipulate the stacks. The allowed operations are:



| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | Swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | Swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | Both `sa` and `sb`                                     |
| `pa`  | push a                              | Moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | Moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | Shift up all elements of stack a by 1                  |
| `rb`  | rotate b                            | Shift up all elements of stack b by 1                  |
| `rr`  | rotate a + rotate b                 | Both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | Shift down all elements of stack a by 1                |
| `rrb` | reverse rotate b                    | Shift down all elements of stack b by 1                |
| `rrr` | reverse rotate a + reverse rotate b | Both `rra` and `rrb`                                   |

The program should follow specific formatting rules for the output.
Algorithm Complexity: The project places importance on developing an efficient algorithm. The number of operations performed should be limited, and the algorithm should sort the stack within a specific range of allowed operations.

This project challenged me to think critically, optimize my code, and implement an efficient sorting algorithm using a limited set of operations. 



## Algorithm
To solve the push_swap problem, we will utilize the radix sort algorithm. Radix sort efficiently sorts non-negative integers by grouping them based on their digits, from the least significant to the most significant, and repeatedly rearranging them accordingly. The time complexity of radix sort is O(n * d), where n is the number of elements and d is the number of digits in the largest element.

## Advantages of Radix Sort:
- Easy implementation
- Stable sorting algorithm (preserves the relative order of equal elements)

## Disadvantages of Radix Sort:
- May not achieve optimal instructions for the push_swap project (unless optimized)

To facilitate efficient manipulation using bitwise operators and binary representation, we will simplify the numbers in stack A before applying radix sort. This simplification involves replacing the numbers with a range of values from 0 to N-1, where N is the size of the stack.

For example, suppose stack A initially contains the following numbers:
- 87
- -487
- 781
- -100
- 101
- 0
- 1

We can simplify these numbers as follows:
- 4
- 0
- 6
- 1
- 5
- 2
- 3

By simplifying the numbers, we transform them into non-negative integers within the range [0, N-1]. Consequently, we only need to sort the simplified numbers, making radix sort an efficient choice.

By simplifying the numbers, we transform them into non-negative integers within the range [0, N-1]. Consequently, we only need to sort the simplified numbers, making radix sort an efficient choice.

To apply radix sort in the push_swap context, we will treat `stack_a` as "stack A" and `stack_b` as "stack B". Starting from the rightmost bit, we perform operations on each number to place them into the corresponding stack based on their digit.

At the i-th bit from the right, if the i-th bit of the top number in `stack_a` is 0, we execute the "pb" instruction to move the number to `stack_b`. Otherwise, we execute the "ra" instruction to leave it in `stack_a`. This process emulates the concept of placing numbers during radix sort.

Upon completion of these operations for each number, they will be arranged in the stacks according to their respective digits.







In C, a linked list is a data structure used to store a collection of elements. Unlike arrays, linked lists do not require contiguous memory allocation. Instead, each element in a linked list, known as a node, contains a value and a reference to the next node in the list.





Define the structure for a node:
```c
typedef struct	s_list
{
	int				index;
	int				value;
	struct	s_list	*prev;
	struct	s_list	*next;
}	t_list;
```





## What does it means for abit to be "set"
When you say that a bit is "set" in binary, it means that the value of that particular bit is 1. In binary representation, each digit or bit can have a value of either 0 or 1. When a bit is set, it indicates that it is turned on or active with a value of 1. Conversely, when a bit is not set, it means the value of that bit is 0.

/**
 * @brief Checks if a specific bit in an integer is set.
 *
 * This function checks the value of a specific bit in the binary representation
 * of an integer. It works by right-shifting the integer by the given bit position,
 * effectively moving the bit of interest to the rightmost position. Then, it performs
 * a bitwise AND operation with 1 to extract the value of the rightmost bit. If the
 * extracted bit is 1, the specified bit is considered set; otherwise, it is considered
 * not set.
 *
 * @param num The integer value.
 * @param bit The position of the bit to check.
 * @return 1 if the specified bit is set (1), 0 otherwise (0).
 */
int is_bit_set(int num, int bit)


> Radix sort:
> 
> - Check the numbers one by one.
> - If a number ends with 1, put it in the 1 stack (`stack_b`).
> - If a number ends with 0, leave it in the 0 stack (`stack_a`). => by rotating the list `ra`
> - If the i-th digit of the top number in `stack_a` is 0, perform the `pb` operation to move this number to `stack_b`.
> - Otherwise, perform the `ra` operation to keep the number in `stack_a`.
> - After that, perform the `pa` operation until there are no numbers left in `stack_b`.
> - Repeat this process for the second and third bit.








#INI AND MAIN VERSION 2 (malloced in ini)
```c
void stack_ini(t_list **stack, int argc, char **argv)
{
	int i;
	t_list *new_list;

	i = 1;
	while (i < argc)
	{
		new_list = (t_list *)malloc(sizeof(t_list));
		if (!new_list)
			exit_free("Memory allocation failed", *stack, NULL);
		new_list->value = atoi(argv[i]);
		new_list->index = 0;
		new_list->next = NULL;
		ft_lstadd_back(stack, new_list);
		i++;
	}
}


int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	if (argc < 2)
		return (-1);

	stack_a = NULL;
	stack_b = NULL;

	stack_ini(&stack_a, argc, argv);
	assign_index_by_value(stack_a);

	algo(&stack_a, &stack_b);
	print_list(stack_a);

	exit_free("allgood", stack_a, stack_b);
	return (0);
}
```










Same as...
```C
void check_int(char *arg)
{
    int i;
    int is_negative;
    size_t max_length;

    i = 0;
    is_negative = (arg[i] == '-');
    if (is_negative)
        i++;

    max_length = 10 + is_negative * (11 - 10);
    if (ft_strlen(arg) > max_length)
        exit_free("Number exceeds int range", NULL, NULL);

    while (arg[i])
    {
        if (!ft_isdigit(arg[i]))
            exit_free("Not a number", NULL, NULL);
        i++;
    }

    int is_exceed_range = (is_negative && strlen(arg) == 11 && strcmp(arg, "2147483648") > 0) ||
                          (!is_negative && strlen(arg) == 10 && strcmp(arg, "2147483647") > 0);

    if (is_exceed_range)
        exit_free("Number exceeds int range", NULL, NULL);
}
```

same as:
```c
void check_int(char *arg)
{
    int i;
    int is_negative;
	size_t max_length;

    i = 0;
    is_negative = 0;
    if (arg[i] == '-')
    {
        is_negative = 1;
        i++;
    }

    max_length = (is_negative) * 11 + (!is_negative) * 10;
    if (ft_strlen(arg) > max_length)
        exit_free("Number exceeds int range", NULL, NULL);

    while (arg[i])
    {
        if (!ft_isdigit(arg[i]))
            exit_free("Not a number", NULL, NULL);
        i++;
    }

    int is_exceed_range = 0;
    if (is_negative)
    {
        if (strlen(arg) == 11 && strcmp(arg, "2147483648") > 0)
            is_exceed_range = 1;
    }
    else
    {
        if (strlen(arg) == 10 && strcmp(arg, "2147483647") > 0)
            is_exceed_range = 1;
    }

    if (is_exceed_range)
        exit_free("Number exceeds int range", NULL, NULL);
}
```