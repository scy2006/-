#include"common.h"
#include"algorithm.h"
#include"array_ops.h.h"
#include"block_placement.h"
#include"evaluation.h"
#include"game_logic.h"
#include"main.h"
#include"weight.h"
int  laydownjudege(int angle, int posi, char shape, int* height, int** arr) {
	int X = posi;
	int Y = height[X];
	int coords[4][2] = { {0} };
	int valid = 1;
	if (shape == 'I') {
		if (angle == 90 || angle == 270) {
			if (Y + 3 >= 15)return 0;
			coords[0][0] = Y;   coords[0][1] = X;
			coords[1][0] = Y + 1; coords[1][1] = X;
			coords[2][0] = Y + 2; coords[2][1] = X;
			coords[3][0] = Y + 3; coords[3][1] = X;
		}
		else {
			if (X + 3 >= x) return 0;
			coords[0][0] = Y; coords[0][1] = X;
			coords[1][0] = Y; coords[1][1] = X + 1;
			coords[2][0] = Y; coords[2][1] = X + 2;
			coords[3][0] = Y; coords[3][1] = X + 3;
		}
	}
	else if (shape == 'T') {
		if (angle == 0) {
			if (Y + 1 >= 15 || X + 2 >= x) return 0;
			coords[0][0] = Y;   coords[0][1] = X;
			coords[1][0] = Y;   coords[1][1] = X + 1;
			coords[2][0] = Y;   coords[2][1] = X + 2;
			coords[3][0] = Y + 1; coords[3][1] = X + 1;
		}
		else if (angle == 180) {
			if (Y >= 15 || X + 2 >= x || Y == 0) return 0;
			coords[0][0] = Y;   coords[0][1] = X;
			coords[1][0] = Y - 1;   coords[1][1] = X + 1;
			coords[2][0] = Y;   coords[2][1] = X + 1;
			coords[3][0] = Y; coords[3][1] = X + 2;
		}
		else if (angle == 90) {
			if (Y + 2 >= 15 || X + 1 >= x) return 0;
			coords[0][0] = Y;   coords[0][1] = X;
			coords[1][0] = Y + 1; coords[1][1] = X;
			coords[2][0] = Y + 2; coords[2][1] = X;
			coords[3][0] = Y + 1; coords[3][1] = X + 1;
		}
		else if (angle == 270) {
			if (Y + 1 >= 15 || X + 1 >= x || Y == 0) return 0;
			coords[0][0] = Y + 1;   coords[0][1] = X + 1;
			coords[1][0] = Y; coords[1][1] = X + 1;
			coords[2][0] = Y; coords[2][1] = X;
			coords[3][0] = Y - 1; coords[3][1] = X + 1;
		}
	}
	else if (shape == 'O') {
		if (Y + 1 >= 15 || X + 1 >= x) return 0;
		coords[0][0] = Y;   coords[0][1] = X;
		coords[1][0] = Y;   coords[1][1] = X + 1;
		coords[2][0] = Y + 1; coords[2][1] = X;
		coords[3][0] = Y + 1; coords[3][1] = X + 1;
	}
	else if (shape == 'L') {
		if (angle == 0) {
			if (Y + 1 >= 15 || X + 2 >= x) return 0;
			coords[0][0] = Y;   coords[0][1] = X;
			coords[1][0] = Y;   coords[1][1] = X + 1;
			coords[2][0] = Y;   coords[2][1] = X + 2;
			coords[3][0] = Y + 1; coords[3][1] = X + 2;
		}
		else if (angle == 90) {
			if (Y + 2 >= 15 || X + 1 >= x) return 0;
			coords[0][0] = Y;   coords[0][1] = X;
			coords[1][0] = Y + 1; coords[1][1] = X;
			coords[2][0] = Y + 2; coords[2][1] = X;
			coords[3][0] = Y;   coords[3][1] = X + 1;
		}
		else if (angle == 180) {
			if (Y + 1 >= 15 || X + 2 >= x) return 0;
			coords[0][0] = Y + 1;   coords[0][1] = X + 2;
			coords[1][0] = Y + 1;   coords[1][1] = X + 1;
			coords[2][0] = Y;   coords[2][1] = X;
			coords[3][0] = Y + 1; coords[3][1] = X;
		}
		else { // 270度
			if (Y < 2 || X + 1 >= x) return 0;
			coords[0][0] = Y - 2;   coords[0][1] = X + 1;
			coords[1][0] = Y; coords[1][1] = X;
			coords[2][0] = Y; coords[2][1] = X + 1;
			coords[3][0] = Y - 1; coords[3][1] = X + 1;
		}
	}
	else if (shape == 'J') {
		if (angle == 0) {       // 0 度
			if (Y + 1 >= 15 || X + 2 >= x) return 0;
			coords[0][0] = Y;   coords[0][1] = X;
			coords[1][0] = Y;   coords[1][1] = X + 1;
			coords[2][0] = Y;   coords[2][1] = X + 2;
			coords[3][0] = Y + 1; coords[3][1] = X;
		}
		else if (angle == 90) {  // 90 度
			if (Y + 2 >= 15 || X + 1 >= x) return 0;
			coords[0][0] = Y;   coords[0][1] = X;
			coords[1][0] = Y + 1; coords[1][1] = X;
			coords[2][0] = Y + 2; coords[2][1] = X + 1;
			coords[3][0] = Y + 2; coords[3][1] = X;
		}
		else if (angle == 180) { // 180 度
			if (Y < 1 || X + 2 >= x) return 0;
			coords[0][0] = Y;   coords[0][1] = X;
			coords[1][0] = Y - 1;   coords[1][1] = X + 2;
			coords[2][0] = Y;   coords[2][1] = X + 1;
			coords[3][0] = Y; coords[3][1] = X + 2;
		}
		else {
			if (Y + 2 >= 15 || X + 1 >= x) return 0;
			coords[0][0] = Y;   coords[0][1] = X + 1;
			coords[1][0] = Y + 1; coords[1][1] = X + 1;
			coords[2][0] = Y + 2; coords[2][1] = X + 1;
			coords[3][0] = Y;   coords[3][1] = X;
		}
	}
	else if (shape == 'S') {
		if (angle == 0 || angle == 180) {  // 水平方向
			if (Y + 1 >= 15 || X + 2 >= x) return 0;
			coords[0][0] = Y;   coords[0][1] = X + 1;
			coords[1][0] = Y;   coords[1][1] = X;
			coords[2][0] = Y + 1; coords[2][1] = X + 1;
			coords[3][0] = Y + 1; coords[3][1] = X + 2;
		}
		else {  // 垂直方向
			if (Y + 1 >= 15 || X + 1 >= x || Y == 0) return 0;
			coords[0][0] = Y;   coords[0][1] = X;
			coords[1][0] = Y + 1; coords[1][1] = X;
			coords[2][0] = Y; coords[2][1] = X + 1;
			coords[3][0] = Y - 1; coords[3][1] = X + 1;
		}
	}
	else if (shape == 'Z') {
		if (angle == 0 || angle == 180) {  // 水平方向
			if (Y == 0 || X + 2 >= x) return 0;
			coords[0][0] = Y;   coords[0][1] = X;
			coords[1][0] = Y;   coords[1][1] = X + 1;
			coords[2][0] = Y - 1; coords[2][1] = X + 1;
			coords[3][0] = Y - 1; coords[3][1] = X + 2;
		}
		else {  // 垂直方向
			if (Y + 2 >= 15 || X + 1 >= x) return 0;
			coords[0][0] = Y;   coords[0][1] = X;
			coords[1][0] = Y + 1; coords[1][1] = X;
			coords[2][0] = Y + 1; coords[2][1] = X + 1;
			coords[3][0] = Y + 2; coords[3][1] = X + 1;
		}
	}
	//放置区预检查
	for (int i = 0; i < 4; i++) {
		int Ypos = coords[i][0];
		int Xpos = coords[i][1];
		if (Ypos < 0 || Xpos >= x || Ypos >= 15 || Xpos < 0 || arr[Ypos][Xpos] != 0) {
			valid = 0;
			break;
		}
	}
	if (valid == 1) {

		return 1;
	}
	return 0;
}//放置方块 0为失败 1为成功 此函数仅仅用于模拟探测 在算法中有用
void laydown(int angle, int posi, char shape, int* height, int** arr) {
	int X = posi;
	int Y = height[X];

	if (shape == 'I') {
		if (angle == 90 || angle == 270) {
			arr[Y][X] = 1;
			arr[Y + 1][X] = 1;
			arr[Y + 2][X] = 1;
			arr[Y + 3][X] = 1;
		}
		else {
			arr[Y][X] = 1;
			arr[Y][X + 1] = 1;
			arr[Y][X + 2] = 1;
			arr[Y][X + 3] = 1;
		}
	}
	else if (shape == 'T') {
		if (angle == 0) {
			arr[Y][X] = 1;
			arr[Y][X + 1] = 1;
			arr[Y][X + 2] = 1;
			arr[Y + 1][X + 1] = 1;
		}
		else if (angle == 180) {
			arr[Y - 1][X + 1] = 1;
			arr[Y][X + 2] = 1;
			arr[Y][X + 1] = 1;
			arr[Y][X] = 1;
		}
		else if (angle == 90) {
			arr[Y][X] = 1;
			arr[Y + 1][X] = 1;
			arr[Y + 2][X] = 1;
			arr[Y + 1][X + 1] = 1;
		}
		else if (angle == 270) {
			arr[Y + 1][X + 1] = 1;
			arr[Y][X + 1] = 1;
			arr[Y][X] = 1;
			arr[Y - 1][X + 1] = 1;
		}
	}
	else if (shape == 'O') {
		arr[Y][X] = 1;
		arr[Y][X + 1] = 1;
		arr[Y + 1][X] = 1;
		arr[Y + 1][X + 1] = 1;
	}
	else if (shape == 'L') {
		if (angle == 0) {
			arr[Y][X] = 1;
			arr[Y][X + 1] = 1;
			arr[Y][X + 2] = 1;
			arr[Y + 1][X + 2] = 1;
		}
		else if (angle == 90) {
			arr[Y][X] = 1;
			arr[Y + 1][X] = 1;
			arr[Y + 2][X] = 1;
			arr[Y][X + 1] = 1;
		}
		else if (angle == 180) {
			arr[Y + 1][X + 2] = 1;
			arr[Y + 1][X + 1] = 1;
			arr[Y][X] = 1;
			arr[Y + 1][X] = 1;
		}
		else { // 270度
			arr[Y - 1][X + 1] = 1;
			arr[Y][X + 1] = 1;
			arr[Y - 2][X + 1] = 1;
			arr[Y][X] = 1;
		}
	}
	else if (shape == 'J') {
		if (angle == 0) {
			arr[Y][X] = 1;
			arr[Y][X + 1] = 1;
			arr[Y][X + 2] = 1;
			arr[Y + 1][X] = 1;
		}
		else if (angle == 90) {
			arr[Y][X] = 1;
			arr[Y + 1][X] = 1;
			arr[Y + 2][X] = 1;
			arr[Y + 2][X + 1] = 1;
		}
		else if (angle == 180) {
			arr[Y][X] = 1;
			arr[Y][X + 1] = 1;
			arr[Y - 1][X + 2] = 1;
			arr[Y][X + 2] = 1;
		}
		else { // 270度
			arr[Y][X + 1] = 1;
			arr[Y + 1][X + 1] = 1;
			arr[Y + 2][X + 1] = 1;
			arr[Y][X] = 1;
		}
	}
	else if (shape == 'S') {
		if (angle == 0 || angle == 180) {
			arr[Y][X + 1] = 1;
			arr[Y][X] = 1;
			arr[Y + 1][X + 1] = 1;
			arr[Y + 1][X + 2] = 1;
		}
		else { // 垂直方向
			arr[Y][X] = 1;
			arr[Y + 1][X] = 1;
			arr[Y][X + 1] = 1;
			arr[Y - 1][X + 1] = 1;
		}
	}
	else if (shape == 'Z') {
		if (angle == 0 || angle == 180) {
			arr[Y][X] = 1;
			arr[Y][X + 1] = 1;
			arr[Y - 1][X + 1] = 1;
			arr[Y - 1][X + 2] = 1;
		}
		else { // 垂直方向
			arr[Y][X] = 1;
			arr[Y + 1][X] = 1;
			arr[Y + 1][X + 1] = 1;
			arr[Y + 2][X + 1] = 1;
		}
	}
}//真实放置到arr中