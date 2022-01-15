#include "documentary.h"
#include <cstdio>

void Documentary::In(FILE *file) {
    name = Utils::readStr(file);
    year = Utils::readInteger(file);
    duration = Utils::readInteger(file);
}

void Documentary::InRandom() {
    name = Utils::randomStr(Utils::rndInteger(5, 10));
    year = Utils::rndInteger(1950, 2021);
    duration = Utils::rndInteger(1, 100);
}

void Documentary::Out(FILE *file) {
    fprintf(file,
            "Documentary film: name - %s, year of release - %d,  duration - %d\n",
            name,
            year,
            duration);
}

double Documentary::Function() {
    return static_cast<double>(year) / static_cast<double>(strlen(name));
}