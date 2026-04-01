#include"common.h"
#include"algorithm.h"
#include"array_ops.h.h"
#include"block_placement.h"
#include"evaluation.h"
#include"game_logic.h"
#include"main.h"
#include"weight.h"
int** creatarr() {
	int** arr = malloc(sizeof(int*) * y);
	for (int i = 0; i < y; i++) {
		arr[i] = calloc(x, sizeof(int));
	}
	return arr;
}//状态区构建 默认元素为0
int* heightarr() {
	int* height = calloc(x, sizeof(int));
	return height;
}//高度区构建，默认初始高度是0
int** COPY_arr(int** arr) {
	int** copy_arr = malloc(sizeof(int*) * y);
	for (int i = 0; i < y; i++) {
		copy_arr[i] = malloc(sizeof(int) * x);
	}
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			copy_arr[i][j] = arr[i][j];
		}
	}
	return copy_arr;
}
//深拷贝
int* COPY_height(int* height) {
	int* copy_height = malloc(sizeof(int) * x);
	for (int i = 0; i < x; i++) {
		copy_height[i] = height[i];
	}
	return copy_height;
}
void freeline(int** arr) {
	for (int i = 0; i < y; i++)free(arr[i]);
	return;
}
//void visualize(int** arr) {
//	for (int Y = y - 1; Y >= 0; Y--) {
//		if (Y == 14)printf("死亡线: ");
//		else if (Y == 11)printf("警戒线: ");
//		else if (Y == 7)printf("安全线: ");
//		else printf("\t");
//		for (int X = 0; X <x; X++) {
//			printf("%d ", arr[Y][X]);
//		}
//		printf("\n");
//	}
//}