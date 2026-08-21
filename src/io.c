#include "../include/types.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/solve.h"


void closeFiles(struct InputSettings inputSettings) {
    if (inputSettings.input) {
        fclose(inputSettings.input);
    }
    if (inputSettings.output) {
        fclose(inputSettings.output);
    }
}

enum Read readFileString(double *a, double *b, double *c, struct InputSettings inputSettings) {
    int correct = fscanf(inputSettings.input, "%lg %lg %lg\n", a, b, c);
    if (correct == -1) {
        closeFiles(inputSettings);
        return END;
    } else if (correct == 3) {
        return DONE;
    }
    return FAIL;
}

void printFile(enum RootType rootType, double x1, double x2, struct InputSettings inputSettings) {
    switch (rootType) {
        case ZERO_ROOT:
            fprintf(inputSettings.output, "None\n");
            break;
        case ONE_ROOT:
            fprintf(inputSettings.output, "%lg\n", x1);
            break;
        case TWO_ROOT:
            fprintf(inputSettings.output, "%lg %lg\n", x1, x2);
            break;
        case ANY_ROOT:
            fprintf(inputSettings.output, "Any\n");
            break;
    }
}



enum Read readDouble(double *a, char c) {
    printf("Программа решающая квадратное уравнение\n\n");
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

void printConsole(enum RootType rootType, double x1, double x2) {
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

void printAnswer(enum RootType rootType, double x1, double x2, struct InputSettings inputSettings) {
    if (inputSettings.output) {
        printFile(rootType, x1, x2, inputSettings);
    } else {
        printConsole(rootType, x1, x2);
    }
}


struct InputSettings getArgs(int argc, char *argv[]) {
    struct InputSettings inputSettings = {nullptr, nullptr, CIN};
    for (int argi = 1; argi < argc; ++argi) {
        char *current = argv[argi];
        char *var = nullptr;
        unsigned long len = strlen(current);
        for (unsigned long i = 0; i < len; ++i) {
            if (current[i] == '=') {
                current[i] = '\0';
                var = &(current[i + 1]);
                break;
            }
        }
        if (var == nullptr) {
            printf("Неправильный аргумент: %s\n", current);
            inputSettings.typeRead = ERR;
            return inputSettings;
        }
        if (strcmp(current, "--input") == 0) {
            inputSettings.input = fopen(var, "r");
            if (!inputSettings.input) {
                printf("Файл недоступен: %s\n", var);
                inputSettings.typeRead = ERR;
                return inputSettings;
            }
            inputSettings.typeRead = FIN;
        } else if (strcmp(current, "--output") == 0) {
            inputSettings.output = fopen(var, "w");
        } else if (strcmp(current, "--epsilon") == 0) {
            char **end = nullptr;
            epsilon = strtod(var, end);
            if (*end == var) {
                printf("Ошибка epsilon: %s", var);
                inputSettings.typeRead = ERR;
                return inputSettings;
            }
        } else {
            printf("Ошибка аргумента: %s", current);
            inputSettings.typeRead = ERR;
            return inputSettings;
        }
    }
    return inputSettings;
}

