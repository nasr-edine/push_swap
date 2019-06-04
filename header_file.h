#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for read function
#include <string.h> // for strcpy function
#define _GNU_SOURCE
#include <dlfcn.h>

#define BUF_SIZE 10

#define malloc(x) debug_malloc(x,__FILE__,__LINE__)
#define free(x) debug_free(x,__FILE__,__LINE__)

// Data structure for stack
typedef struct stacks
{
	int maxsize;	// define max capacity of stack
    int top;		
    int *items;
} stack;

void * debug_malloc( size_t len, char * file, int line );
void debug_free( void * addr, char * file, int line );

// All functions for use the stack
stack* newStack(int capacity);
int size(stack *pt);
int isEmpty(stack *pt);
int isFull(stack *pt);
void push(stack *pt, int x);
int peek(stack *pt);
int pop(stack *pt);

char ** reading_stdin(); // Reading stdin and save the commands
void add_parameters_to_stack(char **parameters, int nb_parameters, stack *pt); // Add list of numbers to the stack

void free_memory(char **commands);


// All operations for stack a and b
void swap(stack *a, stack *b);
void sa(stack *a);
void sb(stack *b);
void ss(stack *a, stack *b);
void pa(stack *a, stack *b);
void pb(stack *a, stack *b);

#endif

