#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for read function
#include <string.h> // for strcpy function
#include <ctype.h> // for isdigit
#define _GNU_SOURCE
#include <dlfcn.h>

typedef struct stacks
{
	int maxsize;	// define max capacity of stack
    int top;		
    int *items;
} stack;

// Utility function to initialize stack
stack* newStack(int capacity)
{
    stack *pt = (stack*)malloc(sizeof(stack));

	pt->maxsize = capacity;
    pt->top = -1;
	pt->items = (int*)malloc(sizeof(int) * capacity);

    return pt;
}

// Utility function to return the size of the stack
int size(stack *pt)
{
    return pt->top + 1;
}

// Utility function to check if the stack is empty or not
int isEmpty(stack *pt)
{
    return pt->top == -1;	// or return size(pt) == 0;
}

// Utility function to check if the stack is full or not
int isFull(stack *pt)
{
    return pt->top == pt->maxsize - 1;	// or return size(pt) == pt->maxsize;
}

/********************************************************************************/

// Utility function to add an element x in the stack
void push(stack *pt, int x)
{
	// check if stack is already full. Then inserting an element would 
	// lead to stack overflow
	if (isFull(pt))
    {
        printf("OverFlow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

	//printf("Inserting %d\n", x);
	
	// add an element and increments the top index
    pt->items[++pt->top] = x;
}
/********************************************************************************/

// Utility function to return top element in a stack
int peek(stack *pt)
{
	// check for empty stack
    if (!isEmpty(pt))
        return pt->items[pt->top];
    else
    {
        printf("isEmpty\n");
        //exit(EXIT_FAILURE);
    }
       
}
/********************************************************************************/

// Utility function to pop top element from the stack
int pop(stack *pt)
{
	// check for stack underflow
    if (isEmpty(pt))
    {
        printf("UnderFlow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    //printf("Removing %d\n", peek(pt));

	// decrement stack size by 1 and (optionally) return the popped element
    return pt->items[pt->top--];
}
/********************************************************************************/

// Utility function to print the stack
int print_stack(stack *pt)
{
    stack new_pt = *pt;
    //printf("print stack: ");
    while(!isEmpty(&new_pt)) 
    {
        int top_a = peek(&new_pt);
        printf("[%d]", top_a);
        pop(&new_pt);
    }    
    printf("\n");
    return 0;
}






int main(int argc, char const *argv[])
{
    int current;
    stack *a = newStack(100);
    stack *b = newStack(100);
    stack *temp = newStack(100);

    push(a, 8);
    push(a, 5);
    push(a, 6);
    push(a, 3);
    push(a, 1);
    push(a, 2);

        //print_stack(a);

    while(!isEmpty(a))
    {
         printf("stack a: ");
         print_stack(a);
        printf("stack b: ");
        print_stack(temp);
         printf("\n\n");

        current = peek(a);
        pop(a);
        
        while (!isEmpty(temp) && current < peek(temp)) 
        {
            push(a, peek(temp));
            pop(temp);
        }
        push(temp, current);
    }
    
    while(!isEmpty(temp)){
        push(a, peek(temp));
        pop(temp);
    }
    
        printf("stack temp: ");
        print_stack(temp);

        printf("\nstack a: ");
        print_stack(a);
    return 0;
    
}
