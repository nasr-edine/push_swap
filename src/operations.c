#include "../header_file.h"

void swap(stack *a, stack *b)
{


    	if ((!isEmpty(a)) && !isEmpty(b))
        {
            int top_a = peek(a);
            int top_b = peek(b);

                // printf("before Top element in stack a is %d\n", top_a);
                // printf("before Top element in stack b is %d\n", top_b);

            pop(a);
            pop(b);
            push(a, top_b);
            push(b, top_a);

                // printf("after Top element in stack a is %d\n", peek(a));
                // printf("after Top element in stack b is %d\n", peek(b));


        }
}

void sa(stack *a)
{
    printf("before Top element in stack a is %d\n", peek(a));


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
        printf("after Top element in stack a is %d\n", peek(a));
}

void sb(stack *b)
{
    sa(b);
}


void ss(stack *a, stack *b)
{
    sa(a);
    sb(b);
}

void pa(stack *a, stack *b)
{
    	if (!isEmpty(b))
        {
            int top_b = peek(b);
                 printf("before Top element in stack is %d\n", peek(a));
                 printf("before Top element in stack is %d\n", peek(b));
            pop(b);
            push(a, top_b);

                 printf("after Top element in stack is %d\n", peek(a));
                 printf("after Top element in stack is %d\n", peek(b));
        }
}

void pb(stack *a, stack *b)
{
    pa(b, a);
}

void ra(stack *a, stack *b)
{
    int count = 0;
    int current_element;


    	if (!isEmpty(a))
        {
            int top_a = peek(a);
            pop(a);
            if (!isEmpty(a))
            {
                while(!isEmpty(a))
                {
                    current_element = peek(a);
                    pop(a);
                    push(b, current_element);
                    count++;
                }
                push(a, top_a);
                while(count--)
                {
                    current_element = peek(b);
                    pop(b);
                    push(a, current_element);
                }  
            }
            else {
                push(a, top_a);
            }
        }
}

void rb(stack *a, stack *b)
{
    ra(b, a);
}

void rr(stack *a, stack *b)
{
    ra(a, b);
    rb(a, b);
}