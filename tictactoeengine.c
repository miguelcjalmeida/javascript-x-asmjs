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

int minimax(struct game* game, int depth){	
	
	if(depth == 0 || isGameOver(game))
	{
		return getHeuristicScore(game);
	}
	
	int bestNextMoveScore = 0;
	int anyNextMovePicked = FALSE;
	
	for(int i=0; i<game->size; i++){
		for(int j=0; j<game->size; j++){
			if(game->board[i][j] == PLAYER_NONE)
			{ 
				struct game* nextMoveGame = cloneGame(game);
				makeOneMove(nextMoveGame, i, j);
												
				int nextMoveScore = -minimax(nextMoveGame, depth-1);
				
				if(anyNextMovePicked == FALSE || nextMoveScore > bestNextMoveScore){		
					bestNextMoveScore = nextMoveScore;
					anyNextMovePicked = TRUE;
				}
				
				freeGame(nextMoveGame);
			}
		}
	}
	
	return bestNextMoveScore;
}

int getBestMove(struct game* game, int depth, struct game** bestMove, int* bestScore){
	int foundAnyAlready = FALSE;
		
	for(int i=0; i<game->size; i++){
		for(int j=0; j<game->size; j++){
			if(game->board[i][j] == PLAYER_NONE)
			{ 	
				struct game* nextMoveGame = cloneGame(game);
				makeOneMove(nextMoveGame, i, j);
								
				int score = -minimax(nextMoveGame, depth);
					
				if(!foundAnyAlready || score > *bestScore){	
					if(foundAnyAlready){
						//freeGame(*bestMove);
					}
					*bestScore = score;
					*bestMove = nextMoveGame;
					foundAnyAlready = TRUE;
				}
				else {
					freeGame(nextMoveGame);					
				}			
			}
		}	
	}	

	return foundAnyAlready;
}

