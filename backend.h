#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int Randomize(int board[9]);
int PrintBoard(int board[9]);
int CheckBoard(int board[9]);
int SaveBoard(int board[9]);
int LoadBoard(int board[9]);

/*
	TO DO:
	Limit the infinite loop of randomiation.
*/
int Randomize(int *board){
	int i, j=sizeof(board)/sizeof(board[0]);
	int boardCheck[j] = {0};
	for(i=0;i<j;i++){
		while(1){
			srand(clock());
			board[i] = rand()%j+1;
			if(!boardCheck[board[i]]){
				boardCheck[board[i]] = 1;
				break;
			}	
		}
	}
	return 1;
}

int PrintBoard(int *board){
	int i, j= sizeof(board)/sizeof(board[0]);
	for(i=1;i<j+1;i++){
		printf("%d ", board[i-1]);
		if(!(i%sqrt(j))){
			printf("\n");
		}
	}
	return 1;
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


/*
	TO DO:
	Make the textfile user defined instead of
	fixed.
*/
int SaveBoard(int board[9]){
	FILE * fp = fopen("saveFile.txt", "w");
	int i;
	for(i=0;i<9;i++){
		fprintf(fp, "%d ", board[i]);
	}
	fclose(fp);
	return 1;
}

/*
	TO DO:
	Make the textfile user defined instead of 
	fixed.
*/
int LoadBoard(int board[9]){
	FILE * fp = fopen("saveFile.txt", "r");
	int i=0;
	while(fscanf(fp, "%d ", &(board[i++])) != EOF){};
	fclose(fp);
	return 1;
}
