#include <unistd.h> //для стандартных функций ввода-вывода
#include <stdio.h>  //для использования системных функций линукса
#include <sys/wait.h>
#include <stdlib.h>

void message()
{
    int count = 0; // счетчик
    char str[100]; // для сообщения в консоль

    while (1) // бесконечный цикл
    {
        // записываем строку вызова всплывающего окна
        sprintf(str, "notify-send \"Текущее значение: %d\" ", count);
        system(str); // вызываем всплывающее окно
        count++;     // увеличиваем
        sleep(5);    // спим 5 секунд
    }
}

int main()
{
    switch (fork()) // рождаем ребенка
    {
    case -1: // аборт
        exit(-1);
    case 0: // ребенок выходит
        break;
    default:
        exit(EXIT_SUCCESS); // убиваем родителя
    }

    if (setsid() == -1) // проверяем стал ли процесс главой сеанса
        return -1;      // выходим если не прокатило

    message();
}