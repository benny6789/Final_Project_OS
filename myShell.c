#include "myShell.h"
#include "myFunction.h"
int main()
{
    welcome();
    while (1)
    {
        getLocation();
        char *input = getInputFromUser();
        puts(input);
        char **arguments = splitArgument(input);
        for (int i = 0; *(arguments + i) != NULL; i++)
        {
            puts(*(arguments+i));
            puts(arguments[i]);
        }

        free(arguments);
        free(input);

        break;
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