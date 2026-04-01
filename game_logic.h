#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "common.h"

void heightcheck(int** arr, int* height);
int* scoreline(int** arr, int* size);
int score(int size);
void cleanhelper(int line, int** arr, int* height);
void clean(int* line, int** arr, int size, int* height);

#endif