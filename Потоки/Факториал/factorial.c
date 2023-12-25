#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> //для работы с потоками

void *fact(void *arg)
{
    int num = (int *)arg; // приводим к виду числа

    if (num < 0) // проверяем не отрицательное ли число
    {
        printf("число не может быть меньше 0\n"); // сообщение об ошибки
        return -1;                                // заканчиваем программу
    }
    if (num == 0) // проверяем = 0
    {
        printf("факториал %d = 1\n", num); // сообщение
        return 0;                          // заканчиваем программу
    }

    int startnum = 1; // начальная позиция
    for (int i = 0; i < num; i++)
    {
        startnum *= i + 1; // вычисляем факториал
    }
    printf("факториал %d = %d\n", num, startnum); // сообщение
    return 0;                                     // заканчиваем программу
}

int main()
{
    pthread_t pth;                               // поток
    int n = 5;                                   // число для работы
    int s = pthread_create(&pth, NULL, fact, n); // создаем поток
    sleep(5);
}