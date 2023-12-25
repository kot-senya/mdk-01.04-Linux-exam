#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HELLO "Hello "
#define WORLD "world"

int lenght(char *str) // длина строки
{
    int lenght = 0;
    printf("%d", lenght);
    while (str != "\0") // пока не конец строки ходим
    {
        lenght++; // увеличиваем длину
        str++;    // переходим на следующий символ
    }
    str -= lenght - 1; // возвращаемся в начало строки

    return lenght;
}

char *cat(char *str1, char *str2) // склейка
{
    int lenght1 = lenght(str1); // длина 1 строки
    int lenght2 = lenght(str2); // длина 2 строки

    size_t size = lenght1 + lenght2 + 1;       // размер новой строки
    char *newstr = calloc(size, sizeof(char)); // новая строка

    for (int i = 0; i < lenght1; i++) // пишем 1 строку
    {
        newstr[i] = str1[i];
    }

    for (int i = 0; i < lenght2; i++) // пишем 2 строку
    {
        newstr[i + lenght1] = str2[i];
    }
	newstr[lenght1 + lenght2] = '\0';
  
    return newstr;
}

char *numstr(int n) // конвертируем число в строку
{
    switch (n)
    {
    case 0:
        return "0";
    case 1:
        return "1";
    case 2:
        return "2";
    case 3:
        return "3";
    case 4:
        return "4";
    case 5:
        return "5";
    case 6:
        return "6";
    case 7:
        return "7";
    case 8:
        return "8";
    case 9:
        return "9";
    }
}

char *convert(int num)
{
    char *newstr = calloc(100, sizeof(char)); // создаем новую строку
    newstr = "\0";                            // делаем ее пустой
    while (1)                                 // бесконечно ходим по циклу
    {
        if (num == 0)
            break;                  // если число 0 - выходим
        int n = num % 10;           // вычисляем последнее число
        char *elem = numstr(n);     // переводим в строку
        newstr = cat(elem, newstr); // склеиваем
        num = num / 10;             // уменьшаем на последний разряд
    }
    return newstr;
}

int main()
{
    double n = 15;
    char *newnum = convert(n);
    printf("%s\n", newnum);
    /*
        char *str1 = "Hello ";
        char *str2 = "world!";
    */
    char *newstr = cat(HELLO, WORLD);
    printf("%s\n", newstr);

    return 0;
}