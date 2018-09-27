#include "Includes.h"

void getSomeEnv()
{
    printf("PATH : %s\n", getenv("PATH"));
    printf("HOME : %s\n", getenv("HOME"));
    printf("ROOT : %s\n", getenv("ROOT"));
}

void systemCmd()
{
    char command[50];

    #ifdef __unix__
        strcpy(command, "mkdir /test/dir");
    #else
        strcpy(command, "mkdir test\\dir"); // escape the \ or it sees it as \d (which doesn't exist)
    #endif

    printf("\nCommand = %s", command);
    system(command);
}
