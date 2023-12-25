#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HELLO "Hello "
#define WORLD "world!"

int main()
{
    // условные конструкции: if-else if-else, switch, ()?

    // 1 - сравнение строки и ctrcat
    char *str = calloc(100, sizeof(char));
    strcpy(str, HELLO);
    strcat(str, WORLD);                                                                         // новая строка
    int flag = ("hello world" == str) ? printf("Строки равны\n") : printf("Строки не равны\n"); // сравнение 2 строк

    // 2 - определение размера строки
    int lenght = strlen(str);
    if (lenght < 12)
        printf("Строка слишком короткая\n");
    else if (lenght > 15)
        printf("Строка слишком длинная\n");
    else
        printf("Идеальная строка\n");

    // 3 - определение введенной цифры
    printf("Введите цифру ");
    switch (getchar())
    {
    case '0':
        printf("Вы ввели 0\n");
        break;
    case '1':
        printf("Вы ввели 1\n");
        break;
    case '2':
        printf("Вы ввели 2\n");
        break;
    case '3':
        printf("Вы ввели 3\n");
        break;
    case '4':
        printf("Вы ввели 4\n");
        break;
    case '5':
        printf("Вы ввели 5\n");
        break;
    case '6':
        printf("Вы ввели 6\n");
        break;
    case '7':
        printf("Вы ввели 7\n");
        break;
    case '8':
        printf("Вы ввели 8\n");
        break;
    case '9':
        printf("Вы ввели 9\n");
        break;
    default:
        printf("Вы ввели не цифру\n");
        break;
    }
}