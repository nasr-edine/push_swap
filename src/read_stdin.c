#include "../header_file.h"

char ** reading_stdin()
{
    char buf[BUF_SIZE];
    int num_read = 1;
    int nb_commands = 0;
    char** stringArray;

    //get input for the number of strings
    stringArray = malloc(sizeof(char*)* 10);

    // reading standard input
    while(num_read > 0)
    {
        num_read = read(0, buf, BUF_SIZE);
        //printf("Length of String is %d\n", num_read); 

        stringArray[nb_commands] = malloc(num_read * sizeof(char));       
        strcpy(stringArray[nb_commands], buf); // copy the contents of buf to stringArray
        stringArray[nb_commands][num_read - 1] = '\0'; // replace \n by \0
        nb_commands++;
    }

    stringArray[nb_commands - 1] = NULL;

    return (stringArray);
}
