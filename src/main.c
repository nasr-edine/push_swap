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
    printf("start\n");
    char **commands;
    int nb_parameters;
    char **list_of_numbers;

	// create a stack a and b
    stack *a = newStack(100);
    stack *b = newStack(100);

    nb_parameters = argc - 1;

    list_of_numbers = argv;
    
    // add the list of numbers to the stack
    add_parameters_to_stack(list_of_numbers, nb_parameters, a);

    // reading of the commands in stdin
    commands = reading_stdin();

    // print instructions
    print_instructions(commands);


    execute_commands(commands, a, b);

    // check i  stack b empty and is stack is sorted
    if (isEmpty(b) && !is_stack_sort(a))
        printf("OK\n");
    else
        printf("KO\n");

    free_memory(commands);

    return 0;
}
