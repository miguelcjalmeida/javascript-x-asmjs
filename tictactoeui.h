#ifndef TICTACTOEUI_H_INCLUDED
#define TICTACTOEUI_H_INCLUDED

#include "tictactoegame.h"

int getPlayerMove(struct game* game);
void printGame(struct game* game);
void keepPlayingUntilEndOfTurn(struct game* game);

#endif
