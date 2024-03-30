#include "myShell.h"
#include "myFunction.h"

int main()
{
    welcome();
    while (1)
    {
        getLocation();
        int piping = 0;
        getLocation();
        char *input = getInputFromUser();
        if (strcmp(input, "exit") == 0 || strncmp(input, "exit ", 5) == 0)//first condition checks if the input is exactly as the word exit
        //the second condition checks for a specified number of chars, in this case 5 needed.
        logout(input);


        char **arguments = splitArgument(input);
        if(strcmp(arguments[0], "exit") == 0){ //This covers the case where there is space in the begining of the string
            free(arguments);
            logout(input);
}
        int i=0;
        while(*(arguments+i)!=NULL){
            puts(*(arguments+i));
            i++;
        }
        if (strcmp(input, "echo") == 0)
            echo(arguments);
        else if (strcmp(input, "cd") == 0)
            cd(arguments);
        else if (strcmp(input, "cp") == 0)
            cp(arguments);
        else if (strcmp(input, "delete") == 0)
            delete (arguments);
        else if (strcmp(input, "dir") == 0)
            get_dir(arguments);
        else if (piping)
        {
            
            mypipe(arguments, arguments+/*indexPipe*/+1);
            wait(NULL);
        }
        else
        {
            systemCall(arguments);
            wait(NULL);
        }
        free(arguments);
        free(input);
    }
    return 0;
}





                                        
void welcome()
{
    printf("**********************************************************| Welcome to myShell   \n");
    printf("                                                          | Version 2.4.3     \n");
    printf("**********************************************************|       \n");
    printf("                                                          | https://github.com/benny6789/OS2024.git \n");
    printf("**********************************************************|                                         \n");
    printf("                                                          |                                         \n");
    printf("BBBBBBBBB  EEEEEEEE  NNN     NN  NNN     NN  YY      YY   |                   B                      \n");
    printf("BBB   BBB  EEE       NNNN    NN  NNNN    NN   YY    YY    |             B   B   B   B                   \n");
    printf("BBB   BBB  EEEE      NN NN   NN  NN NN   NN    YY  YY     |               B       B                    \n");
    printf("BBBBBBBBB  EEEEEEEE  NN  NN  NN  NN  NN  NN      YY       |             B   B   B   B               \n");
    printf("BBB   BBB  EEE       NN   NN NN  NN   NN NN      YY       |                   B             \n");
    printf("BBB   BBB  EEEEEEEE  NN    NNNN  NN    NNNN      YY       |                                         \n");
    printf("                                                          |                                         \n");
    printf("**********************************************************|  Life is like a ostrich chasing you   \n");
    printf("                                                          |  down the corridor         \n");
    printf("**********************************************************|      \n");
    printf("                                                          |  -- Benny Tryster         \n");
    printf("**********************************************************|           \n");




    
}