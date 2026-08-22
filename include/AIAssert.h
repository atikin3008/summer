//
// Created by Никита Комков on 21.08.2026.
//

#ifndef SQUARE_EQUATION_SOLVER_AIASSERT_H
#define SQUARE_EQUATION_SOLVER_AIASSERT_H
#include <stdlib.h>
#include <stdio.h>

#ifdef DEBUG
#define assert(x) if(!x) {\
    printf("\033[1;31mОШИБКА В ФАЙЛЕ: %s В СТРОКЕ %d\033[0m\n", __FILE__, __LINE__)\
    ;abort();\
}
#else
#define assert(x)
#endif

#endif //SQUARE_EQUATION_SOLVER_AIASSERT_H
