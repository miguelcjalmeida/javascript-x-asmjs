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

int minimax(struct game* game, int depth, struct game* bestChild){	
	if(depth == 0 || isGameOver(game))
	{
		return getHeuristicScore(game);		
	}
		
	int childBestScore = -100;
	
	for(int i=0; i<game->size; i++){
		for(int j=0; j<game->size; j++){
			if(game->board[i][j] == PLAYER_NONE)
			{
				struct game* newGame = cloneGame(game);
				makeOneMove(newGame, i, j);
				//printGame(newGame);
								
			    int score = -minimax(newGame, depth-1, bestChild);
				
				if(score > childBestScore){
					childBestScore = score;
					//bestChild = newGame;
				}	
				free(newGame);
			} 
		}
	}
	
	return childBestScore;
}

void makeBestMove(struct game* game, int* score){
	struct game* bestNode;

		printf("%d score \n", minimax(game, -1, bestNode));

	//game = bestNode;	
}

