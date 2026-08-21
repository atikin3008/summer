#include <stdio.h>
#include <stdlib.h>
#include "../include/types.h"
#include "../include/io.h"
#include "../include/solve.h"

int solveFIN(struct InputSettings inputSettings);
int solveCIN(struct InputSettings inputSettings);


int main(int argc, char *argv[]) {
    struct InputSettings inputSettings = getArgs(argc, argv);
    if (inputSettings.typeRead == FIN){
        return solveFIN(inputSettings);
    }else if(inputSettings.typeRead == CIN){
        return solveCIN(inputSettings);
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
        }else if (e == FAIL){
            closeFiles(inputSettings);
            return 1;
        }else if(e == DONE){
            double x1, x2;
            enum RootType rootType = solveSquareEquation(a, b, c, &x1, &x2);
            printAnswer(rootType, x1, x2, inputSettings);
        }


    }
}


int solveCIN(struct InputSettings inputSettings) {
    double a = 0, b = 0, c = 0;
    if (readDouble(&a, 'a') == FAIL || readDouble(&b, 'b') == FAIL || readDouble(&c, 'c') == FAIL) {
        printf("ОШИБКА ВВОДА!\n");
        return 1;
    }
    double x1, x2;
    enum RootType rootType = solveSquareEquation(a, b, c, &x1, &x2);
    printAnswer(rootType, x1, x2, inputSettings);
    closeFiles(inputSettings);
    return 0;
}