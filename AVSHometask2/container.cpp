#include <cstdio>
#include "container.h"

// Конструктор контейнера.
Container::Container() : length{0} {}

// Деструктор контейнера.
Container::~Container() {
    for (int i = 0; i < length; i++) {
        delete container[i];
    }
    length = 0;
}

// Ввод содержимого контейнера из указанного потока.
void Container::In(FILE *file) {
    while (!feof(file)) {
        if ((container[length] = Movie::StaticIn(file)) != nullptr) {
            length++;
        }
    }
}

// Случайный ввод содержимого контейнера.
void Container::InRnd(int size) {
    while (length < size) {
        if ((container[length] = Movie::StaticInRnd()) != nullptr) {
            length++;
        }
    }
}

// Вывод содержимого контейнера в указанный поток.
void Container::Out(FILE *file) {
    fprintf(file, "Container contains %d elements.\n", length);

    for (int i = 0; i < length; i++) {
        fprintf(file, "%d: ", i + 1);
        container[i]->Out(file);
    }
}

// Сортировка.
void Container::InsertionSort() {
    for (int i = 0; i < length; ++i) {
        Movie *key = container[i];
        int j = i - 1;
        while (j >= 0 && key->Function() > container[j]->Function()) {
            container[j + 1] = container[j];
            --j;
        }
        container[j + 1] = key;
    }
}