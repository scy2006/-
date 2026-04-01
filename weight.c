#include"common.h"
#include"algorithm.h"
#include"array_ops.h.h"
#include"block_placement.h"
#include"evaluation.h"
#include"game_logic.h"
#include"main.h"
#include"weight.h"
weight* creat() {
	weight* temp = malloc(sizeof(weight));
	temp->flat = temp->hole = temp->score = temp->max_height = temp->depth = temp->dangerfactor = 0;
	return temp;
}
//权重初始化
void modify(weight* temp, int* height, int ans) {
	int max_h = maxheight(height);

	// 强化高风险区域的响应
	const int DEATH_LINE = 15;
	int danger_distance = DEATH_LINE - max_h;

	// 基础权重模板
	temp->flat = -5;   // 增强平整度惩罚
	temp->hole = -500;
	temp->depth = -2.0;  // 2倍井深惩罚

	if (danger_distance <= 3) { // 高风险区域（12层+）
		temp->score = ans ? 800 : 0;  // 消行奖励提升4倍
		temp->max_height = -500.0;        // 高度惩罚增强
		temp->dangerfactor = -50.0;    // 危险列惩罚加倍
		temp->hole = -5;
	}
	else if (danger_distance <= 6) { // 中风险区域（9-11层）
		temp->score = ans ? 200 : 500;
		temp->max_height = -20.0;
		temp->dangerfactor = -30.0;
	}
	else {  // 安全区域
		temp->score = ans ? 1 : 1000;
		temp->max_height = -5.0;
		temp->dangerfactor = -10.0;
	}

}
//改权重