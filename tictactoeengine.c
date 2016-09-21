#include "tictactoeengine.h"
#include "tictactoeui.h"
#include <stdio.h>
#include <stdlib.h>
 
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
	 
int getHeuristicScore(struct game* game){
	int winner = getWinner(game);
	
	if(winner == game->currentPlayer)
		return 1;
	
	if(winner == getEnemy(game->currentPlayer))
		return -1;
	
	return 0;
}

struct evaluation* minimax(struct game* game, int depth){	
	
	if(depth == 0 || isGameOver(game))
	{
		struct evaluation* evaluation = calloc(sizeof(struct evaluation), 1);
		evaluation->score = getHeuristicScore(game);
		return evaluation;
	}
	
	struct evaluation* bestEvaluation = calloc(sizeof(struct evaluation), 1);

	bestEvaluation->score = -100;
	
	for(int i=0; i<game->size; i++){
		for(int j=0; j<game->size; j++){
			if(game->board[i][j] == PLAYER_NONE)
			{ 
				struct game* childNode = cloneGame(game);
				makeOneMove(childNode, i, j);
							
				struct evaluation* childEvaluation = minimax(childNode, depth-1);
				
				if(-childEvaluation->score > bestEvaluation->score){
					bestEvaluation->bestNode = childNode;
					bestEvaluation->score = -childEvaluation->score;					
				}
			}
		}
	}
	
	return bestEvaluation;
}

struct evaluation* getBestMove(struct game* game, int depth){
	return minimax(game, depth); 
}

