/*
	Authors:
		BASNILLO, Miles Lawrence R., 2013-12868
		JARO, Jeriel., 

	CMSC 125 Project: 8-Puzzle Game

	** Please refer to README.md regarding editing, installing and running the program.
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
void erase();
//void SaveBoard(int board[9]);
//void LoadBoard(int board[9]);

#define up 'w'
#define down 's'
#define left 'a'
#define right 'd'
#define quit 'q'
#define start 'e'

void main(int argc, char *argv[]){
	/*
	int board[9] = {0};
	while(1){
		Randomize(board);
		PrintBoard(board);
		int x = CheckBoard(board);
		printf("Inversions: %d\n", x);
		if(x%2==0){break;}
	}
	//SaveBoard(board);
	*/
	char keypress = start;

	set_graphics(VGA_320X200X256);
	write_text("Hello, World!", 69, 69, WHITE, 0);

	do{
		keypress=(char)getch();
		if(keypress == up){
			erase(69, 69, 300, 300);
			write_text("I pressed UP!", 69, 69, WHITE, 0);
		}else if(keypress == left){
			erase(69, 69, 300, 300);
			write_text("I pressed LEFT!", 69, 69, WHITE, 0);
		}else if(keypress == right){
			erase(69, 69, 300, 300);
			write_text("I pressed RIGHT!", 69, 69, WHITE, 0);
		}else if(keypress == down){
			erase(69, 69, 300, 300);
			write_text("I pressed DOWN!", 69, 69, WHITE, 0);
		}
	}while(keypress != quit);

	set_graphics(VGA_TEXT80X25X16);
	clrscr();
}

/*
	Function from the lights out example
*/
void erase(int x, int y, int w, int h){ //basically covers an area with a black rectangle 
   int i,j;
   for (i=y;i<=(y+h);i++)
      for (j=x;j<=(x+w);j++)
         write_pixel(j,i,100);
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