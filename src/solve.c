#include "../include/types.h"
#include <math.h>
#include <assert.h>

double EPS = 1e-3;

bool eqDouble(double a, double b) {
    return fabsl(a - b) <= EPS;
}

enum EquationType getEquationType(double a, double b, double c) {
    if (eqDouble(a, 0)) {
        if (eqDouble(b, 0)) {
            if (eqDouble(c, 0)) {
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

double getDiscriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}


/**
 * @brief Решает любые уравнения до 2 степени
 * @param a Коэффициент уравнения a
 * @param b Коэффициент уравнения b
 * @param c Коэффициент уравнения c
 * @param x1 Указатель на первый корень уравнения
 * @param x2 Указатель на второй корень уравнения
 * @return Количество корней уравнения
 */
enum RootType solveSquareEquation(double a, double b, double c, double *x1, double *x2) {

    assert(isfinite(a) && !isnan(a));
    assert(isfinite(b) && !isnan(b));
    assert(isfinite(c) && !isnan(c));


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

    double discriminant = getDiscriminant(a, b, c);

    if (discriminant > 0) {
        *x1 = (b + sqrt(discriminant)) / (2 * a);
        *x2 = (b - sqrt(discriminant)) / (2 * a);
        return TWO_ROOT;
    }
    if (eqDouble(discriminant, 0)) {
        *x1 = b / (2 * a);
        return ONE_ROOT;
    }
    return ZERO_ROOT;
}
