#include <sys/stat.h> //mkfifo, S_I...- для работы с очередями FIFO, флаги
#include <fcntl.h>    //O_... - флаги для открытия FIFO
#include <unistd.h>   //для использования системных функций линукса
#include <stdio.h>    //для стандартных функций ввода-вывода
#include <stdlib.h>   //для работы с памятью (free)
#include <string.h>   //для работы со строками

#define PATHSERVER "/tmp/FIFOserver" // общедоступное имя сервера
#define PATHCLIENT "/tmp/FIFOclient" // имя конкретного клиента
#define MESSAGE "Hello world"

struct DATA // структура для обмена данными с сервером
{
    char clientFIFOPath[20];
    char str[1000];
};

typedef struct DATA DATA;

int main()
{
    mkfifo(PATHCLIENT, 0664); // создаем очередь со следующими правами (Для всех групп - значение константно): rw user, rw group, r other

    int fifoWrite = open(PATHSERVER, O_WRONLY); // открываем очередь на запись для сервера
    DATA data = {PATHCLIENT, MESSAGE};          // инициализация объекта

    write(fifoWrite, &data, sizeof(DATA)); // пишем письма
    close(fifoWrite);                      //

    int fifoRead = open(PATHCLIENT, O_RDONLY); // открываем очередь на чтение для клиента
    char *answer = calloc(1000, sizeof(char)); // ответик
    read(fifoRead, answer, sizeof(answer));    // читаем
    printf("Ответ сервера: %s\n", answer);     // выводим
    free(answer);
}