/*Создание функции, аргументом которой является указатель на функцию. 
Создать не менее двух вспомогательных функций и передать их в качестве аргумента исходной функции. 
Продемонстрировать специфику работы исходной функции в зависимости от переданных параметров*/

#include<stdio.h>
#include<stdlib.h>

typedef int(*fun)(int); //переопределяем такой вид функции

int mult2(int n) //функция умножения на 2
{
    return n * 2;
}

int div2(int n) //функция деления на 2
{
    return n / 2;
}

void call(fun callfun, int n)
{
    printf("Результат работы функции = %d\n", callfun(n));//выводим результат работы функции
}

int main()
{
    //вызываем функции
    call(div2, 4);
    call(mult2, 4);
}