#include "../header_file.h"

void free_memory(char **commands)
{
    int i = 0;
    while(commands[i] != NULL )
    {
        //iterate again, freeing each index
        free(commands[i]);
        i++;
    }
    // free terminator of array
    free(commands[i]);
    //free the main handle
    free(commands);
}
