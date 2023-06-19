
Useful ressources:
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
https://www.youtube.com/watch?v=OaG81sDEpVk&ab_channel=Oceano
https://www.geeksforgeeks.org/radix-sort/
https://www.programiz.com/dsa/radix-sort
https://medium.com/@ayogun/push-swap-c1f5d2d41e97


# push_swap
Coding assignment from the 42 Berlin school : sort a stack of int in the most efficient way possible

## The push_swap project is a coding assignment from the coding school 42 (which is known for its unique pedagogical approach and focus on peer learning). The goal of the push_swap project is to develop a sorting algorithm that can sort a stack of integers using a limited set of predefined operations.

Here's a breakdown of how the project works:

Stacks: The project revolves around two stacks, named Stack A and Stack B. Stack A initially contains a random list of integers, and Stack B is empty. The objective is to sort the integers in Stack A in ascending order.

Operations: A limited set of operations is provided to manipulate the stacks. The allowed operations are:



| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

The program should follow specific formatting rules for the output.
Algorithm Complexity: The project places importance on developing an efficient algorithm. The number of operations performed should be limited, and the algorithm should sort the stack within a specific range of allowed operations.

This project challenged me to think critically, optimize my code, and implement an efficient sorting algorithm using a limited set of operations. 




Start with a set of boxes labeled from 0 to 9 (or in our case, 0 and 1).
Begin with the least significant digit (1's place) of the numbers.
Put each number into the box that corresponds to its digit.
Connect the numbers according to the order of the boxes.
Repeat this process for the next significant digit (10's place, 100's place, etc.).
Finally, the numbers will be sorted according to the specified digits.
In the context of the push_swap project, we simplify the numbers by replacing them with a range from 0 to N-1, where N is the size of the list. This allows us to use radix sort with a base of 2 (0 and 1) instead of 10. To manipulate the numbers in base 2, bitwise operators (such as right shift and bitwise AND) are used.

Advantages and Disadvantages
Advantages of radix sort:

Easy to implement
Stable sort (maintains the order of equal elements)
Disadvantages of radix sort:

May not achieve the maximum score unless optimized further
Implementation
To implement the push_swap program:

Parse the input numbers and put them into stack A.
Check if the numbers in stack A are already sorted. If so, end the program.
If the size of stack A is less than or equal to 5, use the sort_small_stack() function. Otherwise, use the sort_big_stack() function.
For the sort_big_stack() function, use the radix sort algorithm described above with bitwise operations to manipulate numbers in base 2.




## Algorithm
To solve the push_swap problem, we will use the radix sort algorithm. Radix sort is an efficient sorting algorithm for non-negative integers. It operates by grouping numbers based on their digits, from the least significant digit to the most significant digit, and repeatedly rearranging them according to these groups. It has a time complexity of O(n * d), where d is the number of digits in the largest number.

## Advantages of Radix Sort:
Easy to implement
Stable sorting algorithm (preserves the relative order of equal elements)
## Disadvantages of Radix Sort:
May not achieve the optimal number of instructions for the push_swap project (unless optimized)
We will simplify the numbers in stack A before applying radix sort to ensure that they fall within the non-negative range. This simplification will allow us to use bitwise operators and binary representation to manipulate the numbers efficiently.

## Simplifying the Numbers
To simplify the numbers in stack A, we will replace them with a range of values from 0 to N-1, where N is the size of the stack. This allows us to treat the numbers as non-negative integers, which can be sorted efficiently using radix sort.

For example, if we have the following numbers in stack A:

87 -487 781 -100 101 0 1

We can simplify them to:

4 0 6 1 5 2 3

Now, instead of sorting the original numbers, we only need to sort the simplified numbers in the range [0, N-1].

## Radix Sort on Push_swap
To apply radix sort on push_swap, we will treat stack A as box 1 and stack B as box 0. We will start from the rightmost bit and perform operations on each number to place them in the corresponding box according to their digit.

At the i-th bit from the right, if the i-th bit of the top number in stack A is 0, we perform the pb instruction to move the number to stack B. Otherwise, we perform the ra instruction to leave it in stack A. This process is similar to how numbers are placed in boxes in radix sort.

After performing this operation for each number, they will be in the boxes corresponding to their digits.



