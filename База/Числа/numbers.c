#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void show(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d el - %d\n", i + 1, *arr);
        arr++;
    }
    arr -= size;
}

int *convert(char *str, int *size_i)
{
    int size = 1;                      // размер массива
    int *arr = calloc(2, sizeof(int)); // выделяем память 
    int *head = arr;
    char* newstr = calloc(1000, sizeof(char)); 
    strcpy(newstr, str);
    char *newLine = strtok(newstr, " ");  // делим по пробелу

    while (newLine != NULL) // смотрим осталась ли строка
    {
        arr = realloc(head, (size + 1) * sizeof(int)); // выделяем память
        for(int i = 0; i <size; i++)
        {
            arr++;
        }
        int el;
        while (1) //для дебилов любящих ставить несколько пробелов - коряво работает, можно в принципе и без этого только 37 стрк
        {
            int f = sscanf(newLine, "%d", &el); // перводим
            if (f == 1)
                break; // выходим если нашли элемент
            newLine = strtok(NULL, " ");
        }
        *arr = el;
        arr++;
        size++;
        newLine = strtok(NULL, " ");
    }
    arr -= size;
    *size_i = size;
    return arr;
}
int main()
{
    char *str = calloc(1000, sizeof(char));
    gets(str);
    int size;
    int *arr = convert(str, &size);
    show(arr, size);
}