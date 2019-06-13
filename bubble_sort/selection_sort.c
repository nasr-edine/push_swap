#include <stdio.h>

main(int argc, char const *argv[])
{
    
    int array[5] = {64, 25, 12 ,22, 11};
    int min = 0;

    int temp;
    int index;

for(size_t i = 0; i < 4; i++)
{
    min = array[i];
    for(size_t j = i + 1; j < 5; j++)
    {
        printf("[%d]", array[j]);
        
        if (array[j] < min) 
        {
            min = array[j];
            index = j;
        }
    }
    printf("\n");
    printf("min: %d\n", min); 

    temp = array[i];
    array[i] = array[index];
    array[index] = temp;
}

for(size_t i = 0; i < 5; i++)
{
            printf("[%d]", array[i]);

}

    return 0;
}
