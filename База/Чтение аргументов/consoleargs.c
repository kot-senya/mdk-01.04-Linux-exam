#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]) 
{
    for(int i = 0; i < argc; i++)
    {
        printf("%d аргумент: %s\n", i+1, argv[i]);
    }
}