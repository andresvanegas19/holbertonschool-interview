#ifndef SAND_H
#define SAND_H

/* Librerias */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Funciones */
int isStable(int grid[3][3]);
void topple(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* SAND_H */
