#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for read function
#include <string.h> // for strcpy function
#include <ctype.h> // for isdigit
#define _GNU_SOURCE
#include <dlfcn.h>

#define BUF_SIZE 10

// Data structure for stack
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

// Utility function to check if the stack is empty or not
int isEmpty(stack *pt)
{
    return pt->top == -1;	// or return size(pt) == 0;
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

// Utility function to return top element in a stack
int peek(stack *pt)
{
	// check for empty stack
    if (!isEmpty(pt))
        return pt->items[pt->top];
    else
        // exit(EXIT_FAILURE);
        return 0;
}

// Utility function to return the size of the stack
int size(stack *pt)
{
    return pt->top + 1;
}



// Utility function to check if the stack is full or not
int isFull(stack *pt)
{
    return pt->top == pt->maxsize - 1;	// or return size(pt) == pt->maxsize;
}

// Utility function to print the stack
int print_stack(stack *pt)
{
    stack new_pt = *pt;
    printf("print stack: ");
    while(!isEmpty(&new_pt)) 
    {
        int top_a = peek(&new_pt);
        printf("[%d]", top_a);
        pop(&new_pt);
    }    
    printf("\n");
    return 0;
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
void sa(stack *a)
{
    printf("\n/*****************************/\n");
    //printf("before %d\n", peek(a));


    	if (!isEmpty(a))
        {
            int top_first = peek(a);
            pop(a);
            if (!isEmpty(a))
            {
                int top_second = peek(a);
                pop(a);
                push(a, top_first);
                push(a, top_second);
                
            }
            else {
                push(a, top_first);
            }
        }
        printf("%d\n", peek(a));
}

void pa(stack *a, stack *b)
{
    // printf("\n/*****************************/\n");
    	if (!isEmpty(b))
        {

            int top_b = peek(b);
                //  printf("before Top element in stack is %d\n", peek(a));
                  //printf("[%d]\n", top_b);

            pop(b);
            push(a, top_b);

                //  printf("%d\n", peek(a));
                 //printf("after Top element in stack is %d\n", peek(b));
        }
}

void pb(stack *a, stack *b)
{
    pa(b, a);
}

/********************************************************************************/

// main function
int main(int argc, char **argv)
{
    int current;
    stack *a = newStack(100);
    stack *b = newStack(100);
    stack *temp = newStack(100);

    push(a, 10);
    push(a, 29);
    push(a, 14);
    push(a, 37);
    push(a, 15);
    push(a, 2);
    
    int array[5] = {29, 10, 14, 37, 15};
    print_stack(a);     

    // int swap;
    // for(size_t i = 0; i < 4; i++)
    // {

    //     for(size_t j = i + 1; j < 5; j++)
    //     {
    //         if (array[i] > array[j]) 
    //         {
    //             swap = array[i];
    //             array[i] = array[j];
    //             array[j] = swap;
    //         }
    //     }    
    // }
    
    // for(size_t i = 0; i < 5; i++)
    // {
    //     printf("[%d]", array[i]);
    // }

    // int current;
    
    int size_stack = size(a);
    int count_operations = 0;
    
 while(size_stack != 0 )
 {
        while(!isEmpty(a)){
        pb(a, b);
        count_operations++;

        // printf("[%d]", peek(b));
        // printf("[%d]", peek(a));
        
        if (peek(b) > peek(a)) {
            pa(a,b);
            count_operations++;
            sa(a);
            count_operations++;
            pa(a,b);
            count_operations++;
        }
        else
        {
            count_operations++;
            pb(a, b);
        }
    }
    
    while(!isEmpty(b)){
        count_operations++;
        pa(a,b);
    }
    size_stack--;
 }
     
    
    printf("t\n\n");
    print_stack(a);
    print_stack(temp);
    printf("number operations: %d", count_operations);










    return 0;
}