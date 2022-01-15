#include "container.h"
#include <cstdlib>
#include <cstring>
#include <ctime>

void firstErrorMessage() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command file <infile> <outfile>\n"
           "  Or:\n"
           "     command random <numberOfMovies> <outfile>\n");
}

void secondErrorMessage(int size) {
    printf("incorrect number of movies = %d. Set 0 < number <= 10000\n", size);
}

void thirdErrorMessage() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command file <infile> <outfile>\n"
           "  Or:\n"
           "     command random <numberOfMovies> <outfile>\n");
}

// Точка входа программы
int main(int argc, char *argv[]) {
    if (argc != 5) {
        firstErrorMessage();
        return 1;
    }
    printf("Start\n");
    Container container;
    if (!strcmp(argv[1], "-f")) {
        FILE *input = fopen(argv[2], "r");
        if (!input) {
            printf("File does not exist!");
            return 1;
        }
        container.In(input);
        fclose(input);
    } else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            secondErrorMessage(size);
            return 3;
        }
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера случайным образом.
        container.InRnd(size);
    } else {
        thirdErrorMessage();
        return 2;
    }
    FILE *second_output = fopen(argv[3], "w");
    fprintf(second_output, "Sorted container:\n");
    container.InsertionSort();
    container.Out(second_output);
    printf("Stop\n");
    fclose(second_output);
    return 0;
}