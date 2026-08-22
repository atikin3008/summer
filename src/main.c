#include <stdio.h>
#include <stdlib.h>
#include "../include/types.h"
#include "../include/io.h"
#include "../include/solve.h"
#include <math.h>


int solveFIN(struct InputSettings inputSettings);

int solveCIN(struct InputSettings inputSettings);


int main(int argc, char *argv[]) {
    struct InputSettings inputSettings = getArgs(argc, argv);
    if (inputSettings.typeRead == FIN) {
        return solveFIN(inputSettings);
    } else if (inputSettings.typeRead == CIN) {
        return solveCIN(inputSettings);
    } else if (inputSettings.typeRead == HELP) {
        return 0;
    }
    return inputSettings.typeRead;
}

int solveFIN(struct InputSettings inputSettings) {
    while (true) {
        double a = 0, b = 0, c = 0;
        enum Read e = readFileString(&a, &b, &c, inputSettings);
        if (e == END) {
            closeFiles(inputSettings);
            return 0;
        } else if (e == FAIL) {
            closeFiles(inputSettings);
            return 1;
        } else if (e == DONE) {
            double x1 = 0, x2 = 0;
            enum RootType rootType = solveSquareEquation(a, b, c, &x1, &x2);
            printAnswer(rootType, x1, x2, inputSettings);
        }
    }
}


void drawGraphic(double a, double b, double c);

int solveCIN(struct InputSettings inputSettings) {
    printf("Программа решающая квадратное уравнение\n\n");
    double a = 0, b = 0, c = 0;
    if (readDouble(&a, 'a') == FAIL || readDouble(&b, 'b') == FAIL || readDouble(&c, 'c') == FAIL) {
        printf("ОШИБКА ВВОДА!\n");
        return 1;
    }
    double x1 = 0, x2 = 0;
    enum RootType rootType = solveSquareEquation(a, b, c, &x1, &x2);
    printAnswer(rootType, x1, x2, inputSettings);
    closeFiles(inputSettings);
    fflush(stdout);
    if (inputSettings.gui)
        drawGraphic(a, b, c);

    return 0;
}

