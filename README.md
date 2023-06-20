
Useful ressources:
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
https://www.youtube.com/watch?v=OaG81sDEpVk&ab_channel=Oceano
https://www.geeksforgeeks.org/radix-sort/
https://www.programiz.com/dsa/radix-sort
https://medium.com/@ayogun/push-swap-c1f5d2d41e97
https://sharkigamers.github.io/pushswap_epitech_project/


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










In C, a linked list is a data structure used to store a collection of elements. Unlike arrays, linked lists do not require contiguous memory allocation. Instead, each element in a linked list, known as a node, contains a value and a reference to the next node in the list.


Here's an example of a basic implementation of a singly linked list in C:

In this example, we define a structure called Node to represent a node in the linked list. It has two members: data to store the value of the node and next to point to the next node.

The createNode function is used to create a new node by allocating memory dynamically using malloc. It takes the data value as a parameter and returns a pointer to the newly created node.

The insertAtBeginning function inserts a new node at the beginning of the linked list. It creates a new node using createNode, sets its next pointer to the current head of the list, and updates the head to point to the new node.

The insertAtEnd function inserts a new node at the end of the linked list. If the list is empty, it simply assigns the new node as the head. Otherwise, it traverses the list using a while loop until it reaches the last node and then adds the new node as the next node.

The display function is used to print the elements of the linked list. It starts from the head and iterates through the list, printing each node's data.

Finally, in the main function, we create a linked list, insert some nodes using insertAtEnd and insertAtBeginning, and display the resulting list using the display function.

This is a basic implementation to get you started with linked lists in C. There are other operations you can perform on linked lists, such as deleting nodes, searching for a value, or inserting at a specific position.

```C
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to print the linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);

    // Display the linked list
    printf("Linked list: ");
    display(head);

    return 0;
}
```
















In the context of the 42 push_swap project, you can use a linked list to implement a stack data structure. The push_swap project involves sorting a stack of integers using a limited set of operations.

Here's a brief overview of how you can use a linked list to implement a stack for the push_swap project:

Define the structure for a node:
```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Create functions to perform stack operations:
```

push: Insert a new element at the top of the stack.
pop: Remove and return the top element from the stack.
peek: Get the value of the top element without removing it.
isEmpty: Check if the stack is empty.
Implement these functions using the linked list structure:

```c
void push(Node** top, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Error: Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

int peek(Node* top) {
    if (isEmpty(top)) {
        printf("Error: Stack is empty!\n");
        exit(EXIT_FAILURE);
    }
    return top->data;
}

int isEmpty(Node* top) {
    return top == NULL;
}
```

Utilize the stack functions in your push_swap algorithm:
Use push to insert elements onto the stack as you read input or generate instructions.
Use pop to retrieve elements from the stack when needed for sorting operations.
Use peek to access the top element for comparisons or other operations.
Use isEmpty to check if the stack is empty before performing any stack-related operations.
By implementing a stack using a linked list, you can effectively manage the stack of integers in the push_swap project. The linked list structure allows for dynamic allocation and deallocation of nodes, providing flexibility in handling the stack operations.




