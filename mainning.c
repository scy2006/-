#include"common.h"
#include"algorithm.h"
#include"array_ops.h.h"
#include"block_placement.h"
#include"evaluation.h"
#include"game_logic.h"
#include"main.h"
#include"weight.h"
void printing(int angle, int position, int score) {
	printf("%d %d\n", angle / 90, position);
	printf("%d\n", score);
	fflush(stdout);
	return;
}
//打印位置，角度，分数

int  input(char* s0, char* s1, int stage, int* height) {
	if (stage == 0) {
		int ch1, ch2;
		ch1 = fgetc(stdin);
		ch2 = fgetc(stdin);
		clearbuffer();
		if (ch1 != '\n' && ch1 != EOF && ch2 != '\n' && ch2 != EOF) {
			*s0 = ch1;
			*s1 = ch2;
			/*printf("s0 是：%c s1是：%c\n", ch1, ch2);*/
			return 1;
		}
		return 0;
	}
	else {
		if (*s1 == 'E' || *s1 == 'X') {
			*s0 = *s1;
			return 1;
		}
		int ch = fgetc(stdin);
		clearbuffer();
		if (ch != '\n' && ch != EOF) {
			*s0 = *s1;
			*s1 = ch;
			/*printf("s0 是：%c s1是：%c\n", s0[0], s1[0]);*/
			return 1;
		}
		return 0;
	}
}//输入区域，如果输入异常，返回0，正常返回1 如果第一次输入，s0，s1正常输入，其余的话s0变为s1 s1变为新输入的
