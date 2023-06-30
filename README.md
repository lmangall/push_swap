- [Useful ressources:](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
- [https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e](https://www.youtube.com/watch?v=OaG81sDEpVk&ab_channel=Oceano)
- [https://www.youtube.com/watch?v=OaG81sDEpVk&ab_channel=Oceano](https://www.geeksforgeeks.org/radix-sort/)
- [https://www.geeksforgeeks.org/radix-sort/](https://www.programiz.com/dsa/radix-sort)
- [https://www.programiz.com/dsa/radix-sort](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [https://medium.com/@ayogun/push-swap-c1f5d2d41e97](https://sharkigamers.github.io/pushswap_epitech_project/)
- [https://sharkigamers.github.io/pushswap_epitech_project/](https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/)

Regarding the use of double pointers:
- [Why using double pointers](https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/)



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
