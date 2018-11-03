#include "../header_file.h"

// add parameters to the stack function
void add_parameters_to_stack(char **parameters, int nb_parameters, stack *pt)
{
    int i;
    int array[5];

    for(i = 1; i <= nb_parameters; i++)
    {
        array[nb_parameters - i] = atoi (parameters[i]);
    }
    printf("\n");

    for(i = 0; i < nb_parameters; i++)
    {
        printf("%d\t", array[i]);
        push(pt, array[i]);

    }
        printf("\n");
}