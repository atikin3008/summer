#include "../include/types.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/solve.h"

FILE *input = nullptr;
FILE *output = nullptr;

void closeFiles() {
    if (input) {
        fclose(input);
    }
    if (output) {
        fclose(output);
    }
}

enum Read readFileString(double *a, double *b, double *c) {
    int correct = fscanf(input, "%lg %lg %lg\n", a, b, c);
    if (correct == -1) {
        closeFiles();
        return END;
    } else if (correct == 3) {
        return DONE;
    }
    return FAIL;
}

void printFile(enum RootType rootType, double x1, double x2) {
    switch (rootType) {
        case ZERO_ROOT:
            fprintf(output, "None\n");
            break;
        case ONE_ROOT:
            fprintf(output, "%lg\n", x1);
            break;
        case TWO_ROOT:
            fprintf(output, "%lg %lg\n", x1, x2);
            break;
        case ANY_ROOT:
            fprintf(output, "Any\n");
            break;
    }
}



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

void printCIN(enum RootType rootType, double x1, double x2) {
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

void print(enum RootType rootType, double x1, double x2) {
    if (output) {
        printFile(rootType, x1, x2);
    } else {
        printCIN(rootType, x1, x2);
    }
}


enum TypeRead getArgs(int argc, char *argv[]) {
    enum TypeRead typeRead = CIN;
    for (int argi = 1; argi < argc; ++argi) {
        char *current = argv[argi];
        char *var = nullptr;
        for (unsigned long i = 0; i < strlen(current); ++i) {
            if (current[i] == '=') {
                current[i] = '\0';
                var = &(current[i + 1]);
                break;
            }
        }
        if (var == nullptr) {
            printf("Неправильный аргумент: %s\n", current);
            return ERR;
        }
        if (strcmp(current, "--input") == 0) {
            input = fopen(var, "r");
            if (!input) {
                printf("Файл недоступен: %s\n", var);
                return ERR;
            }
            typeRead = FIN;
        } else if (strcmp(current, "--output") == 0) {
            output = fopen(var, "w");
        } else if (strcmp(current, "--eps") == 0) {
            char **end = NULL;
            EPS = strtod(var, end);
            if (*end == var) {
                printf("Ошибка EPS: %s", var);
                return ERR;
            }
        } else {
            printf("Ошибка аргумента: %s", current);
            return ERR;
        }
    }
    return typeRead;
}

