/*
 Отправка и получение данных из именованного канала. Данные содержатся в строковой форме. Перед отправкой следующей строки клиенту необходимо дождаться ответа от сервера
*/

#include <unistd.h>   //для использования системных функций линукса
#include <stdio.h>    //для стандартных функций ввода-вывода
#include <stdlib.h>   //для работы с памятью (free)
#include <string.h>   //для работы со строками
#include <malloc.h>   //для работы с динамическим выделением памяти (calloc)
#include <sys/stat.h> //для работы с очередями FIFO
#include <fcntl.h>    //O_... - флаги для открытия FIFO

#define PATH "/tmp/FIFOserver" // путь к файлу FIFO
#define MESSAGE "End world"

struct DATA // структура, в которой содержится передаваемая от клиента информация
{
    char clientFIFOPath[20]; // имя канала откуда пришло
    char str[1000];
};

typedef struct DATA DATA;

int main()
{
    mkfifo(PATH, 0664);                              // создаем очередь со следующими правами (Для всех групп - значение константно): rw user, rw group, r other
    write(STDOUT_FILENO, "сервер запустился\n", 35); // сообщение при старте сервера
    // STDOUT_FILENO - дескриптор файла для стандартного вывода.

    DATA data;

    for (;;) // бесконечный цикл
    {
        int fifoRead = open(PATH, O_RDONLY); // O_NONBLOCK - чтобы не блокировалась система. O_RDONLY заблокирует систему до тех пор, пока в нее кто-либо не напишет
        read(fifoRead, &data, sizeof(DATA)); // считываем данные от клиента
        close(fifoRead);                     // закрываем дескриптор для чтения

        printf("Подключился клиент со следующими данными: имя канала: %s, передаваемые данные %s\n", data.clientFIFOPath, data.str);

        int fifowrite = open(data.clientFIFOPath, O_WRONLY); // открываем очередь на запись для клиента
        write(fifowrite, MESSAGE, sizeof(MESSAGE));          // записываем в канал клиента ответ
        close(fifowrite);                                    // закрываем дескриптор для записи
    }
}
