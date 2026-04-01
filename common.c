#include"common.h"
#include"algorithm.h"
#include"array_ops.h.h"
#include"block_placement.h"
#include"evaluation.h"
#include"game_logic.h"
#include"main.h"
#include"weight.h"
void clearbuffer() {
	int ch;
	while (ch = fgetc(stdin), ch != EOF && ch != '\n');
	return;
}
weight* weightness;