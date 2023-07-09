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



> Radix sort:
> 
> - Check the numbers one by one.
> - If a number ends with 1, put it in the 1 stack (`stack_b`).
> - If a number ends with 0, leave it in the 0 stack (`stack_a`). => by rotating the list `ra`
> - If the i-th digit of the top number in `stack_a` is 0, perform the `pb` operation to move this number to `stack_b`.
> - Otherwise, perform the `ra` operation to keep the number in `stack_a`.
> - After that, perform the `pa` operation until there are no numbers left in `stack_b`.
> - Repeat this process for the second and third bit.







# Push Swap

Coding assignment from the 42 Berlin school: sort a stack of integers in the most efficient way possible.

## Introduction

The push_swap project is a coding assignment from the coding school 42, which focuses on peer learning and a unique pedagogical approach. The goal of the push_swap project is to develop a sorting algorithm that can sort a stack of integers using a limited set of predefined operations.

## Project Overview

### Stacks

The project revolves around two stacks, named `stack_a` and `stack_b`. Initially, `stack_a` contains a random list of integers, while `stack_b` is empty. The objective is to sort the integers in `stack_a` in ascending order.

### Operations

A limited set of operations is provided to manipulate the stacks. The allowed operations are:

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | Swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | Swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | Both `sa` and `sb`                                     |
| `pa`  | push a                              | Moves the top element of stack b to the top of stack a  |
| `pb`  | push b                              | Moves the top element of stack a to the top of stack b  |
| `ra`  | rotate a                            | Shifts up all elements of stack a by 1                  |
| `rb`  | rotate b                            | Shifts up all elements of stack b by 1                  |
| `rr`  | rotate a + rotate b                 | Both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | Shifts down all elements of stack a by 1                |
| `rrb` | reverse rotate b                    | Shifts down all elements of stack b by 1                |
| `rrr` | reverse rotate a + reverse rotate b | Both `rra` and `rrb`                                   |

### Algorithm Complexity

The project emphasizes developing an efficient algorithm. The number of operations performed should be limited, and the algorithm should sort the stack within a specific range of allowed operations.

## Algorithm

To solve the push_swap problem, we will utilize the radix sort algorithm. Radix sort efficiently sorts non-negative integers by grouping them based on their digits, from the least significant to the most significant, and repeatedly rearranging them accordingly. The time complexity of radix sort is O(n * d), where n is the number of elements and d is the number of digits in the largest element.

### Advantages of Radix Sort

- Easy implementation
- Stable sorting algorithm (preserves the relative order of equal elements)

### Disadvantages of Radix Sort

- May not achieve optimal instructions for the push_swap project (unless optimized)

To facilitate efficient manipulation using bitwise operators and binary representation, we will simplify the numbers in stack A before applying radix sort. This simplification involves replacing the numbers with a range of values from 0 to N-1, where N is the size of the stack.

### Implementation Steps

1. Simplify the numbers in stack A by replacing them with values in the range [0, N-1].
2. Apply radix sort, treating `stack_a` as "stack A" and `stack_b` as "stack B."
3. Starting from the rightmost bit, perform operations on each number to place them into the corresponding stack based on their digit.
4. Upon completion, the numbers will be arranged in the stacks according to their respective digits.

### Using an index

To facilitate efficient manipulation using bitwise operators and binary representation, we will give the numbers in stack A an index (from 0 to N-1, where N is the size of the stack) before applying radix sort. We will manipulate the nodes using the indexes, effectively pushing or rotating the values themselves.

Here is an example of stack A contains the following numbers, the indexes that will be given and their binary representation

| Values | 87   | -487 | 781 | -100 | 101 | 0   | 1   |
|--------|------|------|-----|------|-----|-----|-----|
| Index  | 4    | 0    | 6   | 1    | 5   | 2   | 3   |
| Binary | 0100 | 0000 | 0110| 0001 | 0101| 0010| 0011|

By simplifying the numbers, we transform them into non-negative integers within the range [0, N-1]. Consequently, we only need to sort the simplified numbers, making radix sort an efficient choice.


## Usage

1. Compile the push_swap program.
2. Execute the program, passing the initial configuration of the stack as command-line arguments.
3. The program will output the list of operations to sort the stack.

