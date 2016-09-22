#ifndef TICTACTOEENGINE_H_INCLUDED
#define TICTACTOEENGINE_H_INCLUDED
#include "tictactoegame.h"
	 
struct evaluation { 
	int score;
	struct game* bestNode;
};

int getBestMove(struct game* game, int depth, struct game** bestMove, int* score);

#endif

