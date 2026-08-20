#include "../include/types.h"
#include <stdio.h>

enum Read read(double *a, double *b, double *c) {
    printf("Прогама решающая квадратное уравнение\n\n");
    char letters[] = "abc";
    double *variables[] = {a, b, c};
    for (int letter = 0; letter < 3; ++letter) {
        printf("Введите %c: ", letters[letter]);
        int is_read = scanf("%lg", variables[letter]);
        int fail_count = 0;
        while (getchar() != '\n') {}
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