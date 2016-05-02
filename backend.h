#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Randomize(int board[9]);
void PrintBoard(int board[9]);
int CheckBoard(int board[9]);
void NewGame(int board[9]);
void SaveBoard(int board[9]);
void LoadBoard(int board[9]);

void Randomize(int board[9]){
	int i,j;
	int boardCheck[9] = {0};
	PrintBoard(boardCheck);
	for(i=0;i<9;i++){
		while(1){
			srand(clock());
			board[i] = rand()%9+1;
			if(!boardCheck[board[i]]){
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
