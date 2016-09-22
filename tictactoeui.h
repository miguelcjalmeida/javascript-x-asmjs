#ifndef TICTACTOEUI_H_INCLUDED
#define TICTACTOEUI_H_INCLUDED

#include "tictactoegame.h"

int getPlayerMove(struct game* game);
void printGame(struct game* game, int score);
void keepPlayingUntilEndOfGame(struct game** game, int depth);
void showResults(struct game* game);
void playCpuVsCpu(struct game** game, int depth);

#endif
