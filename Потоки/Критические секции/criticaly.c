#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER; // создаем и инициализируем мьютекс (взаимное исключение, только 1 поток может работать)
int count = 0;                                   // счетчик

void *counter(void *arg)
{
    pthread_mutex_lock(&mtx); // блокируем для других потоков
    for (int i = 0; i < *(int *)arg; i++)
    {
        count++;
        
    }
    pthread_mutex_unlock(&mtx); // разблокируем для других потоков
}

int main()
{
    pthread_t pt1, pt2; // создали дискрипторы для потока

    int n = 100000; // количество итераций в цикле

    pthread_create(&pt1, NULL, counter, &n); // создаем поток 1
    pthread_create(&pt2, NULL, counter, &n); // создаем поток 2

    pthread_join(pt1, NULL); // ждем 1 поток
    pthread_join(pt2, NULL); // ждем 2 поток
    
    printf("Конечное значение %d\n", count);
}