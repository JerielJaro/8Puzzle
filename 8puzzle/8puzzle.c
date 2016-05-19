/*
	Authors:
		BASNILLO, Miles Lawrence R., 2013-12868
		JARO, Jeriel., 2013-_____

	CMSC 125 Project: 8-Puzzle Game

	** Please refer to README.md regarding editing, installing and running the program.
*/	

#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

//Macros used as dimensions of the 8 Puzzle board
#define ROW 3
#define COL 3
#define DIM ROW*COL

//Keys used in in-game proper of the 8 Puzzle
#define UP 'w'
#define UP2 (char)151
#define DOWN 's'
#define DOWN2 (char)152
#define LEFT 'a'
#define LEFT2 (char)150
#define RIGHT 'd'
#define RIGHT2 (char)153
#define QUIT 'q'
#define START 'e'
#define YES 'y'
#define NO 'n'
#define ENTER '\n'
#define SPACE ' '

int board[ROW][COL];

void 	Erase();
void 	EraseAll();
void 	PrintBorder(); 
void 	PrintMenu();
void 	PrintArrow(int x, int y);	
void 	PrintInstructions(int x, int y);
void	NewGame(int board[ROW][COL]);
void 	PrintBoard(int x, int y);	
void 	ShowHint();
//void	MovePiece(char d, int board[ROW][COL]);
void 	MovePiece(char d);
void 	RandomizeBoard(int board[ROW][COL]);
int 	CheckBoard(int board[ROW][COL]);
int		CheckWin(int board[ROW][COL]);

void main(int argc, char *argv[]){
	char keypress = START;
	int ch=0;
	int moves=0;
	char mc[10];

	set_graphics(VGA_320X200X256);

	PrintArrow(80, 105);

	do{	//Game loop
		PrintBorder();
		PrintMenu();
		keypress = (char)getch();

		if(keypress == QUIT){
			keypress = START;					//special condition so that it will not exit on Q press at menu
		}else if(keypress == UP || keypress == UP2){
			Erase(80, 120, 15, 15);
			PrintArrow(80, 105);
			ch = 0;
		}else if(keypress == DOWN || keypress == DOWN2){
			Erase(80, 100, 15, 15);
			PrintArrow(80, 125);
			ch = 1;
		}else if(keypress == ENTER || keypress == SPACE){
			switch(ch){
				case 0:
						EraseAll();
						NewGame(board);
						do{	//Inside-the-game loop
							PrintInstructions(180, 30);
							PrintBoard(30, 30);										//* Always prints update version of board at coordinates
							PrintBorder();														//* Always prints border
							sprintf(mc, "%d", moves);
							Erase(55, 175, 150, 15);
							write_text("Moves: ", 55, 175, WHITE, 0);
							write_text(mc, 120, 175, WHITE, 0);
							ShowHint();

							keypress=(char)getch();

							if(keypress == UP || keypress == UP2){
								//Erase(15, 15, 150, 150);
								MovePiece(keypress);
								moves++;
							}else if(keypress == LEFT || keypress == LEFT2){
								//Erase(15, 15, 150, 150);
								MovePiece(keypress);
								moves++;
							}else if(keypress == RIGHT || keypress == RIGHT2){
								//Erase(15, 15, 150, 150);
								MovePiece(keypress);
								moves++;
							}else if(keypress == DOWN || keypress == DOWN2){
								//Erase(15, 15, 150, 150);
								MovePiece(keypress);
								moves++;
							}else if(keypress == QUIT){
								Erase(55, 175, 150, 15);
								write_text("Really exit? Y/N", 55, 175, WHITE, 0);
								do{
									keypress=(char)getch();
									if(keypress == YES){
										moves = 0;
										keypress = QUIT;
										break;
									}else if(keypress == NO){
										keypress = YES;
										Erase(55, 175, 150, 15);
										break;
									}
								}while(1);
							}else{
								Erase(55, 175, 150, 15);
								write_text("Invalid button!", 55, 175, WHITE, 0);
							}
							if(CheckWin(board)){
								EraseAll();
								write_text("You win!", 125, 85, WHITE, 0);
								moves = 0;
								keypress = QUIT;
							}
						}while(keypress != QUIT);
						EraseAll();
						PrintArrow(80, 105);
						keypress = START;
						break;
				case 1: keypress = QUIT;
						break;
				default: break;
			}
		}
		
	}while(keypress != QUIT);
	
	set_graphics(VGA_TEXT80X25X16);
	clrscr();
}

void Erase(int x, int y, int w, int h){ //basically covers an area with a black rectangle 
   int i,j;
   for (i=y;i<=(y+h);i++)
      for (j=x;j<=(x+w);j++)
         write_pixel(j,i,100);
}

void EraseAll(){
	int i, j;
	for(i=1;i<320;i++){
		for(j=1;j<200;j++){
			write_pixel(i,j,100);
		}
	}
}

