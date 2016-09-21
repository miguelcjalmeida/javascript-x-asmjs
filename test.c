#include<stdio.h>
#include<stdlib.h>
#include "tictactoegame.h"
#include "tictactoeui.h"
#define SIZE 3

int main () {	
	
	for(int i=0; i< 400000; i++){
		struct game* game = initGame(SIZE);
				
		freeGame(game);
	}
	
	system("pause");
	
	return 0;
}
