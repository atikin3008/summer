#include "../include/solve.h"
#include "../include/types.h"

#define max(a, b) (a > b? a : b)
#define min(a, b) (a < b? a : b)


int main() {
    for (double x1 = -50; x1 < 50; ++x1) {
        for (double x2 = -50; x2 < 50; ++x2) {
            for (double a = -50; a < 50; ++a) {
                double b = (-x1 - x2) * a;
                double c = x1 * x2 * a;
                double nx1 = 0, nx2 = 0;
                enum RootType rootType = solveSquareEquation(a, b, c, &nx1, &nx2);
                if(a == 0){
                    if (rootType != ANY_ROOT){
                        printf("Error in: a: %lg b: %lg c: %lg x1: %lg x2: %lg nx1: %lg nx2: %lg\n", a, b, c, x1, x2, nx1, nx2);
                        continue;
                    }
                }
                else if (x1 == x2) {
                    if (rootType != ONE_ROOT) {
                        printf("Error in: a: %lg b: %lg c: %lg x1: %lg x2: %lg nx1: %lg nx2: %lg\n", a, b, c, x1, x2, nx1, nx2);
                        continue;
                    }
                    if (nx1 != x1) {
                        printf("Error in: a: %lg b: %lg c: %lg x1: %lg x2: %lg nx1: %lg nx2: %lg\n", a, b, c, x1, x2, nx1, nx2);
                    }
                } else {
                    if (rootType != TWO_ROOT) {
                        printf("RError in: a: %lg b: %lg c: %lg x1: %lg x2: %lg nx1: %lg nx2: %lg\n", a, b, c, x1, x2, nx1, nx2);
                        continue;
                    }
                    if ((max(nx1, nx2) != max(x1, x2)) || (min(nx1, nx2) != min(x1, x2))) {
                        printf("MError in: a: %lg b: %lg c: %lg x1: %lg x2: %lg nx1: %lg nx2: %lg\n", a, b, c, x1, x2, min(nx1, nx2), max(nx1, nx2));
                    }
                }
            }
        }

    }

}