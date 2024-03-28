#include "myFunction.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void getLocation()
{
    char location[SIZE_BUFF];
    char userName;
    
    char computerName[SIZE_BUFF];
    if (getcwd(location, SIZE_BUFF) == NULL)
        printf("Error\n");
    else
    {   printf("\033[1;32m");
        userName = getlogin();
        printf("%s","btryster");
        printf("\033[1;32m");
        printf(userName);
        printf("\033[0m");  
        printf("%s","@");
        gethostname(computerName, SIZE_BUFF);
        printf("\033[1;32m");
        printf(computerName);
        printf("%s",":");
        printf("\033[0m");
        printf("\033[1;34m");
        printf(location);
        printf("\033[0m");
        printf("%s","$");
        
    }
}

char *getInputFromUser()
{
    char ch;
    int size = 1;
    int index = 0;
    char *str = (char *)malloc(size * sizeof(char));
    while ((ch = getchar()) != '\n')
    {
        *(str + index) = ch;
        size++;
        index++;
        str = (char *)realloc(str, size);
    }
    *(str + index) = '\0';
    return str;
}

char *myStrtok(char *str, char *delimeter){
    static char *lastToken = NULL; //keeps the space of the token for feauture calls
    char *token; //pointer to current token
    char *delimiterPtr; //pointer that goes on the delemter cells


    //If str is not null set the token to be the start of the string,
    //else, use the position which is the lastToken

    if (str!=NULL){
        token  = str;
    }
    else{
        token = lastToken;
    }

    //Skip over all delimeters by using strchr which searches for the first occurrence of the 
    //character in the string pointed to by the argument .
    while(*token && strchr(delimeter,*token)){
        token++;
    }

    //If the token is at the end of the string return null
    if(!*token){
        return NULL;
    }
//find the end of the token
    for (lastToken=token+1; *lastToken && !strchr(delimeter,*lastToken); lastToken++)
    {//replace delimeter at the end with null
        if(*lastToken){
            lastToken = '\0';
            lastToken++;
        }
    }
    return token;



}

char **splitArgument(char *str)
{
   
    char *subStr;
    

    subStr = myStrtok(str, " ");
    int size = 2;
    int index = 0;
    char **argumnts = (char **)malloc(size * sizeof(char *));
    *(argumnts + index) = subStr; // [subStr,subStr,subStr,subStr,NULL]
    while ((subStr = myStrtok(NULL, " ")) != NULL)
    {
        index++;
        size++;
        argumnts = (char **)realloc(argumnts, size * sizeof(char *));
        *(argumnts + index) = subStr;
    }
    *(argumnts + (index + 1)) = NULL;

    return argumnts;
}

void logout(char *input){
    free(input);
    puts("logout");
    exit(EXIT_SUCCESS);//EXIT_SUCCESS = 0
}

void echo(char **arguments)
{

    while (*(++arguments))
        printf("%s ", *arguments);

    puts("");
}

void cd(char **path)
{
    size_t len = strlen(path[1]);//The length of the path
    if (strncmp(path[1], "\"", 1) != 0 && path[2] != NULL)
        printf("-myShell: cd: too many arguments\n");

    else if (chdir(path[1]) != 0)//If the chngeing path return a value that is not 0 then the change direcrory failed
    //There is no such directory.
        printf("-myShell: cd: %s: No such file or directory\n", path[1]);
    else if ( path[1][len - 1] != '"') {//If the last character is not " then the directory is also invalid.
        printf("-myShell: cd: %s: Invalid directory format\n", path[1]);    
}


void cp(char **arguments)
{

    if (arguments[1] ==  null || arguments[2] == null)//Those are the source file and destination file (should not be null)
    {
        puts("error");
        return;
    }
    if (arguments[3] !=  null )
    {
        puts("error");
        return;
    }
    
    char ch;
    FILE *src, *des;
    if ((src = fopen(arguments[1], "r")) == NULL)//Open the source file
    {
        puts("error");
        return;
    }

    if ((des = fopen(arguments[2], "w")) == NULL)//Open the destination file
    {
        puts("error");
        fclose(src);
        return;
    }
    while ((ch = fgetc(src)) != EOF)
        fputc(ch, des);

    fclose(src);
    fclose(des);
}

// בכל שינוי יש לבצע קומיט מתאים העבודה מחייבת עבודה עם גיט.
// ניתן להוסיף פונקציות עזר לתוכנית רק לשים לב שלא מוסיפים את חתימת הפונקציה לקובץ הכותרות