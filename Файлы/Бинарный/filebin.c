/*
Программа для считывания числового значения из файла (с сохранением его в числовом формате).
Исходный файл является бинарным.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <sys/stat.h> //содержатся флаги режимов доступа к файлам (mode)
#include <fcntl.h>    //содержатся флаги открытия файлов (flags)

double readfile(char *path)
{
    FILE *fd = fopen(path, "rb"); // открываем файл для чтения бинарных файлов
    if (fd == NULL)               // если не открылся выходим
    {
        printf("Не удалось открыть файл для чтения %s\n", path);
        exit(-1);
    }

    int size = 1000;                             // размер буфера
    double buf;                                  // буфер
    int nr = fread(&buf, sizeof(double), 1, fd); // читаем в буфер
    if (nr == -1)                                // если не получилось прочитать
    {
        printf("Не удалось прочитать файл %s\n", path);
        exit(-1);
    }

    fclose(fd); // закрываем дискриптор

    return buf; // возвращаем строку
}
/*
void writefile(char *path, double answer)
{
    FILE *fd = fopen(path, "wb"); // открываем файл для записи бинарных файлов
    if (fd == NULL)               // если не открылся выходим
    {
        printf("Не удалось открыть файл для записи %s\n", path);
        exit(-1);
    }
    int nw = fwrite(&answer, sizeof(double), 1, fd); // пишем
    if (nw == -1)                                                // если не получилось записать
    {
        printf("Не удалось записать в файл %s\n", path);
        exit(-1);
    }

    fclose(fd); // закрываем дискриптор
}
*/
int main()
{

    char *path = "./file.bin";

    //writefile(path, 121);           // пишем письмо
    double letter = readfile(path); // читаем
    printf("%f\n", letter);
    printf("\nесли вы дошли до сюда, то все гуд\n");
}