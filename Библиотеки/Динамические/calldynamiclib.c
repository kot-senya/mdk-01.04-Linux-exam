#include <stdio.h>//библиотека для стандартных функций ввода-вывода
#include <dlfcn.h>//библиотека для работы с разделяемыми библиотеками

typedef void (*fundll)(char*);
int main()
{
    void * libhandle = dlopen("./libdynamic.so",RTLD_LAZY);//подключаем библиотеку
    fundll showMess = dlsym(libhandle,"message");//импортируем функцию для вывода сообщений
    int (*funPov)(int) = dlsym(libhandle,"pov");//импортируем функцию для возведения в степень

    char str[20] = "Привет мир!\n"; //инициализация строки
    showMess(str); //вызов библиотечной функции (вывод сообщения)
    
    int x = funPov(2); //вызов библиотечной функции (возведение в степень)
    printf("%d\n", x);//вывод результата в консоль

    return 0;
}