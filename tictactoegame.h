#ifndef TICTACTOEGAME_H_INCLUDED
#define TICTACTOEGAME_H_INCLUDED

#define PLAYER_NONE 0
#define PLAYER_1 	-1
#define PLAYER_2 	1
#define TRUE 		1

struct game {
	int** board;
	int size;
	int movesMade;
	int currentPlayer;
};


struct game* initGame(int size); 
void resetGame(struct game* game);
void makeOneMove(struct game* game, int row, int col);
int getEnemy(int player);
int isGameOver(struct game* game);
int getWinner(struct game* game);
struct game* cloneGame(struct game* game);
#endif