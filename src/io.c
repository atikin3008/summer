#include "../include/types.h"
#include <stdio.h>

enum Read readDouble(double *a, char c) {
    printf("Прогама решающая квадратное уравнение\n\n");
    printf("Введите %c: ", c);
    int is_read = scanf("%lg", a);
    int fail_count = 0;
    while (getchar() != '\n') {}
    while (is_read != 1) {
        fail_count++;
        if (fail_count >= 5) {
            return FAIL;
        }
        printf("Введите повторно %c: ", c);
        is_read = scanf("%lg", a);
        while (getchar() != '\n');
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
