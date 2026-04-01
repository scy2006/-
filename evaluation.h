#ifndef EVALUATION_H
#define EVALUATION_H

#include "common.h"

int calculate_well_depth(int* height);
int maxheight(int* height);
int flatness(int* height);
int holecount(int* height, int** arr);
int dangerline(int* height);
double evaluation(int** arr, int* height, int size, weight* temp);

#endif
