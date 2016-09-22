#include<stdio.h>
#include<stdlib.h>
#include "tictactoegame.h"
#include "tictactoeui.h"
#define SIZE 3

int main () {	
	
	struct game* game = initGame(3);
	struct game* p;
	
	for(int i=0; i<300000; i++){
		struct game* clone = cloneGame(game);
		p = clone;
	}
	
	system("pause");
	
	return 0;
}
