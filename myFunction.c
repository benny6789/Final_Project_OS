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

// עליכם לממש את הפונקציה strtok כלומר שהפונקציה הנ"ל תבצע בדיוק אותו הדבר רק בלי השימוש בפונקציה strtok
char **splitArgument(char *str)
{
    // cp file file
    //[cp,file,file,NULL]
    char *subStr;
    // cp\0file file
    // hello1\0hello2\0hello3\0hello4\0
    // subStr = address of 'h'
    // str = address of 'h'
    // int i=0;
    // int startIndex=0;
    // while(*str+i!=' '){
    // }
    // *(str+i)='\0';
    // // [str+startIndex,]
    // startIndex=++i;
    // while(*str+i!=' '){
    // }
    // *(str+i)='\0';
    // // [str+startIndex,str+startIndex]
    // startIndex=++i;

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

// בכל שינוי יש לבצע קומיט מתאים העבודה מחייבת עבודה עם גיט.
// ניתן להוסיף פונקציות עזר לתוכנית רק לשים לב שלא מוסיפים את חתימת הפונקציה לקובץ הכותרות