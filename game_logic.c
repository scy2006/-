#include"common.h"
#include"algorithm.h"
#include"array_ops.h.h"
#include"block_placement.h"
#include"evaluation.h"
#include"game_logic.h"
#include"main.h"
#include"weight.h"
void heightcheck(int** arr, int* height) {
	for (int i = 0; i < x; i++) {
		int j = 19;
		for (j; j >= 0 && arr[j][i] != 1; j--);
		height[i] = j + 1;
	}
	return;
}
//高度检查
int* scoreline(int** arr, int* size) {
	int* line = calloc(4, sizeof(int));
	*size = 0;
	for (int i = 0; i < 20; i++) {
		int count = 0;
		for (int j = 0; j < 10; j++) {
			count += arr[i][j];
		}
		if (count == 10) {
			line[*size] = i;
			(*size)++;
		}
	}
	return line;//找出满足条件的行列 从小到大排列高度
}
//得分列返回
int score(int size) {
	if (size == 0)return 0;
	else if (size == 1)return 100;
	else if (size == 2)return 300;
	else if (size == 3)return 500;
	else if (size == 4)return 800;
}//返回分数大小，在line中加入已经满了的行数
void cleanhelper(int line, int** arr, int* height) {
	heightcheck(arr, height);
	for (int i = line; i <= 18; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = arr[i + 1][j];
		}
	}
	return;
}
void clean(int* line, int** arr, int size, int* height) {
	for (int i = 0; i < size; i++) {
		cleanhelper(line[i] - i, arr, height);
	}
	return;
}
//清理得分行