/*Программа для считывания и записи строкового значения из текстового файла
 с последующей записью его в другой текстовый файл.
 Для работы с файлами используются функции Linux.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> //содержатся флаги режимов доступа к файлам (mode)
#include <fcntl.h>    //содержатся флаги открытия файлов (flags)

char *readfile(char *path)
{
    int fd = open(path, O_RDONLY, S_IRWXG | S_IRWXU | S_IRWXO); // открываем файл на чтение для всех групп
    if (fd == -1)                                               // если не открылся выходим
    {
        printf("Не удалось открыть файл для чтения %s\n", path);
        exit(-1);
    }

    int size = 1000;                        // размер буфера
    char *buf = calloc(size, sizeof(char)); // буфер, память выделяем

    int nr = read(fd, buf, size); // читаем в буфер
    if (nr == -1)                 // если не получилось прочитать
    {
        printf("Не удалось прочитать файл %s\n", path);
        exit(-1);
    }

    close(fd); // закрываем дискриптор

    return buf; // возвращаем строку
}
void writefile(char *path, char *answer)
{
    int fd = open(path, O_WRONLY, S_IRWXG | S_IRWXU | S_IRWXO); // открываем файл на запись для всех групп
    if (fd == -1)                                               // если не открылся выходим
    {
        printf("Не удалось открыть файл для записи %s\n", path);
        exit(-1);
    }

    int nw = write(fd, answer, strlen(answer)); // пишем
    if (nw == -1)                               // если не получилось записать
    {
        printf("Не удалось записать в файл %s\n", path);
        exit(-1);
    }

    close(fd); // закрываем дискриптор
}

int main()
{
    char* pathToRead = "./read.txt";
    char* pathToWrite = "./write.txt";

    char* letter = readfile(pathToRead); //читаем
    writefile(pathToWrite, letter); //пишем письмо
    printf("\nесли вы дошли до сюда, то все гуд\n");
    
}