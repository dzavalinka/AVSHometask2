//
// Created by Daniil Zavalinskii on 13.01.2022.
//

#include "movie.h"
#include <cstdio>

class Fiction : public Movie {
public:
    ~Fiction() override = default;

    // Ввод параметров из файла
    void In(FILE *file) override;

    // Случайный ввод параметров
    void InRandom() override;

    // Вывод параметров в форматируемый поток
    void Out(FILE *file) override;

    double Function() override;

private:
    const char *name;
    const char *director;
    int year;
};

