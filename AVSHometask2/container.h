//
// Created by Daniil Zavalinskii on 13.01.2022.
//

#ifndef __container__
#define __container__

// container.h - содержит тип данных, представляющий простейший контейнер

#include "movie.h"
#include <cstdio>

class Container {
public:
    Container();

    ~Container();

    // Ввод содержимого контейнера из указанного потока.
    void In(FILE *file);

    // Случайный ввод содержимого контейнера.
    void InRnd(int size);

    // Вывод содержимого контейнера в указанный поток.
    void Out(FILE *file);

    // Сортировка по убыванию.
    void InsertionSort();

private:
    int length;
    Movie *container[10000]{};
};

#endif
