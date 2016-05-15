/*
	Author:			BASNILLO, Miles Lawrence R.
					JARO, Jeriel G.

	Filename: 		8puzzle_constants.h
	Description:	This library contains the functions for the mechanics of an 8 Puzzle.
*/

//Libraries needed
#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"
#include "8puzzle_constants.h"

void 	RandomizeBoard(int board[ROW][COL]);
void	MovePiece(char d, int board[ROW][COL]);
void	NewGame(int board[ROW][COL]);
int 	CheckBoard(int board[ROW][COL]);
int		CheckWin(int board[ROW][COL]);

void RandomizeBoard(int board[ROW][COL]){
	int i, 
		*p = (int *)(board[0]), 
		checkboard[DIM] = {0};
	srand(time(NULL));
	for(i=0;i<9;i++){
		do{
			if(!checkboard[*(p+i) = rand()%(DIM)]){
				checkboard[*(p+i)] = 1;
				break;
			}
		}
		while(1);
	}
}

void MovePiece(char d, int board[ROW][COL]){
	int i, j;
	for(i = 0;i<ROW;i++){
		for(j = 0;j<COL;j++){
			if(!(board[i][j])) break;
		}
	}

	switch(d){
		case UP:	if(!i){
					board[i][j] = board[i-1][j];
					board[i-1][j] = 0;
					break;
				}	
		case UP2:	if(!i){
					board[i][j] = board[i-1][j];
					board[i-1][j] = 0;
					break;
				}
		case DOWN:	if(i<ROW-1){
					board[i][j] = board[i+1][j];
					board[i+1][j] = 0;
					break;
				}
		case DOWN2:	if(i<ROW-1){
					board[i][j] = board[i+1][j];
					board[i+1][j] = 0;
					break;
				}
		case LEFT:	if(!j){
					board[i][j] = board[i][j-1];
					board[i][j-1] = 0;
					break;
				}
		case LEFT2:	if(!j){
					board[i][j] = board[i][j-1];
					board[i][j-1] = 0;
					break;
				}
		case RIGHT:	if(j<COL-1){
					board[i][j] = board[i][j+1];
					board[i][j+1] = 0;
					break;
				}	
		case RIGHT2:if(j<COL-1){
					board[i][j] = board[i][j+1];
					board[i][j+1] = 0;
					break;
				}		
	}
}

void NewGame(int board[ROW][COL]){
	do{
		RandomizeBoard(board);
	}while(!CheckBoard);
}

int CheckBoard(int board[ROW][COL]){
	int i,j,
		inversions=0,
		*p = (int *)(board[0]);
	for(i=0;i<DIM-1;i++){
		if(!(*(p+i)) && i++) continue;
		for(j=i+1;j<DIM;j++){
			if((*(p+j)) && (*(p+i) > *(p+j))){
				inversions++;
			}
		}
	}
	switch(inversions%2){
		case 0: return 1;
		case 1: return 0;
		default: return -1;
	}
}

int CheckWin(int board[ROW][COL]){
	int i, *p = (int *)(board[0]);
	for(i=0;i<DIM-2;i++){
		if(*(p+i) > *(p+i+1)) return 0;
	}
	return 1;
}
