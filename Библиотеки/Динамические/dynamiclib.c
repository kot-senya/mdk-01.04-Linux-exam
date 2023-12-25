#include <stdio.h> //библиотека для стандартных функций ввода-вывода

void message(char* mes)//функция выводящая сообщение
{
    printf("%s\n", mes);
}

int pov(int n)//функция возведения числа во 2 степень
{
    return n * n;
}