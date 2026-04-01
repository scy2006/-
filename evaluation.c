#include"common.h"
#include"algorithm.h"
#include"array_ops.h.h"
#include"block_placement.h"
#include"evaluation.h"
#include"game_logic.h"
#include"main.h"
#include"weight.h"
int calculate_well_depth(int* height) {
	int well_depth = 0;
	for (int i = 1; i < x - 1; i++) {
		int left = height[i - 1];
		int right = height[i + 1];
		int current = height[i];
		if (current < left && current < right) {
			well_depth += (left < right ? left : right) - current;
		}
	}
	return well_depth;
}
//井深
int maxheight(int* height) {
	int max = 0;
	for (int i = 0; i < 10; i++) {
		if (height[i] > max)max = height[i];
	}
	return max;
}//找出最高高度
//最高高度
int flatness(int* height) {
	int sum = 0;
	for (int i = 0; i < x - 1; i++) {
		sum += abs(height[i + 1] - height[i]);
	}
	return sum;
}
//平整度
int holecount(int* height, int** arr) {
	int count = 0;
	for (int i = 0; i < x; i++) {
		int roof = 0; // 标记是否遇到过方块
		for (int j = y - 1; j >= 0; j--) {
			if (arr[j][i]) {
				roof = 1;
			}
			else if (roof) {
				count++; // 仅统计方块上方的空洞
			}
		}
	}
	return count;
}
//洞口数量
int dangerline(int* height) {
	int count = 0;
	for (int i = 0; i < x; i++) {
		if (height[i] >= 13)count++;
	}
	return count;
}
//危险行列

double evaluation(int** arr, int* height, int size, weight* temp) {
	heightcheck(arr, height);
	int flat = flatness(height);
	int max_high = maxheight(height);
	int holes = holecount(height, arr);
	int wells = calculate_well_depth(height);
	int risks = dangerline(height);
	return (flat * temp->flat + max_high * temp->max_height + holes * temp->hole + score(size) * temp->score / 6.5 + wells * temp->depth + risks * temp->dangerfactor);
}
//评估分
