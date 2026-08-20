#include <stdio.h>
#include <math.h>
#include <assert.h>

enum EquationType {
    // Тип уравнения
    ANY_NUMBER = 0, // Корнем является любое число
    NO_ROOTS = 1, // Нет корней
    LINEAR_EQUATION = 2, // Линейное уравнение
    SQUARE_EQUATION = 3 // Квадратное уравнение
};

enum Read {
    DONE = 0,
    FAIL = 1
};

enum RootType {
    // Количество корней и их тип
    ZERO_ROOT = 0,
    ONE_ROOT = 1,
    TWO_ROOT = 2,
    ANY_ROOT = 3
};

bool eqDouble(double a, double b, double EPS) {
    return fabsl(a - b) <= EPS;
}

enum EquationType getEquationType(double a, double b, double c) {
    if (eqDouble(a, 0, 1e-3)) {
        if (eqDouble(b, 0, 1e-3)) {
            if (eqDouble(c, 0, 1e-3)) {
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

    double discriminant = getDiscreminant(a, b, c);

    if (discriminant > 0) {
        *x1 = (b + sqrt(discriminant)) / (2 * a);
        *x2 = (b - sqrt(discriminant)) / (2 * a);
        return TWO_ROOT;
    }
    if (eqDouble(discriminant, 0, 1e-3)) {
        *x1 = b / (2 * a);
        return ONE_ROOT;
    }
    return ZERO_ROOT;
}

enum Read read(double *a, double *b, double *c) {
    printf("Прогама решающая квадратное уравнение\n\n");
    char letters[] = "abc";
    double *variables[] = {a, b, c};
    for (int letter = 0; letter < 3; ++letter) {
        printf("Введите %c: ", letters[letter]);
        int is_read = scanf("%lg", variables[letter]);
        int fail_count = 0;
        while (getchar() != '\n');
        while (is_read != 1) {
            fail_count++;
            if (fail_count >= 5) {
                return FAIL;
            }
            printf("Введите повторно %c: ", letters[letter]);
            is_read = scanf("%lg", variables[letter]);
            while (getchar() != '\n');
        }
    }
    return DONE;
}

void print(enum RootType rootType, double x1, double x2) {
    switch (rootType) {
        case ZERO_ROOT:
            printf("Корней нет!\n");
            break;
        case ONE_ROOT:
            printf("Уравнение имеет один корень: %lg", x1);
            break;
        case TWO_ROOT:
            printf("Уравнение имеет два корня: %lg %lg", x1, x2);
            break;
        default:
            printf("Корнем уравнения является любое число");
            break;
    }
}


int main(void) {
    double a = 0, b = 0, c = 0;
    if (read(&a, &b, &c) == FAIL) {
        printf("ОШИБКА ВВОДА!\n");
        return 1;
    }
    double x1, x2;
    enum RootType rootType = solveSquareEquation(a, b, c, &x1, &x2);
    print(rootType, x1, x2);
}
