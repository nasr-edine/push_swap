#include "../header_file.h"
// la fonction ne boucle pas sur tous les instructions seulement la 1ere peut etre a cause de mon print_stack
void execute_commands(char **commands, stack *a, stack *b)
{
        int i = 0;
        while(commands[i]) 
        {
                printf("instructions (while): ");
                printf("[%s]", commands[i]);
                if (strcmp(commands[i], "sa") == 0) 
                {
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
                else /* default: */
                {
                        printf("Invalid operations\n" );
                        exit(EXIT_FAILURE);
                }
                i++;
                //print_stack(a);
        }
}