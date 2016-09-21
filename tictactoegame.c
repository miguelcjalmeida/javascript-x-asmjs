#include "tictactoegame.h"
#include <stdio.h>
#include <stdlib.h>

#define amax(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     abs(_a) > abs(_b) ? _a : _b; })

struct game* initGame(int size){
	struct game* game = calloc(sizeof(struct game), 1);
	game->size = size; 
	game->board = calloc(sizeof(int *), size);
	
	for(int i=0; i<game->size; i++){
		game->board[i] = calloc(sizeof(int), game->size); 
	}
		
	resetGame(game);
	return game;
}


void freeGame(struct game* game){
	for(int i=0; i<game->size; i++){
		free(game->board[i]); 
	}	
	
	free(game->board);		
	free(game);
}

void resetGame(struct game* game){	
	game->movesMade = 0;
	game->currentPlayer = PLAYER_1;
	
	for(int i=0; i<game->size; i++)
		for(int j=0; j<game->size; j++)
			game->board[i][j] = PLAYER_NONE; 	
		
}

void makeOneMove(struct game* game, int row, int col){	
	game->board[row][col] = game->currentPlayer;
	game->movesMade++;
	game->currentPlayer = getEnemy(game->currentPlayer);
}

int getEnemy(int player) {
	if(player == PLAYER_1)
		return PLAYER_2;
	
	return PLAYER_1;
}

int isGameOver(struct game* game) {
	if(game->movesMade == game->size*game->size)
		return 1;
	
	if(getWinner(game) != 0)
		return 1;
	
	return 0;
}

int getWinner(struct game* game){
	int diagonalCount1 = 0;
	int diagonalCount2 = 0;
	int horizontalCount = 0;
	int verticalCount = 0;
	
	for(int i=0; i<game->size; i++){		
		int tempHorizontalCount = 0;
		int tempVerticalCount = 0;
		
		for(int j=0; j<game->size; j++)
		{
			tempHorizontalCount += game->board[i][j];			
			tempVerticalCount += game->board[j][i];
		}
		
		horizontalCount = amax(horizontalCount, tempHorizontalCount);
		verticalCount = amax(verticalCount, tempVerticalCount);
		
		diagonalCount1 += game->board[i][i];
		diagonalCount2 += game->board[i][game->size -i - 1];
	}
	
	return amax(diagonalCount1, amax(diagonalCount2, amax(horizontalCount, verticalCount))) /  game->size;	
	
}


struct game* cloneGame(struct game* game){
	struct game* newGame = initGame(game->size);
	
	for(int i=0; i<game->size; i++)
		for(int j=0; j<game->size; j++)
			newGame->board[i][j] = game->board[i][j];
		
	newGame->currentPlayer = game->currentPlayer;
	newGame->movesMade = game->movesMade;
}
