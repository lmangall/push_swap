
# Push Swap

Coding assignment from the 42 Berlin school: sort a stack of integers in the most efficient way possible.

## Introduction

The push_swap project is a coding assignment from the coding school 42, which focuses on peer learning and a unique pedagogical approach. The goal of the push_swap project is to develop a sorting algorithm that can sort a stack of integers using a limited set of predefined operations.

## Project Overview

### Stacks

The project revolves around two stacks, named `stack_a` and `stack_b`. `stack_a` will be initialized with a random list of integers. The objective is to sort the integers in `stack_a` in ascending order. 

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

## The radix algorithm

To solve the push_swap problem, we will utilize the radix sort algorithm. Radix sort efficiently sorts non-negative integers by grouping them based on their digits, from the least significant to the most significant, and repeatedly rearranging them accordingly. The time complexity of radix sort is O(n * d), where n is the number of elements and d is the number of digits in the largest element.
> The project emphasizes developing an efficient algorithm. The number of operations performed should be limited, and the algorithm should sort the stack within a specific range of allowed operations. 

### Advantages of Radix Sort
- Easy implementation
- Stable sorting algorithm (preserves the relative order of equal elements)

### Disadvantages of Radix Sort
- May not achieve optimal instructions for the push_swap project (unless optimized)

### Implementation (overall steps))

1. Simplify the numbers in stack A by replacing them with **index** values in the range [0, N-1].
2. Check the BRI (**binary** representation of the index) of each number **bit by bit**.
3. Starting from the rightmost bit, perform operations on each number to place them into the corresponding stack based on their digit.
>>If a BRI ends (bitwise rightshift) with 0, put it in the `stack_b`: `pb`
>>If a BRI ends with 1, leave it in `stack_a`. (by rotating the list `ra`)
>>repeat for each number
4. Upon completion, the numbers will be arranged in the stacks according to their respective digits.


### Implementation (details)

To facilitate efficient manipulation using bitwise operators and binary representation, we will give the numbers in stack A an index (from 0 to N-1, where N is the size of the stack) before applying radix sort. We will manipulate the nodes using the indexes, effectively pushing or rotating the values themselves.

Here is an example of stack A contains the following numbers, the indexes that will be given and their binary representation

| Values |  87  | -487 | 781 | -100 | 101 |  0  |  1  |
|--------|:----:|-----:|----:|-----:|----:|----:|----:|
| Index  |  4   |  0   |  6  |  1   |  5  |  2  |  3  |
| Binary | 0100 | 0000 | 0110| 0001 | 0101| 0010| 0011|

'
When converting binary numbers to decimal, the odd and even nature of the number can still be determined based on the last bit. If the last bit of the binary number  is not set (i.e., it is 0), the corresponding decimal number will be even. If the last bit is set (i.e., it is 1), the decimal number will be odd. 
'

By simplifying the numbers, we transform them into non-negative integers within the range [0, N-1]. Consequently, we only need to sort the simplified numbers, making radix sort an efficient choice.

By using the 'is_bit_set' function, the code decides whether to push the current node to stack_b or rotate stack_a based on the value of the checked_bit position in the binary representation of the index. The loop continues until all elements in stack_a have been processed. Here is an example for the very first loop:


the push to stack_b (pb) will be made if the bit is not set (i.e., the result is 0), and the rotate operation (ra) will be performed if the bit is set (i.e., the result is 1).

|   Index  | Binary | Move |           | Stack A       | Stack B     |
|----------|--------|------|-----------|---------------|-------------|
|    4     |  0100  |  pb  |           |  0001         |  0010       |
|    0     |  0000  |  pb  |           |  0101         |  0110       |
|    6     |  0110  |  pb  |           |  0011         |  0000       |
|    1     |  0001  |  ra  |           |               |  0100       |
|    5     |  0101  |  ra  |           |               |             |
|    2     |  0010  |  pb  |           |               |             |
|    3     |  0011  |  ra  |           |               |             |


Following the completion of the loop, the values in Stack B are pushed back to Stack A. Then, the second rightmost bit of each index will be examined.

