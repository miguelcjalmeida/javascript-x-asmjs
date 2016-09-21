#include<stdio.h>
#include "tictactoegame.h"
#include "tictactoeui.h"
#define SIZE 3
#define ENGINE_DEPTH 9

int main () {	

	struct game* game = initGame(SIZE);

	while(TRUE){
		keepPlayingUntilEndOfGame(game, ENGINE_DEPTH);
		showResults(game);		
		getchar();
		resetGame(game);
	}
	
	return 0;
}
