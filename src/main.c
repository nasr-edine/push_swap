#include "../header_file.h"

void print_instructions(char **commands)
{
    int i = 0;
    
    printf("list instructions: ");
    while(commands[i] != NULL )
    {
        printf("[%s]", commands[i]);
        i++;
    }
    printf("\n\n");
}

// main function
int main(int argc, char **argv)
{
    char **commands;
    int nb_parameters;
    char **list_of_numbers;

    // reading of the commands in stdin
    commands = reading_stdin();

    // print instructions
    print_instructions(commands);

    nb_parameters = argc - 1;

    list_of_numbers = argv;

	// create a stack a and b
    stack *a = newStack(100);
    stack *b = newStack(100);

    // add the list of numbers to the stack
    add_parameters_to_stack(list_of_numbers, nb_parameters, a);

    execute_commands(commands, a, b);

    // check for empty stack
    if (isEmpty(b))
        printf("stack b is empty\n");
    else
        printf("stack b is not empty\n");

    // check if stack is sort
    if (!is_stack_sort(a))
        printf("stack a is sorted\n");
    else
        printf("stack a is not sorted\n");

    free_memory(commands);

    return 0;
}
