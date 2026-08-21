#include <stdio.h>
#include <stdlib.h>
#include "../include/types.h"
#include "../include/io.h"
#include "../include/solve.h"

int solveFIN();
int solveCIN();


int main(int argc, char *argv[]) {
    enum TypeRead typeRead = getArgs(argc, argv);
    if (typeRead == FIN){
        return solveFIN();
    }else{
        return solveCIN();
    }
}

int solveFIN() {
    while (true) {
        double a, b, c;
        enum Read e = readFileString(&a, &b, &c);
        if (e == END) {
            closeFiles();
            return 0;
        }else if (e == FAIL){
            closeFiles();
            return 1;
        }else if(e == DONE){
            double x1, x2;
            enum RootType rootType = solveSquareEquation(a, b, c, &x1, &x2);
            print(rootType, x1, x2);
        }


    }
}


int solveCIN() {
    double a = 0, b = 0, c = 0;
    if (readDouble(&a, 'a') == FAIL || readDouble(&b, 'b') == FAIL || readDouble(&c, 'c') == FAIL) {
        printf("ОШИБКА ВВОДА!\n");
        return 1;
    }
    double x1, x2;
    enum RootType rootType = solveSquareEquation(a, b, c, &x1, &x2);
    print(rootType, x1, x2);
    closeFiles();
    return 0;
}