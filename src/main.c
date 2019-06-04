#include "../header_file.h"

void read_list_commands(char **commands)
{
    int i = 0;
    
    while(commands[i] != NULL )
    {
        printf("[%s]\t", commands[i]);
        i++;
    }
    printf("\n");
}

// main function
int main(int argc, char **argv)
{
    char **commands;
    int nb_parameters;
    char **list_of_numbers;

    // reading of the commands in stdin
    commands = reading_stdin();

    // Put commands
    read_list_commands(commands);

    nb_parameters = argc - 1;
    // printf("Number of parameters is: %d\n", nb_parameters);

    list_of_numbers = argv;

	// create a stack a and b
    stack *a = newStack(100);
    stack *b = newStack(100);


    // add the list of numbers to the stack
    add_parameters_to_stack(list_of_numbers, nb_parameters, a);

    // printf("Top element is %d\n", peek(a));
    // printf("Stack size is %d\n", size(a));

    // sb(b);
     push(b, 2);
     push(b, 1);
    // ss(a, b);
    //pa(a, b);
    //pb(a, b);

    // rr(a, b);

    //     printf("Top element a is %d\n", peek(a));
    //     pop(a);

    // printf("Top element a is %d\n", peek(a));

    // printf("Top element b is %d\n", peek(b));
    //     pop(b);

    // printf("Top element b is %d\n", peek(b));
    // printf("Top element is %d\n", peek(a));
    // pop(a);
    // printf("Top element is %d\n", peek(a));

    // pop(a);
    // printf("Top element is %d\n", peek(a));

    //free malloc of array of trings (commands)

    rra(a, b);
    printf("Top element is %d\n", peek(a));
    pop(a);
    printf("Top element is %d\n", peek(a));
    pop(a);
    printf("Top element is %d\n", peek(a));
    pop(a);
    printf("Top element is %d\n", peek(a));


    free_memory(commands);

    return 0;
}
