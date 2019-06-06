#include "./header_file.h"

#include <stdio.h> // for printf

// main function
int main(int argc, char **argv)
{
    printf("start\n");

    int nb_parameters;
    char **list_of_numbers;

	// create a stack a and b
    stack *a = newStack(100);
    // stack *b = newStack(100);

    nb_parameters = argc - 1;

    list_of_numbers = argv;

    // add the list of numbers to the stack
    add_parameters_to_stack(list_of_numbers, nb_parameters, a);

    return 0;
}
