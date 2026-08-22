#include "../include/solve.h"
#include "../include/types.h"

#define max(a, b) (a > b? a : b)
#define min(a, b) (a < b? a : b)

void printError(double a, double b, double c, double x1, double x2, double outx1, double outx2) {
    printf("Error in: a: %lg b: %lg c: %lg x1: %lg x2: %lg nx1: %lg nx2: %lg\n", a, b, c, x1, x2,
           outx1, outx2);
}


int main() {
    int count_tests = 0;
    int count_done_tests = 0;
    for (double x1 = -50; x1 < 50; ++x1) {
        for (double x2 = -50; x2 < 50; ++x2) {
            for (double a = -50; a < 50; ++a) {
                count_tests++;
                count_done_tests++;
                double b = (-x1 - x2) * a;
                double c = x1 * x2 * a;
                double outx1 = 0, outx2 = 0;
                enum RootType rootType = solveSquareEquation(a, b, c, &outx1, &outx2);
                if (a == 0) {
                    if (rootType != ANY_ROOT) {
                        printError(a, b, c, x1, x2,
                                   outx1, outx2);
                        count_done_tests--;
                    }
                } else if (x1 == x2) {
                    if (rootType != ONE_ROOT) {
                        printError(a, b, c, x1, x2,
                                   outx1, outx2);
                        count_done_tests--;
                        continue;
                    }
                    if (outx1 != x1) {
                        printError(a, b, c, x1, x2,
                                   outx1, outx2);
                        count_done_tests--;
                    }
                } else {
                    if (rootType != TWO_ROOT) {
                        printError(a, b, c, x1, x2,
                                   outx1, outx2);
                        count_done_tests--;
                        continue;
                    }
                    if ((max(outx1, outx2) != max(x1, x2)) || (min(outx1, outx2) != min(x1, x2))) {
                        printError(a, b, c, x1, x2,
                                   outx1, outx2);
                        count_done_tests--;
                    }
                }
            }
        }

    }
    for (double b = -50; b < 50; ++b) {
        for (double c = -50; c < 50; ++c) {
            double outx1 = 0, outx2 = 0;
            double x = 0;
            if (b != 0) x = -c / b;
            enum RootType rootType = solveSquareEquation(0, b, c, &outx1, &outx2);
            count_tests++;
            if (b == 0 && c == 0 && rootType != ANY_ROOT) {
                printError(0, b, c, x, 0,
                           outx1, outx2);
            } else if (c != 0 && b == 0 && rootType != ZERO_ROOT) {
                printError(0, b, c, x, 0,
                           outx1, outx2);
            } else if (c != 0 && b != 0 && rootType != ONE_ROOT) {
                printError(0, b, c, x, 0,
                           outx1, outx2);
            } else if (c != 0 && b != 0 && outx1 != x) {
                printError(0, b, c, x, 0,
                           outx1, outx2);
            } else count_done_tests++;

        }
    }

    printf("Выполнено верно %i из %i\n", count_done_tests, count_tests);
}