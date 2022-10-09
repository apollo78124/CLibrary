#include <stdio.h>
#include "main_header.h"

int main() {
    char* filePath;
    char* fileName;

    char* fileExpressions[] = {"/root/Documents/client/A Tale of Two Cities.txt", "/root/Documents/client/foo.txt"}, **filePath1;
    filePath1 = fileExpressions;
    //Loop through file expressions and send each of them.

    for (size_t i = 0; i < sizeof(fileExpressions) / sizeof(fileExpressions[0]); i++)
    {
        strcpy(filePath,fileExpressions[i]);
        fileName = getFileNameFromFilePath(fileExpressions[i]);


        printf("%s\n", filePath);
        printf("%s\n", fileName);
    }
    close(filePath);
    close(fileName);
    close(fileExpressions);
    close(filePath1);
    return 0;
}


void loopThroughStringArray(char tempString3[]) {
    char* fileExpressions11[] = {"/root/Documents/client/A Tale of Two Cities.txt", "/root/Documents/client/foo.txt"}, **fff;
    fff = fileExpressions11;
    while(*fff != "") {
        printf("%s\n", *fff++);
    }
}

char* getFileNameFromFilePath(char tempString4[]) {
    char *stringToTest = strdup(tempString4);
    char *token = strtok(stringToTest, "/");
    char *tokenBefore;
    while (token != NULL) {
        tokenBefore = token;
        token=strtok(NULL, "/");
    }
    close(stringToTest);
    return tokenBefore;
}
