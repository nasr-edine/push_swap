#include "../header_file.h"

int  is_stack_sort(stack *s)
{
    stack *tmp = newStack(100);

    int length_stack = size(s);

    // printf("size: %d\n", length_stack);
    int top_b = peek(s);
    while(length_stack-- > 1) 
    {
        // printf("[%d]", top_b);
        pop(s);
        push(tmp, top_b);
        int top_a = peek(s);
        if(!(top_b < top_a))
        {
            return -1;
        }
        top_b = top_a;
    }    
    return 0;
}