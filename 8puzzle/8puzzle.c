/*
	Authors:
		BASNILLO, Miles Lawrence R., 2013-12868
		JARO, Jeriel., 

	CMSC 125 Project: 8-Puzzle Game

*/	

/* NOTE: Use ../sdk/ when running from ics-os, use <stdio.h> when running from terminal */
//#include "../../sdk/dexsdk.h"
//#include "../../sdk/time.h"
#include <stdio.h>
#include <time.h>

void Randomize(int board[9]);
void PrintBoard(int board[9]);
int CheckBoard(int board[9]);
void NewGame(int board[9]);
//void SaveBoard(int board[9]);
//void LoadBoard(int board[9]);

#define up 'w'
#define down 's'
#define left 'a'
#define right 'd'

void main(int argc, char *argv[]){
	int board[9] = {0};
	while(1){
		Randomize(board);
		PrintBoard(board);
		int x = CheckBoard(board);
		printf("Inversions: %d\n", x);
		if(x%2==0){break;}
	}
	SaveBoard(board);
}

void Randomize(int board[9]){
	int i,j;
	int boardCheck[9] = {0};
	for(i=0;i<9;i++){
		while(1){
			srand(clock());
			board[i] = rand()%9;
			if(boardCheck[board[i]] == 0){
				boardCheck[board[i]] = 1;
				break;
			}	
		}
	}
}

void PrintBoard(int board[9]){
	int i, j;

	for(i=1;i<10;i++){
		printf("%d ", board[i-1]);
		if(!(i%3)){
			printf("\n");
		}
	}
}

int CheckBoard(int board[9]){
	int i,j,inversions = 0;
	for(i=0;i<8;i++){
		for(j=i+1;j<9;j++){
			if(board[i] > board[j]){
				inversions++;
			}
		}
	}
	return inversions;
}

void NewGame(int board[9]){
	Randomize(board);
	if(CheckBoard(board)%2 == 0){
	}
}

/*
void SaveBoard(int board[9]){
	FILE * fp = fopen("saveFile.txt", "w");
	int i;
	for(i=0;i<9;i++){
		fprintf(fp, "%d ", board[i]);
	}
	fclose(fp);
}

void LoadBoard(int board[9]){
	FILE * fp = fopen("saveFile.txt", "r");
	int i=0;
	while(fscanf(fp, "%d ", &(board[i++])) != EOF){};
	fclose(fp);
}
*/