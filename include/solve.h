//
// Created by Никита Комков on 20.08.2026.
//

#ifndef SQUARE_EQUATION_SOLVER_SOLVE_H
#define SQUARE_EQUATION_SOLVER_SOLVE_H

enum RootType solveSquareEquation(double a, double b, double c, double *x1, double *x2);

enum RootType solveLinearEquation(double b, double c, double *x);

bool eqDouble(double a, double b);

extern double EPSILON;

#endif //SQUARE_EQUATION_SOLVER_SOLVE_H
