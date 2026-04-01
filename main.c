#include"common.h"
#include"algorithm.h"
#include"array_ops.h.h"
#include"block_placement.h"
#include"evaluation.h"
#include"game_logic.h"
#include"main.h"
#include"weight.h"
int main() {
	weightness = creat();
	int** arr = creatarr();
	int* height = heightarr();
	char* s0 = malloc(sizeof(char));
	char* s1 = malloc(sizeof(char));
	int count = 0;//记录执行次数
	int ans = 0;//记录分数
	input(s0, s1, count, height);
	while (s0[0] != 'E' && s0[0] != 'X') {
		double temp;
		int best_angle = 0;
		int best_position = 0;
		heightcheck(arr, height);
		if (s1[0] != 'E' && s1[0] != 'X') {
			if (algorithm(arr, height, &best_angle, &best_position, s0[0], s1[0], &count, &temp, 1)) {
				laydown(best_angle, best_position, s0[0], height, arr);
				ans += temp;
				if (temp > 0) {
					int size;
					int* lines = scoreline(arr, &size);
					clean(lines, arr, size, height);
					free(lines);
				}//清行，以免方块堆积
				printing(best_angle, best_position, ans);
			}
			else {
				printing(0, 4, ans);
			}
		}
		else {
			if (algorithm(arr, height, &best_angle, &best_position, s0[0], s1[0], &count, &temp, 1)) {
				laydown(best_angle, best_position, s0[0], height, arr);
				ans += temp;
				if (temp > 0) {
					int size;
					int* lines = scoreline(arr, &size);
					clean(lines, arr, size, height);
					free(lines);
				}//清行，以免方块堆积
				printing(best_angle, best_position, ans);
			}
			else {
				printing(0, 4, ans);
				break;
			}
		}
		input(s0, s1, count, height);
	}
	free(height);
	freeline(arr);
	free(arr);
	return 0;
}
