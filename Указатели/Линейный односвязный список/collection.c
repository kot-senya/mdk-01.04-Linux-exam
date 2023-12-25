/*Создание линейного односвязного списка из n элементов.
Значение элемента генерируется случайным образом.
Поместить в отдельные указатели адрес минимального и максимального элемента списка.
Вывести список и значения минимального и максимального элемента через указатель.*/

#include <stdio.h>
#include <stdlib.h>

struct _elem // элемент списка
{
    int n;
    struct _elem *next;
};

typedef struct _elem Elem;
typedef Elem *List;

List createList(int n)
{
    if (n < 1)
        return NULL;

    List list = calloc(1, sizeof(Elem)); // выделяем память под элемент, а не лист
    list->n = rand() % 100;              // генерируем число до 100
    List head = list;                    // запоминаем голову чтобы не терять
    for (int i = 1; i < n; i++)
    {
        List newelem = calloc(1, sizeof(Elem)); // создаем новый элемент
        newelem->n = rand() % 100;              // генерируем число до 100
        list->next = newelem;                   // выстраиваем цепочку, предыдущий элемент ссылается на новый
        list = list->next;                      // переходим на новый элемент
    }
    list->next = NULL; // последний лист ссылается на NULL
    return head;
}

void show(List list)
{
    if (!list)
        return NULL;

    while (list) // пока элементы есть
    {
        printf("%d\n", list->n); // показываем элементы
        list = list->next;       // переходим на следующий элемент
    }
}

List minelem(List list)
{
    List elem = list; // 1 - элемент пока самый маленький
    while (list) // ходим пока есть ал листа
    {
        if (list->n < elem->n) // если меньше - то переобуваем маленького
            elem = list;

        list = list->next; // шагаем дальше
    }
    return elem; // возвращаем маленького
}

List maxelem(List list)
{
    List elem = list; // 1 - элемент пока самый большой
    while (list) // ходим пока есть ал листа
    {
        if (list->n > elem->n) // если меньше - то переобуваем большого
            elem = list;

        list = list->next; // шагаем дальше
    }
    return elem; // возвращаем большлго
}
int main()
{
    int n = 5; // коллекция элементов
    List list = createList(n);
    show(list);
    printf("min: %d max: %d\n", minelem(list)->n, maxelem(list)->n);
}