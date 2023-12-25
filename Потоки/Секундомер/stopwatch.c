#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //для системных штук (pause)
#include <pthread.h> //для работы с потоками
#include <time.h>    //для работы со временем

#define NAV_STR "Нажмите 1 - чтобы остановить, 2 - чтобы начать сначала, other - чтобы выйти"

int flag = 0;
pthread_t cid;

void *stoptime(void *arg)
{
    cid = pthread_self();
    time_t start;       // начало времени
    time_t end;         // конец
    int hour, min, sec; // переменные для времени
    time(&start);       // задаем начальное время

    while (1)
    {
        system("clear");                   // чистим консоль
        time(&end);                        // узнаем сколько сейчас времени
        double dif = difftime(end, start); // находим разницу (сек)

        // переводим время
        if (dif < 60) // если меньше минуты
        {
            hour = 0;
            min = 0;
            sec = (int)dif;
        }
        else if (dif < 3600) // если меньше часа
        {
            hour = 0;
            min = (int)dif % 3600 / 60;
            sec = dif - (min * 60);
        }
        else
        {
            hour = dif / 3600;
            min = (int)dif % 3600 / 60;
            sec = dif - (min * 60) - (hour * 3600);
        }
        printf("%d:%d:%d\n\n%s %d\n", hour, min, sec, NAV_STR, flag); // выводим время
        sleep(1);
    }
}

int main()
{
    pthread_t pth;
    system("pause");

    int s = pthread_create(&pth, NULL, stoptime, NULL);

    while (1)
    {
        switch (getchar())
        {
        case '1':
        {
            pthread_cancel(cid);
            break;
        }
        case '2':
        {
            flag = 0;
            s = pthread_create(&pth, NULL, stoptime, NULL);
            break;
        }
        default:
            exit(0);
        }
    }
}