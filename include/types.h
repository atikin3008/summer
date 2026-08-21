//
// Created by Никита Комков on 20.08.2026.
//

#ifndef SQUARE_EQUATION_SOLVER_TYPES_H
#define SQUARE_EQUATION_SOLVER_TYPES_H
#include <stdio.h>




enum EquationType {
    // Тип уравнения
    ANY_NUMBER = 0, // Корнем является любое число
    NO_ROOTS = 1, // Нет корней
    LINEAR_EQUATION = 2, // Линейное уравнение
    SQUARE_EQUATION = 3 // Квадратное уравнение
};

enum Read {
    DONE = 0,
    FAIL = 1,
    END = 2
};

enum RootType {
    // Количество корней и их тип
    ZERO_ROOT = 0,
    ONE_ROOT = 1,
    TWO_ROOT = 2,
    ANY_ROOT = 3
};

enum TypeRead {
    CIN = 0,
    FIN = 1,
    ERR = 2
};


struct InputSettings {
    FILE* input;
    FILE* output;
    enum TypeRead typeRead;
    bool gui;
};



#endif //SQUARE_EQUATION_SOLVER_TYPES_H
