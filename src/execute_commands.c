#include "../header_file.h"

void execute_commands(char **commands, stack *a, stack *b)
{

    int i = 0;
    while(commands[i]) 
    {
        printf("[%s]\n", commands[i]);
        if (strcmp(commands[i], "sa") == 0) 
        {
                    printf("test sa");

            sa(a);
        } 
        else if (strcmp(commands[i], "sb") == 0)
        {
                sb(b);
        }
        else if (strcmp(commands[i], "ss") == 0)
        {
                ss(a, b);
        }
        else if (strcmp(commands[i], "pa") == 0)
        {
                pa(a, b);
        }
        else if (strcmp(commands[i], "pb") == 0)
        {
                                printf("test pb");

                pb(a, b);
        }
        else if (strcmp(commands[i], "ra") == 0)
        {
                ra(a, b);
        }
        else if (strcmp(commands[i], "rb") == 0)
        {
                rb(a, b);
        }
        else if (strcmp(commands[i], "rr") == 0)
        {
                rr(a, b);
        }
        else if (strcmp(commands[i], "rra") == 0)
        {
                rra(a, b);
        }
        else if (strcmp(commands[i], "rrb") == 0)
        {
                rrb(a, b);
        }
        else if (strcmp(commands[i], "rrr") == 0)
        {
                rrr(a, b);
        }
        /* more else if clauses */
        else /* default: */
        {
            printf("Invalid operations\n" );
            exit(EXIT_FAILURE);
        }
        i++;
        print_stack(a);

    }
}