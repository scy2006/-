#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>

#define y 20
#define x 10

typedef struct {
    double score;
    double flat;
    double hole;
    double max_height;
    double depth;
    double dangerfactor;
} weight;
extern weight* weightness;

void clearbuffer();

#endif