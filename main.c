#include <stdio.h>
#include <math.h>
#include <assert.h>

enum EquationType {
    // Тип уравнения
    ANY_NUMBER, // Корнем является любое число
    NO_ROOTS, // Нет корней
    LINEAR_EQUATION, // Линейное уравнение
    SQUARE_EQUATION // Квадратное уравнение
};

enum RootType {
    // Количество корней и их тип
    ZERO_ROOT,
    ONE_ROOT,
    TWO_ROOT,
    ANY_ROOT
};


enum EquationType getEquationType(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                return ANY_NUMBER;
            }
            return NO_ROOTS; // c != 0
        } else { // b != 0
            return LINEAR_EQUATION;
        }
    } else { // a != 0
        return SQUARE_EQUATION;
    }
}

double solveLinearEquation(double b, double c) {
    return -c / b;
}

double getDiscreminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}


enum RootType solveSquareEquation(double a, double b, double c, double *x1, double *x2) {
    /*
     * @brief Решает любые уравнения до 2 степени
     * @param a Коэффициент уравнения a
     * @param b Коэффициент уравнения b
     * @param c Коэффициент уравнения c
     * @param x1 Указатель на первый корень уравнения
     * @param x2 Указатель на второй корень уравнения
     * @return Количество корней уравнения
     */

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));


    enum EquationType type = getEquationType(a, b, c);

    if (type == NO_ROOTS) {
        x1 = nullptr;
        x2 = nullptr;
        return ZERO_ROOT;
    }

    if (type == ANY_NUMBER) {
        x1 = nullptr;
        x2 = nullptr;
        return ANY_ROOT;
    }

    if (type == LINEAR_EQUATION) {
        (*x1) = solveLinearEquation(b, c);
        return ONE_ROOT;
    }

    double discriminant = getDiscreminant(a, b, c);

    if (discriminant > 0) {
        *x1 = (b + sqrt(discriminant)) / (2 * a);
        *x2 = (b - sqrt(discriminant)) / (2 * a);
        return TWO_ROOT;
    }
    if (discriminant == 0) {
        *x1 = b / (2 * a);
        return ONE_ROOT;
    }
    return ZERO_ROOT;
}

int main(void) {
    printf("Прогама решающая квадратное уравнение\n\n"); // TODOb func
    printf("Введите a, b, c: ");
    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c);
    double x1, x2;

    enum RootType rootType = solveSquareEquation(a, b, c, &x1, &x2);

    if (rootType == ZERO_ROOT){
        printf("Корней нет!\n");
    }else if(rootType == ONE_ROOT){
        printf("Уравнение имеет один корень: %lg", x1);
    }else if(rootType == TWO_ROOT){
        printf("Уравнение имеет два корня: %lg %lg", x1, x2);
    }else{
        printf("Корнем уравнения является любое число");
    }

}
