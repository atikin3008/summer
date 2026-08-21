#include "stdlib.h"
#include <stdio.h>
#include <string.h>

int main() {
    printf("Начало теста\n");
    int returned = system("build/exe --input=test/in.txt --output=test/out.txt");
    if (returned != 0) {
        printf("Программа завершила выполнение с не нулевым кодом: %i\n", returned);
        return 0;
    }

    int count_done = 0;
    int count_tests = 0;
    FILE *output = fopen("test/out.txt", "r");
    if (!output) {
        printf("Программа не создала файл с ответом\n");
        return 0;
    }
    FILE *answer = fopen("test/answer.txt", "r");
    if (!answer) {
        printf("Файла с ответами для проверки нет!\n");
        return 0;
    }
    while (!feof(answer)) {

        char *out = calloc(101, sizeof(char));
        char *ans = calloc(101, sizeof(char));
        fgets(out, 100, output);
        if (fgets(ans, 100, answer)) {
            count_tests++;
            if (strcmp(out, ans) == 0) {
                count_done++;
                printf("\033[1;32mТест: %i выполнен успешно\033[0m\n", count_tests);
            } else {
                printf("\033[1;31mТест: %i провален\033[0m\n", count_tests);
            }
        }
        free(out);
        free(ans);
    }
    printf("Выполнено %i тестов из %i\n", count_done, count_tests);

    fclose(output);
    fclose(answer);
}