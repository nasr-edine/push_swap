#include "../header_file.h"

read_list_commands(char **commands)
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
    printf("Number of parameters is: %d\n", nb_parameters);

    list_of_numbers = argv;

	// create a stack of capacity number of parameters
    stack *pt = newStack(nb_parameters);


    // add the list of numbers to the stack
    add_parameters_to_stack(list_of_numbers, nb_parameters, pt);

    printf("Top element is %d\n", peek(pt));
    printf("Stack size is %d\n", size(pt));

    pop(pt);
    pop(pt);

	if (isEmpty(pt))
	    printf("Stack is empty");
	else
		printf("Stack is not empty");


    //free malloc of array of trings (commands)
    free_memory(commands);


    return 0;
}