Example usage: `./push_swap 4 3 2 1`

## Resources

- [Why Use Double Pointers](https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/)
- [Tutorial on Push Swap](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
- [Video Tutorial on Push Swap](https://www.youtube.com/watch?v=OaG81sDEpVk&ab_channel=Oceano)
- [Radix Sort Explanation](https://www.geeksforgeeks.org/radix-sort/)
- [Radix Sort Tutorial](https://www.programiz.com/dsa/radix-sort)
- [Additional Push Swap Tutorial](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Push Swap Project Documentation](https://sharkigamers.github.io/pushswap_epitech_project/)
- [Double Pointers and Linked List in C](https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/)

## Miscellaneous

- [VSCode Tips](#vscode-tips)


./push_swap_visualizer-master/build/bin/visualizer












## Implementation Notes


### Foo function

Intro

```c
void foo
{
	// Implementation details here...
}
```


### Foo function

Intro

```c
void foo
{
	// Implementation details here...
}
```



### Foo function

When you say that a bit is "set" in binary, it means that the value of that particular bit is 1. In binary representation, each digit or bit can have a value of either 0 or 1. When a bit is set, it indicates that it is turned on or active with a value of 1. Conversely, when a bit is not set, it means the value of that bit is 0.

> This function checks the value of a specific bit in the binary representation of an integer. It right-shifts the integer by the given bit position, moving the bit of interest to the rightmost position. Then, it performs a bitwise AND operation with 1 to extract the value of the rightmost bit. If the extracted bit is 1, the specified bit is considered set; otherwise, it is considered not set.



```c
void foo
{
int	is_bit_set(int num, int bit)
{
	int	shifted;
	int	result;

	shifted = num >> bit;
	result = shifted & 1;
	return (result);
}}
```



## Binary Representation
The print_binary function converts a decimal number to its binary representation.

```c
int print_binary(int num)
{
	// Implementation details here...
}

```



## Helper Functions
is_bit_set: Checks if a specific bit in an integer is set.
find_minimum_node: Finds the node with the minimum value in a linked list.
is_sorted: Checks if a linked list is sorted in ascending order.

```c

```




##VSCode Tips
To collapse all regions in Visual Studio Code, use Cmd+K followed by Cmd+0 (zero).
To hide the terminal, use Cmd+j.
To move up or down selected lines holding Alt and use the arrow keys.



##Node struct for the linked list
```c
typedef struct	s_list
{
	int				index;
	int				value;
	struct	s_list	*prev;
	struct	s_list	*next;
}	t_list;
```

## ENDS UP NOT USED
```C
t_list	*find_minimum_node(t_list *stack_a)
{
	t_list *node;
	t_list *min_node;
	int min_value;

	min_value = 2147483647; // Initialize min_value to MAX_INT
	// min_node = NULL; // Initialize min_node to NULL
	node = stack_a; // Start from the first node
	while (node->next != NULL)
	{
		if (node->index < min_value)
		{
			min_value = node->index;
			min_node = node;
		}
		node = node->next;
		// printf("\nindex = %i\nvalue = %i\nmin_value = %i\n", node->index, node->value, min_value);
	}
	return(min_node);
}
```


## The print_list function takes a pointer to the head of a linked list (head) as its input and prints the contents of the list.
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


## Print binary
```c

```C
/**
 * @brief Converts a decimal number to its binary representation.
 *
 * This function takes a decimal number as input and converts it to its binary representation.
 *
 * @param num The decimal number to be converted.
 * @return The binary representation of the input number.
 */
int print_binary(int num)
{
	// Handling special case when num is 0
	if (num == 0)
	{
		return (0);
	}

	// Finding the number of bits required
	int numBits = 0;
	int temp = num;
	while (temp > 0)
	{
		numBits++;
		temp /= 2;
	}

	// Creating an integer to store the binary representation
	int binary = 0;
	int bitPosition = 1;

	// Converting to binary representation
	for (int i = numBits - 1; i >= 0; i--)
	{
		int bit = num % 2;
		binary += bit * bitPosition;
		bitPosition *= 10;
		num /= 2;
	}

	return (binary);
}
```
```











## SHORTEN THE CODE


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