void PrintBorder(){
	int i, x1=5, y1=5, x2=315, y2=195, color1, color2;
	color1 = GREEN;
	color2 = RED;

	for(i=5;i<315;i++) write_pixel(i, y1, color1);	//TOP
	for(i=5;i<315;i++) write_pixel(i, y1+2, color2);	//TOP
	for(i=5;i<315;i++) write_pixel(i, y2, color1);	//BOTTOM
	for(i=5;i<315;i++) write_pixel(i, y2+2, color2);	//BOTTOM
	for(i=5;i<195;i++) write_pixel(x1, i, color2);	//LEFT
	for(i=5;i<195;i++) write_pixel(x1+2, i, color1);	//LEFT
	for(i=5;i<195;i++) write_pixel(x2, i, color2);	//RIGHT
	for(i=5;i<195;i++) write_pixel(x2+2, i, color1);	//RIGHT
}

void PrintMenu(){
	int i, y=55, color;
	color = RED;

	write_text("8-", 20, 20, GREEN, 1);
	write_text("Puzzle", 40, 20, RED, 1);
	write_text("A game by CMSC 125 Students", 55, 35, WHITE, 0);
	for(i=15;i<305;i++) write_pixel(i, y, color);
	write_text("Start Game", 100, 100, WHITE, 1);
	write_text("Quit", 100, 120, WHITE, 1);

	write_text("ICS-OS", 250, 160, WHITE, 1);
}

void PrintArrow(int x, int y){
	write_text(">>", x, y, WHITE, 0);
}

void PrintInstructions(int x, int y){
	write_text("8-Puzzle Game", x, y, GREEN, 0);
	write_text("Instructions: ", x, y+20, RED, 0);
	write_text("W - Move Up", x, y+40, WHITE, 0);
	write_text("S - Move Down", x, y+50, WHITE, 0);
	write_text("A - Move Left", x, y+60, WHITE, 0);
	write_text("D - Move Right", x, y+70, WHITE, 0);
	write_text("Q - Exit", x, y+80, WHITE, 0);
}

void ShowHint(){
	Erase(160, 140, 145, 45);
	srand(time());
	int i;
	i = rand()%4;
	switch(i){
		case 0:	
				write_text("HINT!", 160, 140, WHITE, 0);
				write_text("Press up", 170, 160, WHITE, 0);
				write_text("to move up!", 175, 175, WHITE, 0);
				break;
		case 1:
				write_text("HINT!", 160, 140, WHITE, 0);
				write_text("Press down", 170, 160, WHITE, 0);
				write_text("to move down!", 175, 175, WHITE, 0);
				break;
		case 2:
				write_text("HINT!", 160, 140, WHITE, 0);
				write_text("Press left", 170, 160, WHITE, 0);
				write_text("to move left!", 175, 175, WHITE, 0);
				break;
		case 3:
				write_text("HINT!", 160, 140, WHITE, 0);
				write_text("Press right", 170, 160, WHITE, 0);
				write_text("to move right!", 175, 175, WHITE, 0);
				break;
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

void PrintBoard(int x, int y){
	int i, j, k, l;
	k = x;
	l = y;

	char str[10];
	for(i=0; i<ROW; i++, l+=30){
		for(j=0; j<COL; j++, k+=45){
			if(board[i][j] == 0){
				write_text(" ", k, l, WHITE, 0);
			}else{
				sprintf(str, "%d", board[i][j]);
				write_text(str, k, l, WHITE, 0);
			}
		}
		k = x;
	}

	for(i=20;i<140;i++){
		write_pixel(i, 20, WHITE);
		write_pixel(i, 50, WHITE);
		write_pixel(i, 80, WHITE);
		write_pixel(i, 110, WHITE);
	}

	for(i=20;i<110;i++){
		write_pixel(20, i, WHITE);
		write_pixel(60, i, WHITE);	
		write_pixel(100, i, WHITE);
		write_pixel(140, i, WHITE);
	}
}

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

void MovePiece(char d){
	int i, j, x, y, temp;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j] == 0){
				x = i;
				y = j;
				break;
			}
		}
	}
	if((x < ROW-1) && (d == UP || d == UP2)){
		Erase(15,15,150,150);	
		board[x][y] = board[x+1][y];
		board[x+1][y] = 0;
	}
	if(x && (d == DOWN || d == DOWN2)){
		Erase(15,15,150,150);
		board[x][y] = board[x-1][y];
		board[x-1][y] = 0;
	}
	if(y && (d == RIGHT || d == RIGHT2)){
		Erase(15,15,150,150);
		board[x][y] = board[x][y-1];
		board[x][y-1] = 0;
	}
	if((y < COL-1) && (d == LEFT || d == LEFT2)){
		Erase(15,15,150,150);
		board[x][y] = board[x][y+1];
		board[x][y+1] = 0;
	}
}

int CheckWin(int board[ROW][COL]){
	int i, *p = (int *)(board[0]);
	for(i=0;i<DIM-2;i++){
		if(*(p+i) > *(p+i+1)) return 0;
	}
	return 1;
}