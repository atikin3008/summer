//
// Created by Никита Комков on 20.08.2026.
//

#ifndef SQUARE_EQUATION_SOLVER_IO_H
#define SQUARE_EQUATION_SOLVER_IO_H

enum Read readDouble(double *a, char c);

void print(enum RootType rootType, double x1, double x2);

enum Read readFileString(double *a, double *b, double *c);

void closeFiles();

enum TypeRead getArgs(int argc, char* argv[]);

#endif //SQUARE_EQUATION_SOLVER_IO_H