| Stack A | Index |
|---------|-------|
|   0100  |   4   |
|   0000  |   0   |
|   0110  |   6   |
|   0010  |   2   |
|   0001  |   0   |
|   0101  |   5   |
|   0011  |   3   |


The specific values themselves are not relevant. The movements of the nodes depend solely on the index, and as a result, the corresponding values are also moved accordingly.

## Usage

1. Compile the push_swap program.
2. Execute the program, passing the initial configuration of the stack as command-line arguments.
3. The program will output the list of operations to sort the stack.

Example usage: `./push_swap 2 4 1 3`

- [Visualizer](https://github.com/o-reo/push_swap_visualizer) command *./push_swap_visualizer-master/build/bin/visualizer*

The visualizer is usefull for debugging


## Resources

- [Why Use Double Pointers](https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/)
- [Tutorial on Push Swap](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
- [Video Tutorial on Push Swap](https://www.youtube.com/watch?v=OaG81sDEpVk&ab_channel=Oceano)
- [Radix Sort Explanation](https://www.geeksforgeeks.org/radix-sort/)
- [Radix Sort Tutorial](https://www.programiz.com/dsa/radix-sort)
- [Additional Push Swap Tutorial](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Push Swap Project Documentation](https://sharkigamers.github.io/pushswap_epitech_project/)
- [Double Pointers and Linked List in C](https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/)
- [Article on 42 cursus gitbook](https://42-cursus.gitbook.io/guide/rank-02/push_swap/building-the-thing)
- [Vizualizer](https://github.com/o-reo/push_swap_visualizer)

## Miscellaneous

### conversion between decimal and binary numbers.
This table can be used to quickly look up the binary representation of a decimal number or vice versa.

| Decimal |   64     |   32     |   16     |   8      |   4      |   2      |   1      |
|---------|----------|----------|----------|----------|----------|----------|----------|
| Binary  | 01000000 | 00100000 | 00010000 | 00001000 | 00000100 | 00000010 | 00000001 |


[Video on binary to decimal](https://youtu.be/RrJXLdv1i74?t=605)



## Error management
The subject didn't specifically require error messages, and using error messages in this context may even be considered unconventional. However, I chose to employ error messages as they significantly enhance code cleanliness and improve readability, aiding in understanding the outputs and the underlying processes. Additionally, I leverage these error messages to selectively trigger various options within a function. By comparing a message sent to a function with a specific one, the code evaluates these comparisons and conditionally executes different code blocks. This allows for dynamic decision-making, such as choosing whether or not to free certain structures or stacks based on the outcome of the comparisons.

```C
void	exit_free(char *msg, t_list **stack_a)
{
	//If the execution is correct we don't want to output error or any messages
	if (ft_strcmp(msg, "correct execution") != 0)
	{
		ft_putstr_fd("Error:\n", 1);
		ft_putendl_fd(msg, 1);
	}
	//in this case we don't want to free
	if (ft_strcmp(msg, "Nothing to sort") == 0 || ft_strcmp(msg, "Duplicate among the arguments") == 0)
		exit(1);
	if (ft_strcmp(msg, "sorted") == 0)
	{
		free_stack(*stack_a);
		exit(1);
	}
	free_stack(*stack_a);
	exit(1);
}
```

By utilizing the error messages that are output to stderr (2), the code becomes more debuggable, and it becomes possible to redirect the output of a single execution to a file based on whether the messages are sent to stdout (1) or stderr (2). This approach can be useful for error tracking, or generating reports that isolate error-related information.

### The ">" operator: the "output redirection operator" or the "stdout redirection operator."
By using the appropriate redirection operators, you can capture and segregate the stdout and stderr outputs separately, allowing for more effective debugging and analysis of the program's execution.
>> "1>" redirects the standard output (stdout) of a command to a file. "2>" redirects the standard error (stderr) of a command to a file.

Let's say we have a command called "mycommand" that produces both regular output (stdout) and error messages (stderr). To capture only the output from either stream, you can use the following commands:

```C
mycommand > stdout.txt
```
In this case, the regular output from "mycommand" will be redirected to the "stdout.txt" file, while any error messages will still be displayed on the terminal.

```C
mycommand 2> stderr.txt
```
In this case, the error messages from "mycommand" will be redirected to the "stderr.txt" file, while the regular output will still be displayed on the terminal.

By redirecting the desired output stream to a file using the ">" operator, you can save that specific output to a file while disregarding the other stream. This allows you to focus on the output that is relevant to your analysis or debugging, keeping it separate for further examination or processing.




## Implementation Notes



#### is_bit_set

When you say that a bit is "set" in binary, it means that the value of that particular bit is 1. In binary representation, each digit or bit can have a value of either 0 or 1. When a bit is set, it indicates that it is turned on or active with a value of 1. Conversely, when a bit is not set, it means the value of that bit is 0.

> This function checks the value of a specific bit in the binary representation of an integer. It right-shifts the integer by the given bit position, moving the bit of interest to the rightmost position. Then, it performs a bitwise AND operation with 1 to extract the value of the rightmost bit.

```c

int	is_bit_set(int num, int bit)
{
	int	shifted;
	int	result;

	shifted = num >> bit;
	result = shifted & 1;
	return (result);
}
```
>the push to stack_b (pb) will be made if the bit is not set (i.e., the result is 0), and the rotate operation (ra) will be performed if the bit is set (i.e., the result is 1).


#### struct s_list

This structure is used to implement a stack data structure. A stack is an abstract data type (ADT) that follows the Last-In-First-Out (LIFO) principle. It is a linear data structure where elements are added and removed from the same end, known as the top of the stack. 

```c
typedef struct	s_list
{
	int				index;
	int				value;
	struct	s_list	*next;
}	t_list;
```
>It's worth noting that while the linked list implementation allows for dynamic resizing of the stack, it may consume more memory due to the additional pointers required for each node. If a fixed-size stack is required, an array-based implementation could be used instead.


## VSCode Tips
To collapse all regions in Visual Studio Code, use Cmd+K followed by Cmd+0 (zero).
To hide the terminal, use Cmd+j.
To move up or down selected lines holding Alt and use the arrow keys.


-
-
-
-
-
-
-
-
-
-
-



-
-
-
-
-
-
-


-
-
-
-
-
-
-



## Blockquotes


> Blockquotes can also be nested...
>> ...by using additional greater-than signs right next to each other...
> > > ...or with spaces between arrows.


### Foo function

Intro

```c
void foo
{
	// Implementation details here...
}
```



## Helper Functions
is_bit_set: Checks if a specific bit in an integer is set.
find_minimum_node: Finds the node with the minimum value in a linked list.
is_sorted: Checks if a linked list is sorted in ascending order.



## find_minimum_node  => not used in the code
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


## Print list function => used for debugging

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


## Print binary => used to better grasp binary
```c
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


-
-
-
-
-
-
-
-
-
-
-
-
-
-
-
-
-
-



## SHORTEN THE CODE

### VS Code collapse
To collapse all code blocks in Visual Studio Code, you can use the following methods:

Using Keyboard Shortcuts:

- Windows/Linux: Press `Ctrl + K` followed by `Ctrl + 0` (zero).
- macOS: Press `Cmd + K` followed by `Cmd + 0` (zero).

Using the Command Palette:

- Open the Command Palette by pressing `Ctrl + Shift + P` (Windows/Linux) or `Cmd + Shift + P` (macOS).
- Type "Fold All" and select the "Fold All" command from the dropdown.



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
```

### Overview and logic to sort 3 values:
```
//minimum at end
Combination 6: (2, 1, 0)              X
Combination 4: (1, 2, 0)
sa if max on top then rra

//maximum at end
Combination 1: (0, 1, 2) sorted: problem already exited
Combination 3: (1, 0, 2)
sa

//other / middle at end
Combination 2: (0, 2, 1)
Combination 5: (2, 0, 1) 
sa if min on top then ra
```




### tester command:
```
ARG="324 5 43 65 435"; ./push_swap $ARG | ./checker_linux $ARG
```
