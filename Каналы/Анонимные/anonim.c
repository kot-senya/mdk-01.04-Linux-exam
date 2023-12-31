// Использование анонимного канала для передачи строковых значений между процессами

#include <stdio.h>  //для стандартных функций ввода-вывода
#include <unistd.h> //для использования системных функций линукса
#include <string.h> //для работы со строками (strlen)
#include <stdlib.h> //для работы с памятью (free)
#include <malloc.h> //для работы с динамическим выделением памяти (calloc)
#include <sys/wait.h>

#define BUF_SIZE 40                  // размер буфера - именно по столько символов разделяться передаваемое сообщение
#define MESSAGE "Йо, меня прочитали" // сообщение
                                     //можно сделать чтобы оно вводилось в ручную

int main()
{
    system("chcp 1251 > null");

    int pfd[2]; // файловые дескрипторы канала
    /*
    канал имеет 2 конца:
    0 - конец для чтения
    1 - конец для записи
    */
    ssize_t numRead;

    if (pipe(pfd) == -1) // Создаем канал
        _exit(1);        // в случае ошибки завершаем работу программы

    // работаем с процессами
    switch (fork()) // делаем ребенка
    {
    case -1: // ошибка при создании дочеренго процесса
        _exit(1);

    case 0: // бебик - потомок только читает данные из канала
    {
        if (close(pfd[1]) == -1) // если не получилось закрыть конец для записи - выходим принудительно
            _exit(1);

        do // Считываем данные из канала до тех пор, пока он не опустеет
        {
            char *buf = calloc(1, BUF_SIZE);       // создаем буфер для чтения
            numRead = read(pfd[0], buf, BUF_SIZE); // операция блокируется до тех пор, пока в канал не поступят данные

            if (numRead == -1)
                _exit(1);

            printf("Родитель написал: %s\n", buf); // выводим на экран то, что прочитали

            free(buf); // очищаем буфер
        } while (numRead != 0);

        if (close(pfd[0]) == -1) // если не получилось закрыть конец для чтения - выходим принудительно
            _exit(1);

        _exit(0); // заканчиваем существование дочеренго  процесса
    }
    default: // родитель - только записывает в канал
    {
        if (close(pfd[0]) == -1) // если не получилось закрыть конец для чтения - выходим принудительно
            _exit(1);

        /* Пример с со своим вводом
        char *str = calloc(100, sizeof(char));
        gets(str, 100);
        write(pfd[1], str, strlen(str));*/

        if (write(pfd[1], MESSAGE, strlen(MESSAGE)) != strlen(MESSAGE))
            _exit(1);

        if (close(pfd[1]) == -1) // Потомок увидит символ завершения файла
            _exit(1);

        wait(NULL); // Ждем завершения потомка

        _exit(0); // успешно завершаем процесс
    }
    }
}