#include <stdio.h>
#include <stdlib.h>
#include "../include/types.h"
#include "../include/io.h"
#include "../include/solve.h"






int main(int argc, char *argv[]) {
    if (argc == 2) {
        char *endpointer = nullptr;
        EPS = strtod(argv[1], &endpointer);
    }
    double a = 0, b = 0, c = 0;
    if (read(&a, &b, &c) == FAIL) {
        printf("ОШИБКА ВВОДА!\n");
        return 1;
    }
    double x1, x2;
    enum RootType rootType = solveSquareEquation(a, b, c, &x1, &x2);
    print(rootType, x1, x2);


}
