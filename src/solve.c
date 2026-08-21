#include "../include/types.h"
#include <math.h>
#include <assert.h>

double EPS = 1e-3;

bool eqDouble(double a, double b) {
    return fabsl(a - b) <= EPS;
}

enum EquationType getEquationType(double b, double c) {
    if (eqDouble(b, 0)) {
        if (eqDouble(c, 0)) return ANY_NUMBER;
        return NO_ROOTS; // c != 0
    } else return LINEAR_EQUATION; // b != 0
}

enum RootType solveLinearEquation(double b, double c, double *x) {
    enum EquationType equationType = getEquationType(b, c);
    if (equationType == LINEAR_EQUATION) {
        *x = -c / b;
        return ONE_ROOT;
    }
    if (equationType == ANY_NUMBER) {
        return ANY_ROOT;
    }
    return ZERO_ROOT;
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

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1);
    assert(x2);


    if (eqDouble(a, 0)) return solveLinearEquation(b, c, x1);


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
