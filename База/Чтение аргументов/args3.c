#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PATH "./arg"

int main()
{
    char* arg[] = {"1 arg", "2 arg", "3 arg", NULL};    
    execve(PATH, arg, NULL);
    return 0;
}
