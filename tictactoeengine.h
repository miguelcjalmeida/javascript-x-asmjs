#ifndef TICTACTOEENGINE_H_INCLUDED
#define TICTACTOEENGINE_H_INCLUDED
#include "tictactoegame.h"
	 
struct evaluation { 
	int score;
	struct game* bestNode;
};

struct evaluation* getBestMove(struct game* game, int depth);

#endif

