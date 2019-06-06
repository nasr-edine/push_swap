#include "./header_file.h"
#include<limits.h> 

void printRepeating(int arr[], int size) 
{ 
  int i, j; 
  for(i = 0; i < size; i++) 
    for(j = i+1; j < size; j++) 
      if(arr[i] == arr[j]) 
      {
            printf("Error\n");
            printf("[duplicate]\n"); 
            exit(EXIT_FAILURE);
      }
}      
  
// add parameters to the stack function
void add_parameters_to_stack(char **parameters, int nb_parameters, stack *pt)
{
    int i;
    int array[5];

    for(i = 1; i <= nb_parameters; i++)
    {
        long num;
 
        num = atol(parameters[i]);
        printf("[%ld]\n", num);

        // check if number overflow int
        if( num > INT_MAX || num < INT_MIN ) 
        {
            printf("Error\n");
            printf("overflow int\n");
            exit(EXIT_FAILURE);
        }


        if (num == 0 && parameters[i][0] != '0')
        {
            printf("Error\n");
            printf("Not a Number!");
            exit(EXIT_FAILURE);
        }
        else
           array[nb_parameters - i] = num;
    }

    printRepeating(array, nb_parameters); 

    for(i = 0; i < nb_parameters; i++)
    {
        //printf("%d\t", array[i]);
        push(pt, array[i]);

    }
       // printf("\n");
}