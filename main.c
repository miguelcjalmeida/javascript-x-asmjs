#include<stdio.h>
#include "tictactoegame.h"
#include "tictactoeui.h"
#define SIZE 3

int main () {	

	struct game* game = initGame(SIZE);

	while(TRUE){
		keepPlayingUntilEndOfTurn(game);
		resetGame(game);
	}
	
	return 0;
}
