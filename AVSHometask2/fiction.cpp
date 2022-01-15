//
// Created by Daniil Zavalinskii on 13.01.2022.
//

#include "fiction.h"

void Fiction::In(FILE *file) {
    name = Utils::readStr(file);
    year = Utils::readInteger(file);
    director = Utils::readStr(file);
}

void Fiction::InRandom() {
    name = Utils::randomStr(Utils::rndInteger(5, 10));
    year = Utils::rndInteger(1950, 2021);
    director = Utils::randomStr(Utils::rndInteger(5, 10));
}

void Fiction::Out(FILE *file) {
    fprintf(file,
            "Fiction film: name - %s, year of release - %d, director - %s\n",
            name,
            year,
            director);
}

double Fiction::Function() {
    return static_cast<double>(year) / static_cast<double>(strlen(name));
}
