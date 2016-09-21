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

void printGame(struct game* game) {	
	//system("cls");
	printf("Player %c turn\n\n", getPlayerSymbol(game->currentPlayer));

	for(int i=0; i<game->size; i++) {
		for(int j=0; j<game->size; j++)
			printf("%c ", getPlayerSymbol(game->board[i][j]));
		
		printf("\n");
	}
	
	
}

int getPlayerMove(struct game* game){
	printf("\nchoose position between %d-%d (or press enter for IA help): ", 1, game->size * game->size);
		
	char digits[3];
	
	gets(digits);
	
	return atoi(digits);
}

void keepPlayingUntilEndOfTurn(struct game* game){
	while(TRUE){
		printGame(game);
		int position = getPlayerMove(game);
		
		if(position != 0)
		{
			position -= 1;
			int row = position / game->size;
			int col = position % game->size;
			makeOneMove(game, row, col);
		}
		else{
			int score;
			makeBestMove(game, &score);
		}
		
		if(getWinner(game) != 0)
			break;
	}
}