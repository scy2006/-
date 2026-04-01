#include"common.h"
#include"algorithm.h"
#include"array_ops.h.h"
#include"block_placement.h"
#include"evaluation.h"
#include"game_logic.h"
#include"main.h"
#include"weight.h"
int algorithm(int** arr, int* height, int* best_angle, int* best_position, char shape, char next, int* time, double* max, int ans) {
	if (ans < 0)return 0;
	if (shape == 'E' || shape == 'X')return 0;
	modify(weightness, height, ans);//修改权重
	int flag = 0;
	*best_angle = 0;
	*best_position = 0;
	double max_score = -INT_MAX;//初始化;

	for (int angle = 0; angle < 360; angle += 90) {
		for (int pos = 0; pos < x; pos++) {
			if (laydownjudege(angle, pos, shape, height, arr) == 0) {
				continue;
			}//穷举放置，直至可放
			int** copyarr = COPY_arr(arr);
			int* copyheight = COPY_height(height);
			laydown(angle, pos, shape, copyheight, copyarr);//放置模拟数组

			int size;
			int* lines = scoreline(copyarr, &size);
			clean(lines, copyarr, size, copyheight);
			double temp = evaluation(copyarr, copyheight, size, weightness);//评估函数，函数里面实时更新模拟数组的高度
			double temp1 = 0;
			if (ans > 0 && next != 'E' && next != 'X' && shape != 'E') {
				int emptytime = *time + 1;
				double emptymax = *max;
				int emptyangle = *best_angle;
				int emptypostion = *best_position;
				temp1 = 0.95 * algorithm(copyarr, copyheight, &emptyangle, &emptypostion, next, 'X', &emptytime, &emptymax, ans - 1);

			}
			double total = temp + temp1;
			if (total > max_score) {
				max_score = total;
				*best_angle = angle;
				*best_position = pos;
				*max = score(size);
				flag = 1;
			}//记录最优解
			free(lines);
			free(copyheight);
			freeline(copyarr);
			free(copyarr);//释放内存
		}
	}
	if (ans) {
		if (flag) {
			(*time)++;
			return max_score;
		}

		return 0;
	}
	else {
		if (flag)return max_score;
		return 0;
	}
}
//算法！！