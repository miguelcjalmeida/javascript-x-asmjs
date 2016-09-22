#include "tictactoeui.h"
#include "tictactoeengine.h"
#include <stdio.h>
#include <stdlib.h>
 
char getPlayerSymbol(int player){
	if(player == PLAYER_1)
		return 'x';
	if(player == PLAYER_2)
		return 'o';
	return '_';
}

void printGame(struct game* game, int score) {	
	//system("cls");
	printf("Player %c turn\n\n", getPlayerSymbol(game->currentPlayer));

	for(int i=0; i<game->size; i++) {
		for(int j=0; j<game->size; j++)
			printf("%c ", getPlayerSymbol(game->board[i][j]));
		
		printf("\n");
	}
	
	printf("Player %c score: %d\n", getPlayerSymbol(game->currentPlayer), score);
	printf("Player %c score: %d\n", getPlayerSymbol(getEnemy(game->currentPlayer)), -score);
	printf("\n");
}

int getPlayerMove(struct game* game){
	printf("\nchoose position between %d-%d (or press enter for IA help): ", 1, game->size * game->size);
		
	char digits[3];
	
	gets(digits);
	
	return atoi(digits);
}

void keepPlayingUntilEndOfGame(struct game** game, int depth){
	struct game* cpuNextMove;
	int cpuNextMoveScore;
	
	while(TRUE){
		system("cls");
				
		printf("start round\n\ngame address: %d\n", *game);

		if(!getBestMove(*game, depth, &cpuNextMove, &cpuNextMoveScore)){			
			printGame(*game, cpuNextMoveScore);
			break;
		}
				
		printGame(*game, cpuNextMoveScore);
					
		if(isGameOver(*game))
			break;
		
		int position = getPlayerMove(*game);

		if(position != 0)
		{
			position -= 1;
			int row = position / (*game)->size;
			int col = position % (*game)->size;
			makeOneMove(*game, row, col);
			freeGame(cpuNextMove);
		}
		else{
			freeGame(*game);
			*game = cpuNextMove;
		}		
		
		printf("next round game address: %d\n", *game);
		getchar();
	}		
}

void playCpuVsCpu(struct game** game, int depth){
	struct game* cpuNextMove;
	int cpuNextMoveScore;
	
	while(TRUE){
		if(!getBestMove(*game, depth, &cpuNextMove, &cpuNextMoveScore)){			
			break;
		}
					
		if(isGameOver(*game))
			break;		

		freeGame(*game);
		*game = cpuNextMove;
	}
}

void showResults(struct game* game){
	int winner = getWinner(game);
	
	if(winner == PLAYER_NONE){
		printf("DRAW!! YOU CAN'T BEAT THE MACHINE\n");
		return;
	}
	
	printf("Player %c won the game!\n", getPlayerSymbol(winner));	
}

